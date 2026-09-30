#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>
int main() {
    //initialize butano
    bn::core::init();

    //gonna start manipulating colors via variables instead of magic numbers!
    int red = 29;
    int green = 17;
    int blue = 0;

    //setting the color to ORANGE
    bn::backdrop::set_color(bn::color(red, green, blue));

    int default_back = 0;

    //infinite loop to keep it running
    //EACH FRAME:
    while(true) {
        //setting the color to ORANGE default each loop
        // bn::backdrop::set_color(bn::color(29, 17, 0));

        //pressing a to swap the condition from true to false?
        
        //if _A is pressed change background to pink
        //returns true or false based off whether it's press or not
        // if (bn::keypad::a_held()) {
        // bn::backdrop::set_color(bn::color(29, 0, 17));
        // }

        // //if _B is pressed change color
        // if (bn::keypad::b_held()) {
        // bn::backdrop::set_color(bn::color(0, 29, 17));
        // }

        //press to add red
        if (bn::keypad::a_held()) {
            if (red < 30) {
                red++;
            } else {
                red = 30;
            }
            default_back = 0;
            bn::backdrop::set_color(bn::color(red, green, blue));
        }

        //press to add green
        if (bn::keypad::b_held()) {
            if (green < 30) {
                green++;
            } else {
                green = 30;
            }
            default_back = 0;
            bn::backdrop::set_color(bn::color(red, green, blue));
        }

        //hold both to add blue;
        if (bn::keypad::b_held() && bn::keypad::a_held()) {
            if (blue < 30) {
                blue++;
            } else {
                blue = 30;
            }
            bn::backdrop::set_color(bn::color(red, green, blue));
            //set default_orange to zero everytime we do this to avoid flcikering orange!
            default_back = 0; //maybe 59 so it almost immediatly returns when you let up?
        }

        //color stays for 1 sec after pressed before starting to return
        if (default_back < 60) {
        default_back++;
        } else {
            if (red < 29) {
                red++;
            } else {
                red = 29; }
            if (green < 17) {
                green++;
            } else {
                green--;
            }
            if (blue > 0) {
                blue--;
            } else {
                blue++;
            }
            //default_back = 0;
            bn::backdrop::set_color(bn::color(red, green, blue));
        }

        bn::core::update();
    }
}