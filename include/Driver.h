#ifndef _DRIVER_H_
#define _DRIVER_H_


#include<Person.h>

using namespace std;

class Driver: public Person{
    friend class Database;

public:
    Driver() {}
    ~Driver() {}
    void showInfomation();

    int registeInfomation();
    virtual ofstream& store(ofstream& ofs) = 0;
}; 


#endif