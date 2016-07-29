// TempSensor Sketch to take the rooms temperature and transmit over a bluetooth connection
// Used https://learn.adafruit.com/tmp36-temperature-sensor/using-a-temp-sensor as a guide
// uses the TMP36 temp sensor which came in the starter set
// -- this sensor has a resolution of 10mV/ degree centigrade
// -- a 500mV offset to deal with negative temps
// uses the 3.3v output from the board as a power supply and a reference for the sensor (increased accuracy)
// ------------------------------ Comments ----------------------------------------------------------------------
// 1. Read serial and print to text file is still needed (Doug)
//    -- Maybe python? stackoverflow.com/questions/20892133/storing-string-from-arduino-to-text-file-using-python (Doug)
// 2. I think my temp sensor is bad beacuse the temp doesn't seem quite right (Doug)
//     -- will need to test sensor or get a better one (Doug)
//------------------------------- ChangeLog ---------------------------------------------------------------------
// July 28 2016 21:20 (Doug) Created .ino file and did some minor testing, see comment section

// Variables to be used in this code
  #define aref 3.3  // Sets the reference as 3.3
  int TempSensorIn = 0; // TMP36's (temp sensor) output pin 
  int TempReading; // analog reading from the sensor
  
void setup() {
  // Setup the serial connection Buad rate
    Serial.begin(9600); // 9600 bits per second
  
  // Setting the aref to use a source that isnt the 5v
    analogReference(EXTERNAL);
             }

void loop() {
  // Reading the value off of the temp sensor
    int SensorValue = analogRead(TempSensorIn);
    
  // Converting from the sensor reading to approximate voltage
    float Voltage = SensorValue * aref;
    Voltage /= 1024.0; // uses the reference voltage
    
  // Converting this voltage into quatifiable units
    float TempCelsius = (Voltage-0.5)*100; // Metric standard
    float TempFahrenheit = (TempCelsius*(9/5))+32; //Imperial standard
    float TempKelvin = TempCelsius + 273.15; // Metric engineering
    float TempRankine = TempFahrenheit + 459.67; // Imperial engineering
   
  // Printing the voltage of the sensor and the quantifiable units, based off of the voltage
    Serial.print("{");
    Serial.print(SensorValue);
    Serial.print("|");
    Serial.print(Voltage);
    Serial.print("|");
    Serial.print(TempCelsius);
    Serial.print("|");
    Serial.print(TempKelvin);
    Serial.print("|");
    Serial.print(TempFahrenheit);
    Serial.print("|");
    Serial.print(TempRankine);
    Serial.print("}");
    Serial.print("\n");
    delay(2000);
            }
            


