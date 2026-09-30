#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>
int main() {
    //initialize butano
    bn::core::init();

    //setting the color to ORANGE
    bn::backdrop::set_color(bn::color(29, 17, 0));

    //infinite loop to keep it running
    //EACH FRAME:
    while(true) {
        //setting the color to ORANGE default each loop
        bn::backdrop::set_color(bn::color(29, 17, 0));

        //pressing a to swap the condition from true to false?
        
        //if _A is pressed change background to pink
        //returns true or false based off whether it's press or not
        if (bn::keypad::a_held()) {
        bn::backdrop::set_color(bn::color(29, 0, 17));
        }

        //if _B is pressed change color
        if (bn::keypad::b_held()) {
        bn::backdrop::set_color(bn::color(0, 29, 17));
        }

        bn::core::update();
    }
}