#ifndef _PERSON_H_
#define _PERSON_H_

#include<string>
#include<fstream>
using namespace std;
class Database;

class Person{
public:
    static const int Patient_c = 0;
    static const int Doctor_c = 1;
    static const int Nurse_c = 2;
    static const int Driver_c = 3;
protected:
    int id;
    string name;
    char gender;
    int16_t age;
    int category;           //category: 0:patient; 1:doctor; 2:nurse; 3:driver;
    
    friend class Database;
public:
    // virtual function all set to zero 
    // no constructor, no destructor
    virtual void showInfomation() = 0;
    virtual int registeInfomation() = 0;
    virtual ofstream& store(ofstream& ofs) = 0;

    // return : 1=succ, 0=fail, 
    int registerPersonGetId();
    void showPersonInfo();
    ofstream& storePerson(ofstream& fs);
}; 

#endif