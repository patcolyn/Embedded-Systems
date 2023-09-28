// You need this to use the Module Support Board
#include <vector>
#include "uop_msb.h"
using namespace uop_msb;

#define MS_TO_US_MULT 1000
#define WAIT_TIME_MS 500 
DigitalOut greenLED(TRAF_GRN1_PIN);
Buzzer buzz;
Buttons buttons;

// TIP: (I suggest you read this!)
//
// Press the black reset button to restart the code (and stop the sound)
// Otherwise, the noise can be "distracting" :)

void playNotes(std::vector<char> notes)
{
    for(const char t : notes)
    {
        greenLED = 1;
        buzz.playTone(&t);
        wait_us(250 * MS_TO_US_MULT);

        greenLED = 0;
        buzz.rest();
        wait_us(WAIT_TIME_MS * MS_TO_US_MULT);
    }
}


int main()
{
    //Wait for the BLUE button to be pressed (otherwise this becomes super annoying!)
    while (buttons.BlueButton == 0);
    
    //Repeat everything "forever" (until the power is removed or the chip is reset)
    while (true)
    {
        playNotes({'C','D','E','F','G','A','B','C'});
    }
}