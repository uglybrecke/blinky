#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
int main() {
    //initialize butano
    bn::core::init();

    //setting the color to blue
    bn::backdrop::set_color(bn::color(20, 20, 31));

    //infinite loop to keep it running
    while(true) {
        bn::core::update();
    }
}