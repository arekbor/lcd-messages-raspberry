#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TRIGGER 0
#define ECHO 2

int main(void){
        wiringPiSetup();
        long timeout = 500000;
        long ping = 0;
        long pong = 0;
        float distance = 0;

        pinMode(TRIGGER, OUTPUT);
        pinMode(ECHO, INPUT);

        digitalWrite(TRIGGER,LOW);
        delay(50);

        digitalWrite(TRIGGER,HIGH);
        delayMicroseconds(10);
        digitalWrite(TRIGGER,LOW);

        while(digitalRead(ECHO) == LOW && micros() < timeout){
        }
        if(micros() > timeout){
                printf("out of range\n");
                return 0;
        }

        ping = micros();

        while(digitalRead(ECHO) == HIGH && micros() < timeout){
        }

        if(micros() > timeout){
                printf("out of range\n");
                return 0;
        }
        pong = micros();

        distance = (float) (pong - ping) * 0.017150;

        printf("Distance: %.2f cm.\n", distance);
        return 0;
}

