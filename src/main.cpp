#include <Arduino.h>
#include <BluetoothSerial.h>
#include  <Siren.h>
#include <doraemon.h>
#include <noomalee.h>
#include <playmelody.h>
#include <happybirthday.h>
BluetoothSerial SerialBT;

#define BUZZER_PIN 26 

void setup() {
  Serial.begin(9600);
  SerialBT.begin("002-Supawit");
  Serial.println("Bluetooth ACTIVE");
  pinMode(BUZZER_PIN, OUTPUT);
}



void loop() {
   if (SerialBT.available()){
      char incoming = SerialBT.read();
      Serial.print("Received: ");
      Serial.println(incoming);
      

      if(incoming == '1')
      {
        SerialBT.println("เปิดเสียงไซเรน");
        playSiren(BUZZER_PIN, SerialBT);
      }
      else if(incoming == '2')
      {
        SerialBT.println("เพลงโดเรม่อน"); 
        Doraemonsong(BUZZER_PIN, SerialBT);
      }
      else if(incoming == '3')
      {
        SerialBT.println("เพลงหนูมาลี");
        playMelody(melodyNooMalee,noteDurationsNooMalee,melodyLengthNooMalee,BUZZER_PIN, SerialBT);
      }
      else if(incoming == '4')
      {
        SerialBT.println("สุขสันต์วันเกิด");
        playMelody(melodyHappybirthday,noteHappybirthday,melodyLengthHappybirthday,BUZZER_PIN, SerialBT);
      }
   }
}

