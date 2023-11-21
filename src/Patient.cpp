#include"Patient.h"
#include"Database.h"

void Patient::showInfomation(){
    // ask the database to get the infomation
    cout << "====== show patient infomation ======";
    Person::showPersonInfo();
    cout << (hospitalized ? "hospitalized" : "not hospitalized") << endl;
}



void Patient::hospitalize(){
    if (this->hospitalized){
        cout << "already hospitalized" << endl;
        return;
    }
    
    this->hospitalized = true;
}

int Patient::registeInfomation(){
    int result = registerPersonGetId();

    category = Person::Patient_c;
    hospitalized = false;
    Database::patients.insert_or_assign(id, *this);
    return id;
}