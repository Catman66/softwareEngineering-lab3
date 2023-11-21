#include "Appointment.h"
#include<fstream>
#include<iostream>
#include<Database.h>

#define GLOBAL_TIME 10


using namespace std;

void Appointment::showInfomation() {
    cout 
    << "id: " << id << '\n'    
    << "patientId: " << patientId << '\n'
    << "doctorId: " << doctorId << '\n'
    << "date: " << date << '\n'
    << "hour: " << hour << '\n'
    << endl;
}

ofstream &Appointment::store(ofstream &ofs)
{
    ofs << id << ','
    << patientId << ','
    << doctorId << ','
    << date << ','
    << hour << ','
    << '\n';
    return ofs;
}

void Appointment::menu(){
    while(1){
        int choice = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect a choice:\n\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        
        cout << "[1] : new appointment\n";
        cout << "[2] : show history appointments\n";
        cout << "[3] : recomend a doctor\n";
        cout << "[-1] : EXIT\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n";

        if (choice == -1)        {
            break;
        } else if (choice == 1) {
            int patientId, doctorId;

            cout << "please input you patient id" << endl;
            cin >> patientId;

            cout << "doctors available" << endl;
            int nAvailable = Database::showAllAvailableDoctors();
            if (nAvailable == 0) {
                cout << "sorry, no doctors available" << endl;
                continue;
            }
            cout << "Please select one" << endl;

            cin >> doctorId;
            Doctor* d = Database::lookupDoctor(doctorId);
            if (d && d->booked == false) {
                Appointment appmnt;
                appmnt.id = Database::getNewId();
                appmnt.date = GLOBAL_TIME;
                appmnt.hour = d->timeAvailable;
                appmnt.doctorId = d->id;
                appmnt.patientId = patientId;

                d->booked = true; 
                Database::appointments.insert_or_assign(appmnt.id, appmnt);
                cout << "book succeed" << endl;
            } else {
                cout << "book failed " << endl;                
            }
        } else if (choice == 2) {
            for (auto& a : Database::appointments) {
                a.second.showInfomation();
            }
        } else if (choice == 3) {
            for (auto& d : Database::doctors) {
                if (d.second.booked == false) {
                    cout << "recomend this doctor: " << endl;
                    d.second.showInfomation();
                    break;
                }
            } 
        } else {
            cout << "invalid choice: " << choice << endl; 
        }
        cout << endl;
    }
}
