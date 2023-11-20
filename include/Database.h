#ifndef _DATABASE_H_
#define _DATABASE_H_

#include<iostream>
#include<map>
using namespace std;

#include"Patient.h"
#include"Driver.h"
#include"Doctor.h"
#include"Nurse.h"
#include"Ambulance.h"


class Database{
    static map<int, Patient> patients;
    static map<int, Driver> drivers;
    static map<int, Doctor> doctors;
    static map<int, Nurse> nurses;
    static map<int, Ambulance> ambulances;

    friend class Person;
    friend class Patient;
    friend class Doctor;
    friend class Nurse;
    friend class Driver;
    friend class Ambulance;
    friend class Appointment;

public:
    static void loadMaps();
    static void storeMaps();

    static void loadPatientMap();
    static void loadDoctorMap();
    static void loadNurseMap();
    static void loadDriverMap();
    static void loadAmbulanceMap();
    static void loadAppointmentMap();


    static void storePatientMap();
    static void storeDoctorMap();
    static void storeNurseMap();
    static void storeDriverMap();
    static void storeAmbulanceMap();
    static void storeAppointmentMap();

    static Patient* lookupPatient(int id);

    static void loadPersonInfo(stringstream& buffer, Person& p);
    static int getNewId();
} ;


#endif