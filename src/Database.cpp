#include "Database.h"
#include <fstream>
#include <sstream>
#include <cassert>


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
const string Database::tmpFname = "data/tmp.csv";


void Database::loadMaps(){ 
    loadPatientMap();
    loadDoctorMap();
    loadNurseMap();
    loadDriverMap();
    loadAmbulanceMap();
    loadAppointmentMap();

#ifdef DEBUG
    showAllInfomation();
#endif
}
void Database::storeMaps(){
    ofstream patientOfs(Database::patientFname);
    ofstream doctorOfs(Database::patientFname);
    ofstream nurseOfs(Database::patientFname);
    ofstream driverOfs(Database::patientFname);
    ofstream ambulanceOfs(Database::patientFname);
    ofstream appointmentOfs(Database::patientFname);

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
}


int Database::getNewId()
{
    return patients.size() + doctors.size() + nurses.size() + drivers.size() + 1;
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
    getline(f >> ws, buffer);
    while (getline(f >> ws, buffer))
    {
        Patient p;

        // load the basic infomation of a person
        stringstream s(buffer);
        loadPersonInfo(s, p);
        
        // load info of patient
        string hospitalized;
        getline(s, hospitalized, ',');
        p.hospitalized = hospitalized[0] == 'Y';

        Database::patients[p.id] = p;
    }
    f.close();
    return;
}

void Database::loadDoctorMap(){
    
 }
void Database::loadNurseMap(){ }
void Database::loadDriverMap(){ }
void Database::loadAmbulanceMap(){ }
void Database::loadAppointmentMap(){ }

Patient* Database::lookupPatient(int id){
    if (patients.find(id) == patients.end()){
        cout << "patient not found" << endl;
        return NULL;
    }
    return &patients.find(id)->second;
}

