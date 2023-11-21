#ifndef _AMBULANCE_H_
#define _AMBULANCE_H_

#include<Person.h>
#include<string>
#include <fstream>


using namespace std;

class Ambulance{
    friend class Database;
private:
    int id;
    string registrationId;
    int driverId;


public:
    void showInfomation();
    ofstream& store(ofstream& ofs);
    int registerInfomation();
    static void menu();

}; 

#endif