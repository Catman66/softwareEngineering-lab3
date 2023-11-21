#include "Appointment.h"
#include<fstream>

using namespace std;

ofstream &Appointment::store(ofstream &ofs){
    ofs << id << ','
    << patientId << ','
    << doctorId << ','
    << date << ','
    << hour << ','
    << '\n';
    return ofs;
}