using namespace std;
#include <string> //It would not let me use string unless i put this in
//Even though I use namespace STD

class Record {
  private:
    string name; 
    int number;
  public:
    Record();
    Record(string name, int number);
    string getName();
    int getNumber();
    void setName(string s);
    void setNumber(int n);
    ~Record();
};
