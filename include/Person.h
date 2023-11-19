#ifndef _PERSON_H_
#define _PERSON_H_

#include<string>
using namespace std;

class Person{
protected:
    int id;
    string Name;
    char gender;
    int16_t age;
    int category;           //category: 1:doctor; 2:patient; 3:nurse; 4:driver;

public:
    Person() {}
    
    virtual void showInfomation() = 0;
    void showPersonInfo();
}; 

#endif