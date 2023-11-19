#include"Person.h"
#include"Database.h"


void Person::showPersonInfo(){
    cout << "id: "            <<  id        << '\n'
        << "Name: "          <<  Name       << '\n'
        << "gender: "        <<  gender     << '\n'
        << "age: "           <<  age        << '\n'
        << "category: "      <<  category   << '\n';      //category: 1:doctor; 2:patient; 3:nurse; 4:driver;
}
