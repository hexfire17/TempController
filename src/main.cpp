#include <Arduino.h>
#include <Logger.h>
#include <MultiLedSegmentDisplay.h>
#include <DigitalPort.h>
#include <RunningAverage.h>

// START CONFIG
char *version = "2.4";
// ##############################################

int degreePrecision = 1;

int updateDelay = 5000;

int tempAnalogPort = 5;

MultiLedSegmentDisplay ledDisplay = MultiLedSegmentDisplay(
  5, 4, 3, 2,
  13, 12, 11, 10, 9, 8, 7, 6);

int meterAnalogPort = 0;
// ##############################################
// END CONFIG

// GLOBALS
enum Mode {DISPLAYING, SETTING};
double currTemp = 99.9;
unsigned long prevTime = 0;
unsigned long currTime = 0;
unsigned long deltaTime = 0;
Mode currMode = DISPLAYING;
RunningAverage runningAvgTemp = RunningAverage(10);
RunningAverage runningAvgPot = RunningAverage(5);

// TEMP SETTER VARS
double setTemp = 99.9;
int tempSetterTimeoutMs = 2500;
int tempSetterUnactiveMs = 0;
int tempSetterFlashOnTimeMs = 200;
int tempSetterCurrFlashOnTimeMs = 0;
int tempSetterCurrChar = 11;

// RELAY SETTINGS
DigitalPort fridge(0);

//Logger logger;

void setup()
{
  //logger.init();
  ledDisplay.setDecimal(1, 0);
  fridge.on();
}

// perform the fancy math of the Steinhart-Hart equation
double analogToF(int RawADC)
{
 double Temp;
 Temp = log(((10240000/RawADC) - 10000));
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;              // Convert Kelvin to Celsius
 Temp = (Temp * 9.0)/ 5.0 + 32.0; // Celsius to Fahrenheit - comment out this line if you need Celsius

 return Temp;
}

void setLed(double temp, int endLetter)
{
  // janky AF - janks yo
  int intF = temp;
  int precisionDigit = (temp - intF) * 10;

  int tensDigit = temp / 10;
  int onesDigit = temp - tensDigit * 10;

  ledDisplay.displayDigit(0, tensDigit);
  ledDisplay.displayDigit(1, onesDigit);
  ledDisplay.displayDigit(2, precisionDigit);
  ledDisplay.displayDigit(3, endLetter); // hack for F
}

double readKnobTemp()
{
  int knobTemp = map(analogRead(meterAnalogPort), 0, 1023, 0, 99);
  runningAvgPot.insert(knobTemp);
  return (int) runningAvgPot.getAverage();
}

double getTemp()
{
  int analogTemp = analogRead(tempAnalogPort);
  double f = analogToF(analogTemp);
  runningAvgTemp.insert(f);

  return runningAvgTemp.getAverage();
}

void runTempDisplayer()
{
  if (deltaTime >= updateDelay)
  {
    deltaTime = 0;
    currTemp = getTemp();
   }

   setLed(currTemp, 10);
}

void runTempSetter()
{
  double currKnobTemp = readKnobTemp();
  if (currKnobTemp == setTemp)
  {
    tempSetterUnactiveMs += deltaTime;
  }
  else
  {
    setTemp = currKnobTemp;
    tempSetterUnactiveMs = 0;
  }

  // flip flop flashing
  tempSetterCurrFlashOnTimeMs += deltaTime;
  if (tempSetterCurrFlashOnTimeMs >= tempSetterFlashOnTimeMs)
  {
    tempSetterCurrFlashOnTimeMs = 0;
    if (tempSetterCurrChar == 10)
    {
      tempSetterCurrChar = 11;
    }
    else
    {
      tempSetterCurrChar = 10;
    }
  }

  setLed(setTemp, tempSetterCurrChar);

  if (deltaTime > 0)
    deltaTime = 0;
}

void controlFridge(double currTemp, double desiredTemp)
{
  if (currMode != SETTING)
  {
    if (currTemp <= desiredTemp + degreePrecision)
        fridge.on();
    else
        fridge.off();
  }
}

void loop()
{
  // DELTA TIME
  prevTime = currTime;
  currTime = millis();
  deltaTime += currTime - prevTime;

  // MODE DECIDER

  // swith to setting when knob is moved
  if (currMode == DISPLAYING && abs(setTemp - readKnobTemp()) >= 1)
  {
    currMode = SETTING;
  }

  // swith to temp when setting unactive
  if (currMode == SETTING && tempSetterUnactiveMs > tempSetterTimeoutMs)
  {
    tempSetterUnactiveMs = 0;
    runningAvgPot.clear();
    currMode = DISPLAYING;
  }

  // MODE ROUTER
  if (currMode == DISPLAYING)
  {
    runTempDisplayer();
  }
  else if (currMode == SETTING)
  {
    runTempSetter();
  }

  controlFridge(setTemp, currTemp);
}
