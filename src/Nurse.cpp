#include"Nurse.h"
#include"Database.h"

void Nurse::showInfomation(){
    // ask the database to get the infomation
    Person::showPersonInfo();
}

int Nurse::registeInfomation()
{
    int result = registerPersonGetId();

    category = Person::Nurse_c;
    

    return result;
}
