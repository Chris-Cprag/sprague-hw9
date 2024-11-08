#define MAXSIZE  10
#include <iostream>
using namespace std;
#include "Record.h"
class PhoneBook{
  private:
    Record list[MAXSIZE];
    string bookName;
    int num_Records;
    int findName(string s);
  public:
    PhoneBook();
    PhoneBook(string s);
    string getPhoneBookName();
    int getNumberofRecords();
    void insert(string name, int number);
    void displayPhoneBook();
    void removeName(string s);
    int getPhoneNumber(string s);
};
