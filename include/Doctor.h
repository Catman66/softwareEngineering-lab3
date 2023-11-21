#ifndef _DOCTOR_H_
#define _DOCTOR_H_

#include<Person.h>
#include<list>

using namespace std;


class Doctor: public Person{
    friend class Database;
private:
    int timeAvailable;
    bool booked;
public:
    Doctor() {}
    ~Doctor(){}
    void showInfomation();
    int registeInfomation();
    virtual ofstream& store(ofstream& ofs) = 0;

}; 

#endif