#include"Doctor.h"
#include"Database.h"


using namespace std;


void Doctor::showInfomation(){
    // ask the database to get the infomation
    showPersonInfo();
    cout << "Available time: " << timeAvailable << '\n'
    << "booked: " << (booked ? 'Y' : 'N')
    << endl;
}

int Doctor::registeInfomation()
{
    int result = registerPersonGetId();

    category = Database::getNewId();
    
    cout << " available time" << endl;
    cin >> timeAvailable;

    booked = false;
    return result;
}

ofstream &Doctor::store(ofstream &ofs)
{
    storePerson(ofs) << timeAvailable << ','
    << (booked ? 'Y' : 'N')
    << '\n'; 

    return ofs;
}
