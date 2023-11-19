#include<Person.h>
#include<string>

using namespace std;

class Ambulance{
private:
    string registrationId;
    int driverId;
public:
    void loadInfomation();
    void storeInfomation();
    void showInfomation();
}; 