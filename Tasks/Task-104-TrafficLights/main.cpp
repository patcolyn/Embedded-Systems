#include "uop_msb.h"
#include <chrono>
using namespace uop_msb;

#define WAIT_TIME_MS 500
#define S_TO_US_MULT 1000000

BusOut lightsBus(PC_2, PC_3, PC_6);
/*DigitalOut red(TRAF_RED1_PIN,0);         //Note the initial state
DigitalOut amber(TRAF_YEL1_PIN,0);
DigitalOut green(TRAF_GRN1_PIN,0);*/

//Object for controlling the LCD
LCD_16X2_DISPLAY lcd;

LowPowerTimer t;

int main()
{
    t.start();

    while(true)
    {
        /*
        red = 1;
        amber = 0;
        green = 0;*/
        lightsBus = 1; //001
        lcd.cls();
        lcd.puts("RED");
        while(t.elapsed_time() < 10s);
        //wait_us(10 * S_TO_US_MULT);

        /*red = 1;
        amber = 1;
        green = 0;*/
        lightsBus = 3; // 011
        lcd.cls();
        lcd.puts("RED + YELLOW");
        t.reset();
        while(t.elapsed_time() < 2s);
        //wait_us(2 * S_TO_US_MULT);

        /*red = 0;
        amber = 0;
        green = 1;*/
        lightsBus = 4; // 100
        lcd.cls();
        lcd.puts("GREEN");
        while(t.elapsed_time() < 10s);    
        //wait_us(10 * S_TO_US_MULT);

        /*red = 0;
        green = 0;*/
        lcd.cls();
        lcd.puts("YELLOW");
        for(int i = 0; i <= 3; ++i)
        {
            //amber = 1;
            lightsBus = 2; // 010
            t.reset();
            while(t.elapsed_time() < 0.25s);
            //wait_us(0.25f * S_TO_US_MULT);
            
            //amber = 0;
            lightsBus = 0; // 000
            while(t.elapsed_time() < 0.5s);
            //wait_us(0.25f * S_TO_US_MULT);
        }

    }

    /*while (true)
    {
        red = !red;
        amber = !amber;
        green = !green;
        wait_us(WAIT_TIME_MS * 1000);
    }*/
}
