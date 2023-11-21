#include "Ambulance.h"
#include <iostream>
#include<Database.h>


void Ambulance::showInfomation(){
    cout << "id: "      << id               << '\n'
    << "registrationId" << registrationId   << '\n'
    << "driverId: "     << driverId         << '\n'
    << endl;
}

ofstream &Ambulance::store(ofstream &ofs)
{
    ofs << registrationId << ','
    << driverId << ','
    << '\n';
    return ofs;
}

int Ambulance::registerInfomation(){
    Ambulance newAmb;
    int regId;
    int drId;
    
    cout << "input registration id" << endl;
    cin >> regId;

    cout << "input driver id" << endl;
    cin >> drId;
    
    registrationId = regId;
    driverId = drId;
    id = Database::getNewId();
    
    Database::ambulances.insert_or_assign(id, *this);
    return id;
}

void Ambulance::menu(){
    while(1){
        int choice = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect a choice:\n\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        
        cout << "[1] : register a new ambulance\n";
        cout << "[2] : show ambulance infomation\n";
        cout << "[3] : remove ambulance infomation\n";
        cout << "[4] : send out an ambulance\n";
        cout << "[-1] : EXIT\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n";

        if (choice == -1)        {
            break;
        } else if (choice == 1) {
            Ambulance amb;
            int id = amb.registerInfomation();
            cout << "register succeed: id: " << id << endl;

        } else if (choice == 2 || choice == 3) {
            int id;
            
            while (1){
                cout << "please input doctor id, intput -1 to exit" << endl;
                cin >> id;
                if (id == -1) {
                    break;
                }                
                
                Ambulance* d = Database::lookupAmbulance(id);
                if (d == nullptr) {
                    cout << "invalid id, please check you input" << endl;
                    continue;
                } 

                if (choice == 2) {
                    d->showInfomation();
                } else {
                    Database::ambulances.erase(id);
                    cout << "remove success" << endl;
                }
            }   
        } else {
            cout << "invalid choice: " << choice << endl; 
        }
        cout << endl;
    }

}