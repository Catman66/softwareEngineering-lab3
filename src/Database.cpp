#include "Database.h"
#include <fstream>
#include <sstream>
#include <cassert>
#include <map>
#include <utility>

using namespace std;

#define Log cout 
#define Bug cout << "[BUG] "


map<int, Patient> Database::patients;
map<int, Driver> Database::drivers;
map<int, Doctor> Database::doctors;
map<int, Nurse> Database::nurses;
map<int, Ambulance> Database::ambulances;
map<int, Appointment> Database::appointments;

const string Database::patientFname = "data/Patient.csv";
const string Database::doctorFname = "data/Doctor.csv";
const string Database::nurseFname = "data/Nurse.csv";
const string Database::driverFname = "data/Driver.csv";
const string Database::ambulanceFname = "data/Ambulance.csv";
const string Database::appointmentFname = "data/Appointment.csv";

const string Database::tmpFname = "data/tmp.csv";




void Database::loadMaps(){ 
    loadPatientMap();
    loadDoctorMap();
    loadNurseMap();
    loadDriverMap();
    loadAmbulanceMap();
    loadAppointmentMap();

    // fresh the state of the doctors each time the system resets
    for (auto& d : doctors) {
        d.second.booked = false;
    }

#ifdef DEBUG
    showAllInfomation();
#endif
}
void Database::storeMaps(){
    ofstream patientOfs(Database::patientFname);
    ofstream doctorOfs(Database::doctorFname);
    ofstream nurseOfs(Database::nurseFname);
    ofstream driverOfs(Database::driverFname);
    ofstream ambulanceOfs(Database::ambulanceFname);
    ofstream appointmentOfs(Database::appointmentFname);

    assert(
        patientOfs
    && doctorOfs
    && nurseOfs
    && driverOfs
    && ambulanceOfs
    && appointmentOfs
    );
    
    for(auto& p : patients) p.second.store(patientOfs);
    for(auto& p : doctors) p.second.store(doctorOfs);
    for(auto& p : nurses) p.second.store(nurseOfs);
    for(auto& p : drivers) p.second.store(driverOfs);
    for(auto& p : ambulances) p.second.store(ambulanceOfs);
    for(auto& p : appointments) p.second.store(appointmentOfs);

    patientOfs.close();
    doctorOfs.close();
    nurseOfs.close();
    driverOfs.close();
    ambulanceOfs.close();
    appointmentOfs.close();
}

void Database::showAllInfomation(){
    for(auto& p : patients) p.second.showInfomation();
    for(auto& p : doctors) p.second.showInfomation();
    for(auto& p : nurses) p.second.showInfomation();
    for(auto& p : drivers) p.second.showInfomation();    
    for(auto& p : ambulances) p.second.showInfomation();    
    for(auto& p : appointments) p.second.showInfomation();    
}


int Database::getNewId()
{
    return patients.size() + doctors.size() + nurses.size() + drivers.size() 
    + appointments.size() + ambulances.size() + 1;
}
void Database::storeAppointmentMap() { cout << "not implemented " << endl; }

void Database::loadPersonInfo(stringstream& s, Person& p){
    string id, name, gender, age, category;

    getline(s, id, ',');
    getline(s, name, ',');
    getline(s, gender, ',');
    getline(s, age, ',');
    getline(s, category, ',');

    p.id = stoi(id);
    p.name = name;
    p.gender = gender[0];
    p.age = stoi(age);
    p.category = stoi(category);
}

void Database::loadPatientMap(){ 
    ifstream f;
    f.open(patientFname, ios::in);
    if(!f){
        Bug << "opening file" << patientFname << "failed" << endl;
        return;
    }
    string buffer;
    while (getline(f >> ws, buffer))
    {
        Patient p;
        stringstream s(buffer);
        loadPersonInfo(s, p);
        
        string hospitalized;
        getline(s, hospitalized, ',');
        p.hospitalized = hospitalized[0] == 'Y';

        Database::patients[p.id] = p;
    }
    f.close();
    return;
}

void Database::loadDoctorMap(){
    ifstream f;
    f.open(doctorFname, ios::in);
    if(!f){
        Bug << "opening file" << doctorFname << "failed" << endl;
        return;
    }
    string buffer;
    while (getline(f >> ws, buffer))
    {
        Doctor d;
        stringstream s(buffer);
        loadPersonInfo(s, d);
        
        string timeAvailable, booked;
        getline(s, timeAvailable, ',');
        getline(s, booked, ',');
        d.timeAvailable = stoi(timeAvailable);
        d.booked = booked[0] == 'Y';
        
        Database::doctors[d.id] = d;
    }
    f.close();
    return;
 }
void Database::loadNurseMap(){ 
    ifstream f;
    f.open(nurseFname, ios::in);
    if(!f){
        Bug << "opening file" << nurseFname << "failed" << endl;
        return;
    }
    string buffer;
    while (getline(f >> ws, buffer))
    {
        Nurse p;
        stringstream s(buffer);
        loadPersonInfo(s, p);
        
        Database::nurses[p.id] = p;
    }
    f.close();
    return;
}
void Database::loadDriverMap(){ 
    ifstream f;
    f.open(driverFname, ios::in);
    if(!f){
        Bug << "opening file" << driverFname << "failed" << endl;
        return;
    }
    string buffer;
    while (getline(f >> ws, buffer))
    {
        Driver p;
        stringstream s(buffer);
        loadPersonInfo(s, p);
        
        Database::drivers[p.id] = p;
    }
    f.close();
    return;
}
void Database::loadAmbulanceMap(){ 
    ifstream f;
    f.open(ambulanceFname, ios::in);
    if(!f){
        Bug << "opening file" << ambulanceFname << "failed" << endl;
        return;
    }
    string buffer;
    while (getline(f >> ws, buffer))
    {
        Ambulance amb;
        stringstream s(buffer);
        
        string id, registrationId, driverId;
        getline(s, id, ',');
        getline(s, registrationId, ',');
        getline(s, driverId, ',');
        
        amb.id = stoi(id);
        amb.registrationId = registrationId;
        amb.driverId = stoi(driverId);
        Database::ambulances[amb.id] = amb;
    }
    f.close();
    return;
}
void Database::loadAppointmentMap(){ 
    ifstream f;
    f.open(appointmentFname, ios::in);
    if(!f){
        Bug << "opening file" << appointmentFname << "failed" << endl;
        return;
    }
    string buffer;
    while (getline(f >> ws, buffer))
    {
        Appointment appmnt;
        stringstream s(buffer);
        
        string id, patientId, doctorId, date, hour;
        getline(s, id, ',');
        getline(s, patientId, ',');
        getline(s, doctorId, ',');
        getline(s, date, ',');
        getline(s, hour, ',');

        appmnt.id = stoi(id);
        appmnt.patientId = stoi(patientId);
        appmnt.doctorId = stoi(doctorId);
        appmnt.date = stoi(date);
        appmnt.hour = stoi(hour);
        
        Database::appointments[appmnt.id] = appmnt;
    }
    f.close();
    return;
}


Patient* Database::lookupPatient(int id){
    if (patients.find(id) == patients.end()) {
        return NULL;
    }
    return &patients.find(id)->second;
}
Doctor* Database::lookupDoctor(int id){
    if (doctors.find(id) == doctors.end()  ) {
        return NULL;
    }
    return &doctors.find(id)->second;
}
Nurse* Database::lookupNurse(int id){
    if (nurses.find(id) == nurses.end()) {
        return NULL;
    }
    return &nurses.find(id)->second;
}
Driver* Database::lookupDriver(int id){
    if (drivers.find(id) == drivers.end()  ) {
        return NULL;
    }
    return &drivers.find(id)->second;
}
Ambulance* Database::lookupAmbulance(int id){
    if (ambulances.find(id) == ambulances.end()) {
        return NULL;
    }
    return &ambulances.find(id)->second;
}
Appointment* Database::lookupAppointment(int id){
    if (appointments.find(id) == appointments.end()) {
        return NULL;
    }
    return &appointments.find(id)->second;
}

int Database::showAllAvailableDoctors(){
    int n = 0;
    for (auto& d : doctors) {
        if (d.second.booked == false) {
            d.second.showInfomation();
            n++;
            cout << "============" << endl;

        }
    }
    return n;
}