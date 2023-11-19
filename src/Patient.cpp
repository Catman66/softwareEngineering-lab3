#include"Patient.h"
#include"Database.h"

void Patient::showInfomation(){
    // ask the database to get the infomation
    Person::showPersonInfo();
    cout << (hospitalized ? "hospitalized" : "not hospitalized") << endl;
}

