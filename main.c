#include <kipr/botball.h>
#include "hardwaretest.c"

/*
digital0 = switch motor
digital1 = up
digital2 = down

lbtn = switch between motor/port
rbtn = end program


*/
int main() {
    /* Welcome message */
    print('Hardware Test Rewrite', 'IDLE');

    while (1) {
        if (DIGITAL0) {
            /* Change motor/servo port */
            changePort();
        } 
        else if (DIGITAL1) {
            /* Move motor/servo up */
            moveUp();
        } 
        else if (DIGITAL2) {
            /* Move motor/servo down */
            moveDown();
        }
        else if (LBTN) {
            /* Switch from motor to servo */
            switchInterface();
        }
        else if (RBTN) {
            /* Change speed */
            changeSpeed();
        }    
    }
}