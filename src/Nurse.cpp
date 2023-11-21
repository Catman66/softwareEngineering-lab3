#include"Nurse.h"
#include"Database.h"

void Nurse::showInfomation(){
    // ask the database to get the infomation
    Person::showPersonInfo();
}

int Nurse::registeInfomation()
{
    int result = registerPersonGetId();

    category = Person::Nurse_c;
    
    int id = Database::getNewId();
    Database::nurses.insert_or_assign(id, *this);
    return result;
}

ofstream &Nurse::store(ofstream &ofs)
{
    return storePerson(ofs);
}



void Nurse::menu(){
    while(1){
        int choice = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect a choice:\n\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        
        cout << "[1] : register a new nurse\n";
        cout << "[2] : show nurse infomation\n";
        cout << "[3] : remove nurse infomation\n";
        cout << "[-1] : EXIT\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n";

        if (choice == -1)        {
            break;
        } else if (choice == 1) {
            Nurse p;
            while(1){
                int id = p.registeInfomation();
                if (id == -1)   break;
                else if (id >= 1) {
                    cout << "register succeed, id allocted: " << id << endl;
                    break;
                }
            } 
            
            break;
        } else if (choice == 2 || choice == 3) {
            int id;
            
            cout << "please input doctor id, intput -1 to exit" << endl;
            while (1){
                cin >> id;
                if (id == -1) {
                    break;
                }                
                
                Nurse* d = Database::lookupNurse(id);
                if (d == nullptr) {
                    cout << "invalid id, please check you input" << endl;
                    continue;
                } 

                if (choice == 2) {
                    d->showInfomation();
                } else {
                    Database::nurses.erase(id);
                    cout << "remove success" << endl;
                }
            }
        } else {
            cout << "invalid choice: " << choice << endl; 
        }
        cout << endl;
    }
}