#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10,11); // CONNECT BT RX PIN TO ARDUINO 11 PIN | CONNECT BT TX PIN TO ARDUINO 10 PIN

void setup()
{

 Serial.begin(9600);
  Serial.println("BLE TESTING");
  Serial.println("Enter AT commands or message:");
  BTSerial.begin(9600); 
}

void loop()
{

 //Read Bluetooth Serial and displays it on the Serial
 if (BTSerial.available())
  {
    while (BTSerial.available())
    {
       Serial.write(BTSerial.read());
       delay(5); //Delay to retrieve the entire message
    }
    Serial.println();
  
    
 }
  //Read Serial and send it to the Bluetooth Serial
  if (Serial.available())
    BTSerial.write(Serial.read());

}
