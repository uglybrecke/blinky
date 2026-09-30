#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>
int main() {
    //initialize butano
    bn::core::init();

    //setting the color to ORANGE
    bn::backdrop::set_color(bn::color(29, 17, 0));

    //if a is pressed change background to pink
    //returns true or false based off whether it's press or not
    if (bn::keypad::a_pressed()) {
        bn::backdrop::set_color(bn::color(31, 0, 15));
    }

    //infinite loop to keep it running
    while(true) {
        bn::core::update();
    }
}