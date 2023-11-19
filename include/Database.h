#include<iostream>
#include<map>
using namespace std;

#include"Patient.h"
#include"Driver.h"
#include"Doctor.h"
#include"Nurse.h"
#include"Ambulance.h"


class Database{
    map<int, Patient> patients;
    map<int, Driver> drivers;
    map<int, Doctor> doctors;
    map<int, Nurse> nurses;
    map<int, Ambulance> ambulances;

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

    static void storePatientMap();
    static void storeDoctorMap();
    static void storeNurseMap();
    static void storeDriverMap();
    static void storeAmbulanceMap();
    static void storeAppointmentMap();
} ;