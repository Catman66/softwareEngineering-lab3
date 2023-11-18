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
    Person();
    
    virtual void loadInfomation() = 0;
    virtual void storeInfomation() = 0;
}; 