#ifndef _PATIENT_H_
#define _PATIENT_H_

#include<Person.h>

using namespace std;

class Patient: public Person{
private:
    bool hospitalized;
    
    friend class Database;
public:
    Patient() {}
    ~Patient() {}
    void showInfomation();
    void hospitalize();
    int registeInfomation();
}; 

#endif