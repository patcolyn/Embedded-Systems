#include "uop_msb.h"
using namespace uop_msb;

Buzzer buzz;

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);


int main()
{
    printf("\nTASK-112\n");

    //getchar
    char c1, c2;
    printf("\n\nPress a key\n");
    c1 = getchar();
    printf("You entered character %c which has the ASCII code %d\n", c1, c1);

    printf("\n\nPress another key\n");
    c2 = getchar();
    printf("You entered character %c which has the ASCII code %d\n", c2, c2);

    //scanf
    printf("\n\nTo set the on delay (in ms), type in an integer number and press return\n");
    int delay_on_ms;
    int parsed = scanf("%d", &delay_on_ms);

    printf("\n\nTo set the off delay (in ms), type in an integer number and press return\n");
    int delay_off_ms;
    parsed = scanf("%d", &delay_off_ms);
    
    printf("You entered %d correct integer values. The values were %dms and %dms\n", parsed*2, delay_on_ms, delay_off_ms);

    // Stop
    while (parsed > 0) {
        wait_us(delay_off_ms * 1000);
        led1 = 1;
        led2 = 1;
        led3 = 1;
        wait_us(delay_on_ms * 1000);
        led1 = 0;
        led2 = 0;
        led3 = 0;        
    } 

    printf("Invalid - please restart and try again\n");
    while(1);    
}