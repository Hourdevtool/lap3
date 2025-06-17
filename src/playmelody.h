#include <pitches.h>
#include <closesound.h>

void playMelody(int melody[], int noteDurations[], int length, int pin, BluetoothSerial &bt)
{
    

    while (true)
    {
        if (shouldStop(bt))
        {
            noTone(pin);
            return;
        }

        for (int i = 0; i < length; i++)
        {
            if (shouldStop(bt))
            {
                noTone(pin);
                return;
            }

            int noteDuration = 1000 / noteDurations[i];
            tone(pin, melody[i], noteDuration * 0.9);

            unsigned long start = millis();
            while (millis() - start < noteDuration)
            {
                if (shouldStop(bt))
                {
                    noTone(pin);
                    return;
                }
                delay(5);
            }

            noTone(pin);
        }
    }
}
