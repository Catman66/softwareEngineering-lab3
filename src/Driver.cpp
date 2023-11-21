#include"Driver.h"
#include"Database.h"

void Driver::showInfomation(){
    // ask the database to get the infomation
    Person::showPersonInfo();
}

int Driver::registeInfomation()
{
    int result = registerPersonGetId();
    category = Person::Driver_c;
    
    int id = Database::getNewId();
    Database::drivers.insert_or_assign(id, *this);
    return result;
}

ofstream &Driver::store(ofstream &ofs)
{
    return storePerson(ofs);
}



void Driver::menu(){
    while(1){
        int choice = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect a choice:\n\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        
        cout << "[1] : register a new driver\n";
        cout << "[2] : show driver infomation\n";
        cout << "[3] : remove driver infomation\n";
        cout << "[-1] : EXIT\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n";

        if (choice == -1)        {
            break;
        } else if (choice == 1) {
            Driver p;
            while(1){
                int id = p.registeInfomation();
                if (id == -1)   break;
                else if (id >= 1) {
                    cout << "register succeed, id allocted: " << id << endl;
                    break;
                }
            } 
            
            break;
        }else if (choice == 2 || choice == 3) {
            int id;
            
            cout << "please input doctor id, intput -1 to exit" << endl;
            while (1){
                cin >> id;
                if (id == -1) {
                    break;
                }                
                
                Driver* d = Database::lookupDriver(id);
                if (d == nullptr) {
                    cout << "invalid id, please check you input" << endl;
                    continue;
                } 

                if (choice == 2) {
                    d->showInfomation();
                } else {
                    Database::drivers.erase(id);
                    cout << "remove success" << endl;
                }
            }
        } else {
            cout << "invalid choice: " << choice << endl; 
        }
        cout << endl;
    }
}