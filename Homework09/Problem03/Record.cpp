using namespace std;
#include "Record.h"

Record::Record(){
}

Record::Record(string name, int number){
  this->name = name;
  this->number = number;
}

string Record::getName(){
  return name;
}

int Record::getNumber(){
  return number;
}

void Record::setName(string s){
  name = s;
}

void Record::setNumber(int n){
  number = n;
}

Record::~Record(){
}
