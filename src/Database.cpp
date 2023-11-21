#include "Database.h"
#include <fstream>
#include <sstream>
using namespace std;

#define Log cout 
#define Bug cout << "[BUG] "


map<int, Patient> Database::patients;
map<int, Driver> Database::drivers;
map<int, Doctor> Database::doctors;
map<int, Nurse> Database::nurses;
map<int, Ambulance> Database::ambulances;

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
    for(auto& p : patients) store(p.second, patientFname);
    
}

void Database::showAllInfomation(){
    for(auto& p : patients) p.second.showInfomation();
    for(auto& p : doctors) p.second.showInfomation();
    for(auto& p : nurses) p.second.showInfomation();
    for(auto& p : drivers) p.second.showInfomation();    
}




void Database::storePatientMap(){
    ofstream ofs;

    ofs.open(tmpFname, ios::out);
    // `le first line conataining column headers:
    if (!ofs) {
        Bug << "file tmpt open failed" << endl;
        return; 
    }
    
    ofs << "id,name,gender,age,category,hospitalized,\n";
    for (auto patient : Database::patients)
        storePerson(ofs, patient.second) 
        << (patient.second.hospitalized ? 'Y' : 'N') << ","
        << '\n';
    
    Log << "dump the map of " << patients.size() << " patients" << endl;

    ofs.close();
    remove(patientFname.c_str());
    rename(tmpFname.c_str(), patientFname.c_str());
    return;
}
void Database::storeDoctorMap(){
    ofstream ofs;

    ofs.open(tmpFname, ios::out);
    // `le first line conataining column headers:
    if (!ofs) {
        Bug << "file tmpt open failed" << endl;
        return; 
    }
    
    ofs << "id,name,gender,age,category,hospitalized,\n";
    for (auto p : Database::doctors)
        storePerson(ofs, p.second) 
        << p.second.timeAvailable << ","
        << (p.second.booked ? 'Y' : 'N') << ','
        << '\n';
    
    Log << "dump the map of " << doctors.size() << " patients" << endl;

    ofs.close();
    remove(doctorFname.c_str());
    rename(tmpFname.c_str(), doctorFname.c_str());
    return;
}

void Database::storeNurseMap(){
    ofstream ofs;

    ofs.open(tmpFname, ios::out);
    // `le first line conataining column headers:
    if (!ofs) {
        Bug << "file tmpt open failed" << endl;
        return; 
    }
    
    ofs << "id,name,gender,age,category,hospitalized,\n";
    for (auto patient : Database::nurses)
        storePerson(ofs, patient.second);
    
    Log << "dump the map of " << patients.size() << " patients" << endl;

    ofs.close();
    remove(nurseFname.c_str());
    rename(tmpFname.c_str(), nurseFname.c_str());
    return;
}
void Database::storeDriverMap(){
    ofstream ofs;

    ofs.open(tmpFname, ios::out);
    // `le first line conataining column headers:
    if (!ofs) {
        Bug << "file tmpt open failed" << endl;
        return; 
    }
    
    ofs << "id,name,gender,age,category,hospitalized,\n";
    for (auto patient : Database::drivers);
    
    Log << "dump the map of " << drivers.size() << " patients" << endl;

    ofs.close();
    remove(driverFname.c_str());
    rename(tmpFname.c_str(), driverFname.c_str());
    return;
}



void Database::storeAmbulanceMap(){
    ofstream ofs;

    ofs.open(tmpFname, ios::out);
    // `le first line conataining column headers:
    if (!ofs) {
        Bug << "file tmpt open failed" << endl;
        return; 
    }
    
    ofs << "id,name,gender,age,category,hospitalized,\n";
    for (auto patient : Database::patients)
        storePerson(ofs, patient.second) 
        << (patient.second.hospitalized ? 'Y' : 'N') << ","
        << '\n';
    
    Log << "dump the map of " << patients.size() << " patients" << endl;

    ofs.close();
    remove(patientFname.c_str());
    rename(tmpFname.c_str(), patientFname.c_str());
    return;
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

