#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>
int main() {
    //initialize butano
    bn::core::init();

    //setting the color to ORANGE
    bn::backdrop::set_color(bn::color(29, 17, 0));

    int default_orange = 0;

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

        //press to change color
        if (bn::keypad::a_pressed()) {
            bn::backdrop::set_color(bn::color(29, 0, 17));
        }

        //press to change color
        if (bn::keypad::b_pressed()) {
            bn::backdrop::set_color(bn::color(0, 17, 29));
        }

        //hold to blend
        if (bn::keypad::b_held() && bn::keypad::a_held()) {
            bn::backdrop::set_color(bn::color(14, 9, 23));
            //set default_orange to zero everytime we do this to avoid flcikering orange!
            default_orange = 0; 
        }

        //shoulder buttons a

        //color stays for 1 sec after pressed before returning
        if (default_orange < 60) {
        default_orange++;
        } else {
        bn::backdrop::set_color(bn::color(29, 17, 0));
        default_orange = 0;
        }

        bn::core::update();
    }
}