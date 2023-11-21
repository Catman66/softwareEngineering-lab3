#include<Person.h>
#include<string>
#include <fstream>


using namespace std;

class Ambulance{
private:
    string registrationId;
    int driverId;
public:
    void loadInfomation();
    void storeInfomation();
    void showInfomation();
    ofstream& store(ofstream& ofs);

}; 