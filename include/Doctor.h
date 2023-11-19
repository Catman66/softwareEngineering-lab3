#include<Person.h>
#include<list>

using namespace std;


class Doctor: public Person{
private:
    int timeAvailable;
    bool booked;

public:
    void showDesc(); 
}; 