#include <SoftwareSerial.h>
#include <SerialRadioFrequency.h>
#include <SerialRadioFrequencyAPC220.h>
#include <RemoteCarControl.h>
#include <RemoteCarRadioControl.h>

SerialRadioFrequencyAPC220 serial(2, 3, 4, 5);
RemoteCarRadioControl remoteCarRadioControl(&serial, 9, 6, 10, 11);

void setup() {

  Serial.begin(9600);

  //Serial.println("Are you sure to continue? (y/n)");
  //while (!Serial.available());
  //while (Serial.read() != 'y');
  
  serial.begin(9600);
  serial.readParameters();

  Serial.print("getFrequency: ");
  Serial.println(serial.getFrequency());
  Serial.print("getAirRate: ");
  Serial.println((char)serial.getAirRate());
  Serial.print("getPower: ");
  Serial.println((char)serial.getPower());
  Serial.print("getUartRate: ");
  Serial.println((char)serial.getUartRate());
  Serial.print("getSeriesCheckout: ");
  Serial.println((char)serial.getSeriesCheckout());
}

void loop() {
  remoteCarRadioControl.loop();
}
