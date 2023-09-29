#include "mbed.h"
#include <vector>
#include <math.h>

// Create a DigitalOut "object"
DigitalOut greenLED(LED1);
DigitalOut blueLED(LED2);
DigitalOut redLED(LED3);

// Microsecond multiplier
int MULT_US_SEC= pow(10, 6);

void rgbLED(vector<bool> rgb)
{
    redLED = rgb[0];
    greenLED = rgb[1];
    blueLED = rgb[2];
}

int main()
{
    while(true)
    {
        rgbLED({0, 0, 1});
        wait_us(MULT_US_SEC * 0.5);

        rgbLED({1, 1, 0});
        wait_us(MULT_US_SEC * 0.5);
    }
}
