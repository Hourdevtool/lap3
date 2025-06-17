#include <Arduino.h>
#include <closesound.h>
void playSiren(int BUZZER_PIN, BluetoothSerial &bt)
{
    while (true)
    {
        if (shouldStop(bt))
        {
            noTone(BUZZER_PIN);
            break;
        }

        tone(BUZZER_PIN, 1200);
        delay(400);
        tone(BUZZER_PIN, 600);
        delay(400);
    }
}
