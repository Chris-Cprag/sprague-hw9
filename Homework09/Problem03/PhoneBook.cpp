#include "PhoneBook.h"


PhoneBook::PhoneBook(){
}

PhoneBook::PhoneBook(string s){
  bookName = s;
  num_Records = 0;
}

int PhoneBook::findName(string s){
  for(int i = 0; i < MAXSIZE; i++){
    if(list[i].getName() == s){
      return i; 
    }
    if(i == MAXSIZE-1){
      cout << "Name Not Found" << endl;
      return MAXSIZE;
    }
  }
  return MAXSIZE;
}

string PhoneBook::getPhoneBookName(){
  return bookName;
}

int PhoneBook::getNumberofRecords(){
  return num_Records;
}

void PhoneBook::insert(string name, int number){
    for(int i = 0; i<MAXSIZE;i++){
      if(list[i].getName() == ""){
        Record x(name,number);
        list[i] = x;
        num_Records++;
        break;
      }
      if(i == MAXSIZE-1){
        cout << "List is Full" << endl;
      }
    }
}

void PhoneBook::removeName(string s){
  int i = findName(s);
  if(i == MAXSIZE){
    return;
  }
  else{
    list[i] = Record();
    num_Records--;
  }
}

void PhoneBook::displayPhoneBook(){
 cout << "PhoneBook: " << endl;
 for(int i = 0; i<MAXSIZE;i++){
    if(list[i].getName() != ""){
      
    
    cout << "Name: " << list[i].getName() << " Number: "<<list[i].getNumber()<<endl;
  }
  }
}

int  PhoneBook::getPhoneNumber(string s){
  int i = findName(s);
  if(i == MAXSIZE){
    return 0;
  }
  else{
    return list[i].getNumber();
  }
} 



