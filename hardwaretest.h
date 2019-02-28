#ifndef HARDWARETEST_H
#define HARDWARETEST_H

/* Defines for digital buttons */
#define DIGITAL0 digital(0)
#define DIGITAL1 digital(1)
#define DIGITAL2 digital(2)
#define DIGITAL3 digital(3)
#define DIGITAL4 digital(4)
#define DIGITAL5 digital(5)
#define DIGITAL6 digital(6)
#define DIGITAL7 digital(7)
#define DIGITAL8 digital(8)
#define DIGITAL9 digital(9)

/* Defines for physical L/R buttons */
#define LBTN left_button_clicked()
#define RBTN right_button_clicked()

/* Defines for motor/servo interfaces */
#define MOTORS 0
#define SERVOS 1

int currentMotor;
int currentServo;
int currentSpeed;
int selectedInterface;

void print();
void changePort();
void changeSpeed();
void moveUp();
void moveDown();
void switchInterface();

#endif