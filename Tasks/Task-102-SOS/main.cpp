// You need this to use the Module Support Board
#include <vector>
#include <string>
#include "uop_msb.h"

#define MS_TO_US_MULT 1000
#define WAIT_TIME_MS 500 

DigitalOut greenLED(TRAF_GRN1_PIN);
uop_msb::Buzzer buzz;
uop_msb::Buttons buttons;

// TIP: (I suggest you read this!)
//
// Press the black reset button to restart the code (and stop the sound)
// Otherwise, the noise can be "distracting" :)

#define DOT_DELAY 150
#define DASH_DELAY 450
#define SYMBOL_SPACE 150
#define LETTER_SPACE 150*3
#define WORD_SPACE  150*6

void playMorse(std::vector<std::string> morse, char tone)
{
    for(const string letter : morse)
    {
        for(const char symbol : letter)
        {
            buzz.playTone(&tone);

            if (symbol == '.') { wait_us(DOT_DELAY * MS_TO_US_MULT);}
            else if (symbol == '-') { wait_us(DASH_DELAY * MS_TO_US_MULT);}

            buzz.rest();

            wait_us(SYMBOL_SPACE * MS_TO_US_MULT);
        }
        wait_us((LETTER_SPACE - SYMBOL_SPACE) * MS_TO_US_MULT);
    }
    wait_us((WORD_SPACE - LETTER_SPACE - SYMBOL_SPACE) * MS_TO_US_MULT);
}


void playNotes(vector<char> notes)
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
        playMorse({"...","---","..."}, 'C');
        playNotes({'C','D','E','F','G','A','B','C'});
    }
}
