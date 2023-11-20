#include"Patient.h"
#include"Database.h"

void Patient::showInfomation(){
    // ask the database to get the infomation
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
    int result = registerPersonInfo();
    if(result != 1){
        return result;
    }
    hospitalized = false;
    Database::patients.insert_or_assign(id, *this);
    return result;
}