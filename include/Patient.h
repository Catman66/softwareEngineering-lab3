#ifndef _PATIENT_H_
#define _PATIENT_H_

#include<Person.h>

using namespace std;

class Patient: public Person{
private:
    bool hospitalized;
    
public:
    void showInfomation();
}; 

#endif