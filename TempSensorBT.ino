// TempSensor Sketch to take the rooms temperature and transmit over a bluetooth connection
// Used https://learn.adafruit.com/tmp36-temperature-sensor/using-a-temp-sensor as a guide
//
// uses the TMP36 temp sensor which came in the starter set
// -- this sensor has a resolution of 10mV/ degree centigrade
// -- a 500mV offset to deal with negative temps
// uses the 3.3v output from the board as a power supply and a reference for the sensor (increased accuracy)
//
// Also uses the DHT22 sensor to sense humidity and temperature, turns out to be more accurate as well. used the
// example included with the DHT library from adafruit industries.
//
// ------------------------------ Comments ----------------------------------------------------------------------
// 1. Read serial and print to text file is still needed (Doug)
//    -- Maybe python? stackoverflow.com/questions/20892133/storing-string-from-arduino-to-text-file-using-python (Doug)
// 2. I think my temp sensor is bad beacuse the temp doesn't seem quite right (Doug)
//     -- will need to test sensor or get a better one (Doug)
//------------------------------- ChangeLog ---------------------------------------------------------------------
// July 28 2016 21:20   (Doug)   Created .ino file and did some minor testing, see comment section
// August 14 2016 16:00 (Doug)   Changed the output to serial bits to allow for the python program ReadSerial.py to write 
//                               the data to a text file. Also adjusted the delay on the write portion to 1 second, 100 \
//                               micro seconds.
// August 21 2016 13:00 (Doug)   Added in the option to use the DHT22 sensor which senses temperature and humidity. Changed
//                               the serial output format to better display the data. Added code to write to bluetooth serial
//                               connection.

// Variables to be used in this code
  //---------------------- Global --------------------------
    #include <SoftwareSerial.h> // Tells the script to use the Software Serial library to set different pins as the TX and RX
    SoftwareSerial BTSerial(10, 11); // RX | TX
    
  // --------------------- TMP36 ---------------------------
//  #define aref 3.3  // Sets the reference as 3.3
//  int TempSensorIn = 0; // TMP36's (temp sensor) output pin 
  

  // --------------------- DHT22 ---------------------------
  #include <DHT.h>         // Tells the script to use the DHT library
  #define DHTPin 2         // Digital pin in which the DHT22 sensor output is hooked to
  #define DHTType DHT22    // Stores the type of DHT sensor being used (22 or 11)
  DHT dht(DHTPin, DHTType); // Passes the required information to the library
  float TempRead;          // Temperature reading from the sensor
  float HumRead;           // Humidity reading from the sensor
  
  
void setup() {  
  
  //---------------------- Global ---------------------------
  // Setup the serial connection Buad rate
    Serial.begin(9600); // 9600 bits per second
    BTSerial.begin(38400);  // HC-05 default speed in AT command more
    
  // --------------------- TMP36 ---------------------------
  // Setting the aref to use a source that isnt the 5v
//    analogReference(EXTERNAL);

  // --------------------- DHT22 ---------------------------
  // Begin reading from the sensor
    dht.begin();
    
             }

void loop() {
  
  // --------------------- TMP36 ---------------------------
//  // Reading the value off of the temp sensor
//    float SensorValue = analogRead(TempSensorIn);
//    
//  // Converting from the sensor reading to approximate voltage
//    float Voltage = SensorValue * aref;
//    Voltage /= 1024.0; // uses the reference voltage
//    
//  // Converting this voltage into quatifiable units
//    float TempCelsius = (Voltage-0.5)*100; // Metric standard
//    float TempFahrenheit = (TempCelsius*(9/5))+32; //Imperial standard
//   
//  // Printing the voltage of the sensor and the quantifiable units, based off of the voltage
//    Serial.write('\n');
//    Serial.print(TempFahrenheit);

//    BTSerial.write('\n');
//    BTSerial.print(TempFahrenheit);
    
  // --------------------- DHT22 ---------------------------
  // Read the sensor values 
    TempRead = dht.readTemperature(true); // Read in as Fahrenheit
    HumRead = dht.readHumidity();         // Read in as Percentage

  // Print the values 
    Serial.write('\n');
    Serial.print(TempRead);
    Serial.print(",");
    Serial.print(HumRead);

    BTSerial.write('\n');
    BTSerial.print(TempRead);
    BTSerial.print(",");
    BTSerial.print(HumRead);

  //---------------------- Global ---------------------------
    delay(1000);
            }
            


