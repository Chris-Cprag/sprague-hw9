#include <iostream>
#include "myGpio.h"

MYGPIO::MYGPIO(int num){
  number = num; //GPIO Number
  path = "/sys/class/gpio/gpio" + to_string(number) + "/";
}

int MYGPIO::write(string path, string filename, string value){
  stream.open(path + filename);
  stream << value;
  stream.flush();
  stream.close();
  return 0;
}

int MYGPIO::write(string path, string filename, int value){
  stream.open(path + filename);
  stream << value;
  stream.flush();
  stream.close();
  return 0;
}

string MYGPIO::read(string path, string filename){
  fstream fs;
  fs.open((path+filename).c_str(),fstream::in);
  string line = "";
  getline(fs,line);
  fs.close();
  return line;
}

int MYGPIO::getNumber(){
  return number;
}

void MYGPIO::setDirection(GPIO_DIRECTION dir){
 if(dir == IN){
  write(path,"direction","in");
  }
  else{
  write(path,"direction","out");
  }
}

GPIO_DIRECTION MYGPIO::getDirection(){
  if(read(path, "direction")=="out"){
    return OUT;
  }
  else{
    return IN;
  }
}

int MYGPIO::setValue(GPIO_VALUE val){
  write(path,"value",val);
  return 0;
}

void MYGPIO:: toggleOutput(){
  if(read(path,"value") == "1"){
    write(path,"value",0);
  }
  else{
    write(path,"value",1);
  }
}

GPIO_VALUE MYGPIO:: getValue(){
  
  if(read(path,"value")=="1"){
    return HIGH;
  }
  else{
    return LOW;
  }
}

MYGPIO::~MYGPIO(){
  cout << "Destroying GPIO Connection" << endl;
}
