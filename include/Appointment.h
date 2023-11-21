#ifndef _APPOINTMENT_H_
#define _APPOINTMENT_H_

#include<fstream>

using namespace std;

class Appointment{

    int id;
    int patientId;
    int doctorId;
    int date;
    int hour;

    friend class Database;
public:
    Appointment() {}
    ~Appointment() {}
    void showInfomation();
    ofstream& store(ofstream& ofs);
    static void menu();
} ;


#endif