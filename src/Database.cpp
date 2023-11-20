#include "Database.h"

#include <fstream>
#include <sstream>
using namespace std;

map<int, Patient> Database::patients;
map<int, Driver> Database::drivers;
map<int, Doctor> Database::doctors;
map<int, Nurse> Database::nurses;
map<int, Ambulance> Database::ambulances;

void Database::loadMaps(){ 
    loadPatientMap();
    loadDoctorMap();
    loadNurseMap();
    loadDriverMap();
    loadAmbulanceMap();
    loadAppointmentMap();
}
void Database::storeMaps(){
    storePatientMap();
    storeDoctorMap();
    storeNurseMap();
    storeDriverMap();
    storeAmbulanceMap();
}
void Database::storePatientMap(){
    ofstream ofs;
    ofs.open("./data/temp.csv", ios::out);
    // `le first line conataining column headers:
    
    ofs << "id,name,gender,age,category,hospitalized,\n";
    for (auto i : Database::patients)
        ofs << i.second.id << "," 
        << i.second.name << "," 
        << i.second.gender << "," 
        << i.second.age << "," 
        << (i.second.hospitalized ? 'Y' : 'N') << ","
        << '\n';
    ofs.close();
    remove("./data/patients.csv");
    rename("./data/temp.csv", "./data/patients.csv");
    return;
}
void Database::storeDoctorMap(){ cout << "not implemented " << endl; }
void Database::storeNurseMap(){ cout << "not implemented " << endl; }
void Database::storeDriverMap(){ cout << "not implemented " << endl; }
void Database::storeAmbulanceMap(){ cout << "not implemented " << endl; }
int Database::getNewId()
{
    return patients.size() + doctors.size() + nurses.size() + drivers.size();
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
    string fname = "data/Patient.csv";
    ifstream f;
    f.open(fname, ios::in);
    if(!f){
        cout << "opening file" << fname << endl;
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

void Database::loadDoctorMap(){ }
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