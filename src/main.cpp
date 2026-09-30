#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>
int main() {
    //initialize butano
    bn::core::init();

    //gonna start manipulating colors via variables instead of magic numbers!
    //default gray
    int red = 15;
    int green = 15;
    int blue = 15;

    //setting the color to GRAY
    bn::backdrop::set_color(bn::color(red, green, blue));

    //1 second ticker
    int default_back = 0;

    //infinite loop to keep it running
    //EACH FRAME:
    while(true) {

        //make the whole process one big if/else

        //hold both to steal red and green to add blue;
        if (bn::keypad::b_held() && bn::keypad::a_held()) {
            if (blue < 30) {
                blue++;
            } else {
                blue = 30;
            }
            if (red > 0) {
                red--;
            }
            if (green > 0) {
                green--;
            }
            bn::backdrop::set_color(bn::color(red, green, blue));
            default_back = 0;

        } //press to add red by stealing blue and green
        else if (bn::keypad::a_held()) {
            if (red < 30) {
                red++;
            } else {
                red = 30;
            }
            if (blue > 0) {
                blue--;
            }
            if (green > 0) {
                green--;
            }
            default_back = 0;
            bn::backdrop::set_color(bn::color(red, green, blue));

        } //press to add green by stealing red and blue
        else if (bn::keypad::b_held()) {
            if (green < 30) {
                green++;
            } else {
                green = 30;
            }
            if (blue > 0) {
                blue--;
            }
            if (red > 0) {
                red--;
            }
            default_back = 0;
            bn::backdrop::set_color(bn::color(red, green, blue));
        }
        
        //color stays and starts shifting back after no button presses
        if (default_back < 60) {
        default_back++;
        } else {
            //return red back to middle
            if (red < 15) {
                red++;
            } else if (red > 15) {
                red--;
            }
            //return green back to middle
            if (green < 15) {
                green++;
            } else if (green > 15) {
                green--;
            }
            //return blue back to middle
            if (blue < 15) {
                blue++;
            } else if (blue > 15) {
                blue--;
            }            
            bn::backdrop::set_color(bn::color(red, green, blue));
        }

        bn::core::update();
    }
}