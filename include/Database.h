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
#include"Appointment.h"

class Database{
    static map<int, Patient> patients;
    static map<int, Doctor> doctors;
    static map<int, Nurse> nurses;
    static map<int, Driver> drivers;
    static map<int, Ambulance> ambulances;
    static map<int, Appointment> appointments;

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

    static void loadMap(const string& fname, map<int, Person&>& mp);
    

    static void storePatientMap();
    static void storeDoctorMap();
    static void storeNurseMap();
    static void storeDriverMap();
    static void storeAmbulanceMap();
    static void storeAppointmentMap();

    static Patient* lookupPatient(int id);
    static Doctor* lookupDoctor(int id);
    static Nurse* lookupNurse(int id);
    static Driver* lookupDriver(int id);
    static Ambulance* lookupAmbulance(int id);
    static Appointment* lookupAppointment(int id);

    static void loadPersonInfo(stringstream& buffer, Person& p);
    static int getNewId();
    static void showAllInfomation();
    static int showAllAvailableDoctors();
    static ofstream& storePerson(const string fname, Person& p);
    static void showAppointmentsOf(int patientId);
    static void addFeedback(string& feedback);
    static const string patientFname;
    static const string doctorFname;
    static const string nurseFname;
    static const string driverFname;
    static const string ambulanceFname;
    static const string appointmentFname;    
    static const string tmpFname;

    static int date;
} ;


#endif


/*

Patient
Doctor
Nurse
Driver
Ambulance
Appointment

patient
doctor
nurse
driver
ambulance
appointment

*/