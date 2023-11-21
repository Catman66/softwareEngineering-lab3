#ifndef _APPOINTMENT_H_
#define _APPOINTMENT_H_

using namespace std;



class Appointment{

    int id;
    int patientId;
    int doctorId;
    int date, hour;

public:
    Appointment(int id, int patientId, int doctorId, int date, int hour);
    ~Appointment();
    void showInfomation();
    virtual ofstream& store(ofstream& ofs);
} ;


#endif