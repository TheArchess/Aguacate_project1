#include <Arduino.h>
#include "task1.h"


void task4(){
    enum class Task4States{
        INIT,
        WAIT_TO_TOGGLE_LED
    };
    static Task4States task4State = Task4States::INIT;
    static uint32_t lasTime;
    static constexpr uint32_t INTERVAL = 250;
    static constexpr uint8_t ledRed = 30;
    static bool ledStatus = false;

    switch(task4State){
        case Task4States::INIT:{
            pinMode(ledRed,OUTPUT);
            lasTime = millis();
            task4State = Task4States::WAIT_TO_TOGGLE_LED;
            break;
        }

        case Task4States::WAIT_TO_TOGGLE_LED:{
            // evento 1:
            uint32_t currentTime = millis();
            if( (currentTime - lasTime) >= INTERVAL ){
                lasTime = currentTime;
                digitalWrite(ledRed,ledStatus);
                ledStatus = !ledStatus;
            }
            break;
        }

        default:{
            break;
        }
    }

}