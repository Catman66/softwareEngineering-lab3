#ifndef _DOCTOR_H_
#define _DOCTOR_H_

#include<Person.h>
#include<list>

using namespace std;


class Doctor: public Person{
private:
    int timeAvailable;
    bool booked;
public:
    Doctor() {}
    ~Doctor(){}
    void showInfomation();
    int registeInfomation();
}; 

#endif