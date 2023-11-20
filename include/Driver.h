#ifndef _DRIVER_H_
#define _DRIVER_H_


#include<Person.h>

using namespace std;

class Driver: public Person{
public:
    Driver() {}
    ~Driver() {}
    void showInfomation();

    int registeInfomation();
}; 


#endif