#include<Person.h>

using namespace std;

class Patient: public Person{
private:
    bool hospitalized;
    
public:
    void showInfomation();
}; 