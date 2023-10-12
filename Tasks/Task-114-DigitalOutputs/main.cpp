#include "mbed.h"


BusOut lightsBus(PC_6, PC_3, PC_2);
LowPowerTimer t;

// main() runs in its own thread in the OS
int main()
{
    
    t.start();

    lightsBus = 0b111;
    while(t.elapsed_time() < 0.5s);
    t.reset();

    while (true) {
        //Red
        lightsBus = 0b100;
        while(t.elapsed_time() < 2s);
        t.reset();

        //Red+Yellow
        lightsBus = 0b110;
        while(t.elapsed_time() < 2s);
        t.reset();

        //Green
        lightsBus = 0b001;
        while(t.elapsed_time() < 2s);
        t.reset();

        //Flashing Yellow
        for(int i = 0; i < 4; ++i)
        {
            lightsBus = 0b010;
            while(t.elapsed_time() < 0.5s);
            t.reset();
            lightsBus = 0b000;
            while(t.elapsed_time() < 0.5s);
            t.reset();
        }
    }
}

