/*
This file utilizes the myGpio.h header class and creates two GPIO
objects, one being an input and one being an output. The program
define both pins as objects and sets the directions of the pins 
respectively. It flashes the output pin for 3 seconds before
turning it off, printing its value before, during and after.
The program then reads the input pin and displays it.
Example Innvocation: ./myGpioApp
*/
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "myGpio.h"

using namespace std;

int main(){

  //Part B
  MYGPIO in_Pin(46);
  //Part A
  MYGPIO out_Pin(60);

  in_Pin.setDirection(IN);
  out_Pin.setDirection(OUT);

  //Part C
  cout << "Before Value: " << out_Pin.getValue() <<endl;
  out_Pin.setValue(HIGH);
  cout << "Set Value: "<< out_Pin.getValue() << endl;
  sleep(3);
  out_Pin.setValue(LOW);
  cout << "After Value: "<<out_Pin.getValue() <<endl;
  
  //Part D
  cout << "Pin 8.16 Value: " << in_Pin.getValue() << endl;



}
