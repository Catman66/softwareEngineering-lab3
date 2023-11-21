#include"Person.h"
#include"Database.h"


void Person::showPersonInfo(){
    cout << "id: "            <<  id        << '\n'
        << "name: "          <<  name       << '\n'
        << "gender: "        <<  gender     << '\n'
        << "age: "           <<  age        << '\n'
        << "category: "      <<  category   << '\n';      //category: 1:doctor; 2:patient; 3:nurse; 4:driver;
}

ofstream& Person::storePerson(ofstream& ofs){
    ofs << id << ',' 
        << name << ',' 
        << gender << ',' 
        << age << ',' 
        << category << ",";
    return ofs;
}


int Person::registerPersonGetId(){
    cout << "input name: " << endl;
    cin >> name;
    
    cout << "input gender: (m/w)" << endl;
    cin >> gender;
    
    cout << " input age: "<< endl;
    cin >> age;

    id = Database::getNewId();

    return id;
}