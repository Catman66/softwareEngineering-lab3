#include"Doctor.h"
#include"Database.h"

void Doctor::showInfomation(){
    // ask the database to get the infomation
    showPersonInfo();
    cout << "Available time: " << timeAvailable << '\n'
    << "booked: " << (booked ? 'Y' : 'N')
    << endl;
}

int Doctor::registeInfomation()
{
    int result = registerPersonInfo();

    category = Database::getNewId();
    
    cout << " available time" << endl;
    cin >> timeAvailable;

    booked = false;
    return result;
}
