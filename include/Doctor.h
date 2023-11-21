#ifndef _DOCTOR_H_
#define _DOCTOR_H_

#include<Person.h>
#include<fstream>


using namespace std;


class Doctor: public Person{
    friend class Database;
    friend class Appointment;
private:
    int timeAvailable;
    bool booked;
public:
    Doctor() {}
    ~Doctor(){}
    void showInfomation();
    int registeInfomation();
    ofstream& store(ofstream& ofs);
    static void menu();
}; 

#endif