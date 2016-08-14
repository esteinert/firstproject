## ReadSerial Python script takes serial data produced by an arduino and writes to a text file.
##
##---------------------------------- Comments --------------------------------------------------
## -- (Doug) User needs to input the file path to the .txt file
## -- (Doug) User need to set how long the script will take in data (in seconds)
## -- (Doug) Pairs with the TempSensorBT.ino file
## -- (Doug) Needs to set new data in the file apart from the old data
##
## --------------------------------- ChangeLog -------------------------------------------------
## August 14 2016 16:00 (Doug) Created the .py file as well as tested to create some sample data
##                             also commented and added header to the code.

## User defined parameters

    FileLocal = 'C:/Users/Douglas/Dropbox/Projects/EricTempSensor/PythonRead/TempData.txt'
    ArduinoPort1 = "COM3"

## Import the serial library

    import serial

## Boolean variable that will represent whether or not the arduino is connected
    
    connected = False

## Establish connection to the serial port that the arduino is connected to. 

    locations=[ArduinoPort1] #allows for the user to add more than one location of the arduino

    for device in locations:
        try:
            print ("Trying...",device)
            SerialPort = serial.Serial(device)
            SerialPort.buadrate = 9600
            break
        except:
            print ("Failed to connect on",device)

## loop until the arduino tells us it is ready
        
    while not connected:
        SerialPortin = SerialPort.read()
        connected = True

## open text file to store the current
    
    WriteFile = open(FileLocal, 'a')    #opens the text file in append mode

## read serial data from arduino and write it to the text file 'TempData.txt'

    count = 0 #sets up the time counter
    while count < 100:
        if SerialPort.inWaiting(): #gets the number of bytes in the input buffer
            x = SerialPort.readline() #reads the entire line of data in the buffer
            X = x.decode("utf-8") #decodes from bytes to a string of data
            WriteFile.write(X) #writes the string of data
            count = count +1 #limits the time the script is running
            print(count)

## close the serial connection and text file
            
    WriteFile.close()
    SerialPort.close()
