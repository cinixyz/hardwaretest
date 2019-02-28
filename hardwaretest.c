#include "hardwaretest.h"

selectedInterface = MOTORS;
currentMotor = 0;
currentServo = 0;
currentSpeed = 50;

/*
 *   void print();
 *   Description: Takes two string inputs and prints them neatly into the console
 *   Parameters: 1) string actionMsg[] 2) string status[]
 *   Returns: N/A
 */

void print(char actionMsg[], char status[]) {
    console_clear();
    printf('\n\n\n');
    printf('-------------------------------------------------------\n\n');
    printf('%s\n', actionMsg);
    printf('%s\n', status);
    printf('\n\n');
    if (selectedInterface == MOTORS) {
        printf('Current Motor: %d\n', currentMotor);
    } else {
        printf('Current Servo: %d\n', currentServo);
    }
    printf('Current Speed: %d\n\n', currentSpeed);
    printf('-------------------------------------------------------');
}

/*
 *   void changePort();
 *   Description: Loops through motor/servo ports to select them
 *   Parameters: N/A
 *   Returns: N/A
 */
void changePort() {
    if (selectedInterface == MOTORS) {
        switch (currentMotor) {
            case 0:
                currentMotor = 1;
                print('Changed motor to 1', 'Current Motor : 1');
                break;
            case 1:
                currentMotor = 2;
                print('Changed motor to 2', 'Current Motor : 2');
                break;
            case 2:
                currentMotor = 3;
                print('Changed motor to 3', 'Current Motor : 3');
                break;
            case 3:
                currentMotor = 0;
                print('Changed motor to 0', 'Current Motor: 0');
                break;
            default:
                printf('Invalid Motor: %d! Process exiting.', currentMotor); /* In the impossible siutation currentMotor is not those values. */
                exit(1);
        }
    } 
    
    /* If servos are selected */
    else {
        /* Iterate through servo ports */
        switch (currentServo) {
            case 0:
                currentServo = 1;
                print('Changed servo to 1', 'Current Servo : 1');
                break;
            case 1:
                currentServo = 2;
                print('Changed servo to 2', 'Current Servo : 2');
                break;
            case 2:
                currentServo = 3;
                print('Changed servo to 3', 'Current Servo : 3');
                break;
            case 3:
                currentServo = 0;
                print('Changed servo to 0', 'Current Servo: 0');
                break;
            default:
                printf('Invalid Servo: %d! Process exiting.', currentServo); /* In the impossible siutation currentServo is not those values. */
                exit(1);
        }
    }
}

/*
 *  void changeSpeed();
 *  Description: Changes the current speed selected
 *  Parameters: N/A
 *  Returns: N/A
 */
void changeSpeed() {
    switch(currentSpeed) {
        case 25:
            currentSpeed = 50;
            print('Changed speed to 50.', 'Current Speed: 50');
            break;
        case 50:
            currentSpeed = 75;
            print('Changed speed to 75.', 'Current Speed: 75');
            break;
        case 75:
            currentSpeed = 100;
            print('Changed speed to 100.', 'Current Speed: 100');
            break;
        case 100:
            currentSpeed = 25;
            print('Changed speed to 25.', 'Current Speed: 25');
            break;
        default:
            currentSpeed = 25;
            print('Changed speed to 25.', 'Current Speed: 25');
    }
}

/*
 *  void moveUp();
 *  Description: Move the selected motor/servo "up"
 *  Parameters: N/A
 *  Returns: N/A
 */

void moveUp() {
    if (selectedInterface == MOTORS) {
        motor(currentMotor, currentSpeed);
    } else {
        /* Get servo position and add currentSpeed */
        int servoPos = get_servo_position(currentServo);
        set_servo_position(currentServo, (servoPos + currentSpeed));
    }
}

/*
 *  void moveDown();
 *  Description: Move the selected motor/servo "down"
 *  Parameters: N/A
 *  Returns: N/A
 */

void moveDown() {
    if (selectedInterface == MOTORS) {
        motor(currentMotor, -currentSpeed);
    } else {
        /* Get servo position and add currentSpeed */
        int servoPos = get_servo_position(currentServo);
        set_servo_position(currentServo, (servoPos - currentSpeed));
    }
}

/*
 *   void switchInterface();
 *   Description: Switches from motors to servos.
 *   Parameters: N/A
 *   Returns: N/A
 */

void switchInterface() {
    if (selectedInterface == MOTORS) {
        selectedInterface = SERVOS;
    }
    else {
        selectedInterface = MOTORS;
    }
}