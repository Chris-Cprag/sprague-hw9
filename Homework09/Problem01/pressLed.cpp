/*
This program will turn on the LED at GPIO60 when the pushbutton at GPIO46 is
pressed, and turn off the LED when not pressed.
Example Innvocation: ./pressLED
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(){
  fstream fs;
  fstream fs_i;
  
  string inp = "0";
  string input_Path = "/sys/class/gpio/gpio46/value";
  string out_Path = "/sys/class/gpio/gpio60/value";

  fs_i.open(input_Path.c_str(),fstream::in);
  fs.open(out_Path.c_str(),fstream::out);
  getline(fs_i,inp); 
  if(inp == "1"){
    fs<<0;
    fs.flush();
  }
  else{
    fs<<1;
    fs.flush();
  }
  
  fs.close();
  fs_i.close();
  
}
