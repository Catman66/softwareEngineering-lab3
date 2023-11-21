#ifndef _DRIVER_H_
#define _DRIVER_H_


#include<Person.h>
#include<list>

using namespace std;

class Driver: public Person{
    friend class Database;

public:
    Driver() {}
    ~Driver() {}
    void showInfomation();

    int registeInfomation();
    ofstream& store(ofstream& ofs);
}; 


#endif