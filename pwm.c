#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLUE 7

#define MAX_VALUE 100
#define MIN_VALUE 0

int main(void){
        wiringPiSetup();
        pinMode(RED,OUTPUT);
        pinMode(BLUE,OUTPUT);
        digitalWrite(RED,0);
        digitalWrite(BLUE,0);
        softPwmCreate(RED,0,100);
        softPwmCreate(BLUE,0,100);
        int speed=0;
        int led=0;
        int led_switch=0;
        int blue=MAX_VALUE;
        int red=MIN_VALUE;
        for(;;){
                //printf("switch state: %i\n",led_switch);
                if(led >= MIN_VALUE && led < MAX_VALUE && led_switch==0){
                        led++;
                        red++;
                        blue--;
                }else{
                        led_switch=1;
                }
                if(led > MIN_VALUE && led_switch==1){
                        led--;
                        red--;
                        blue++;
                }else{
                        led_switch=0;
                }
                softPwmWrite(RED,red);
                softPwmWrite(BLUE,blue);
                //printf("%i|%i",red,blue);
                delay(speed);
                //system("@cls||clear");
        }
        digitalWrite(RED,0);
        digitalWrite(BLUE,0);
        //delay(500);
        return 0;
}
