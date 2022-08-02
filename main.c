#include <wiringPi.h>
#include <lcd.h>
#include <stdio.h>

char *strings[] = {"hello world", "hello mars"};

void lcd_draw(int lcdHandle,  char* text){
        lcdClear(lcdHandle);
        lcdPuts(lcdHandle, text);
        delay(500);
        lcdClear(lcdHandle);
        delay(100);
}

int main(void){
        int lcd;
        wiringPiSetup();
        //pins
        lcd = lcdInit (2, 16, 4,  11,10 , 0,1,2,3,0,0,0,0) ;
        int i=0;
        while(strings[i]){
                lcd_draw(lcd, strings[i]);
                i++;
        }
}
