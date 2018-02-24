# bluefox

- Install Arduino ESP32 support on Windows, instructions here https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/windows.md

- Next we Install the bluefox libraries setup the development enviornment and load our first sketch.

1. Navigate to https://github.com/NetSensors/bluefox 
2. Click on the green clone or download button
3. Click on the blue download ZIP bitton and choose a location to save the zip file in. We will need this file in the next step.

![Screenshot](screenshots/bf001.png)

1. Open the arduino IDE application, if you have not installed this yet install it now using instructions here https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/windows.md

Click on Sketch -> Include Library -> Add ZIP library 

![Screenshot](screenshots/bf002.png)

1. Browse to and select the zip file we downloaded in the previous step

![Screenshot](screenshots/bf003.png)

Click on Edit -> Examples -> Bluefox -> simple_message this opens an example sketch

![Screenshot](screenshots/bf004.png)

We now need to connect our development kit to the computer so we can download the sketch (firmware) to the development kit. The image below shows how this should be done. Ensure you get the USB to serial adapter the correct way round.

![Screenshot](screenshots/bluefox-connect.png)


![Screenshot](screenshots/bf005.png)



![Screenshot](screenshots/bf006.png)



![Screenshot](screenshots/bf007.png)



![Screenshot](screenshots/bf008.png)



![Screenshot](screenshots/bf009.png)
