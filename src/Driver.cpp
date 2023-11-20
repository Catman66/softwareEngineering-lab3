#include"Driver.h"
#include"Database.h"

void Driver::showInfomation(){
    // ask the database to get the infomation
    Person::showPersonInfo();
}

int Driver::registeInfomation()
{
    int result = registerPersonInfo();
    category = Person::Driver_c;
    
    return result;
}
