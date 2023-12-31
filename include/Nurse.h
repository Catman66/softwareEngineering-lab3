#ifndef _NURSE_H_
#define _NURSE_H_

#include<Person.h>
using namespace std;

class Nurse: public Person {
    friend class Database;

public:
    Nurse() {}
    ~Nurse() {}
    void loadInfomation();
    void storeInfomation();
    void showInfomation();

    int registeInfomation();
    ofstream& store(ofstream& ofs);
    static void menu();
}; 


#endif