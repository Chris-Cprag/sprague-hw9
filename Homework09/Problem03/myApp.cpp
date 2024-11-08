/*
This program is a menu based object oriented program that will be a command line
menu to insert, display and remove names from a phonebook. Traverse the program
by entering numbers into the command line with the associated prompt.
Example Innvocation: ./myApp
*/

#include <iostream>
#include "PhoneBook.h"

using namespace std;

void request(){
  cout<< endl;
  cout << "What would you like to do next?" <<endl;
  cout << "1. Insert a name and a number" <<endl;
  cout << "2. Get a number for a person" <<endl;
  cout << "3. Display a phone book" <<endl; 
  cout << "4. Remove a person from the phone book"<<endl;
  cout << "5. Quit"<<endl;
  cout <<"Enter your Choice: " <<endl;
  cout << endl;
}

string request_Name(){
  cout << "Plase Enter a name: " <<endl;
  string name = "";
  getline(cin,name);
  return name;
}
int main(){
  
  PhoneBook book("Hotel Log");
  string input = "";
  string input2 = "";
  request();
  while(1){
    getline(cin, input);
    if(input == "1"){
      cout<< "Insert Name: ";
      getline(cin, input);
      cout << "Insert Number: ";
      getline(cin, input2);
      book.insert(input,stoi(input2));
      request();
    }
    else if(input == "2"){
      input2 = request_Name();
      input = to_string(book.getPhoneNumber(input2));
      if(input == "0"){
        //Ignore
      }
      else{
        cout << input2 + "'s number is: " + input <<endl;
      }
      request();
    }
    else if(input == "3"){
      book.displayPhoneBook();
      request();
    }
    else if(input == "4"){
      input2 = request_Name();
      book.removeName(input2);
      request();
    }
    else if(input == "5"){
      break;
    }
    else{
      cout << "Invalid Command" <<endl;
      request();
    }

  }

}
