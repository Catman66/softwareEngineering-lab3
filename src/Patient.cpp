#include"Patient.h"
#include"Database.h"

void Patient::showInfomation(){
    // ask the database to get the infomation
    cout << "====== show patient infomation ======";
    Person::showPersonInfo();
    cout << (hospitalized ? "hospitalized" : "not hospitalized") << endl;
}



void Patient::hospitalize(){
    if (this->hospitalized){
        cout << "already hospitalized" << endl;
        return;
    }
    
    this->hospitalized = true;
}

int Patient::registeInfomation(){
    int result = registerPersonGetId();

    category = Person::Patient_c;
    hospitalized = false;
    Database::patients.insert_or_assign(id, *this);
    return id;
}

ofstream &Patient::store(ofstream &ofs)
{
    storePerson(ofs) << (hospitalized ? 'Y' : 'N') << ','
    << '\n';
    return ofs;
}


void Patient::menu(){     
    while(1){
        int choice = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect a choice:\n\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        
        cout << "[1] : register a new patient\n";
        cout << "[2] : show patient infomation\n";
        cout << "[3] : hospitalize\n";
        cout << "[4] : appointment infomation\n";
        cout << "[-1] : EXIT\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n";

        if (choice == -1)        {
            break;
        } else if (choice == 1) {
            Patient p;
            while(1){
                int id = p.registeInfomation();
                if (id == -1)   break;
                else if (id >= 1) {
                    cout << "register succeed, id allocted: " << id << endl;
                    break;
                }
            } 
            
            break;
        } else if (choice == 2 || choice == 3 || choice == 4) {
            string buffer;
            int id;

        INPUT:
            cout << "please input patient id, intput -1 to exit" << endl;
            cin >> buffer;
            try {
                id = stoi(buffer);
            }
            catch(const invalid_argument& e) {
                goto INPUT;
            }
            if (id == -1) continue;
            
            
            Patient* p = Database::lookupPatient(id);
            if (p == NULL) {
                cout << "patient not found" << endl;
                goto INPUT;
            }
            switch (choice)
            {
            case 2:
                p->showInfomation();
                break;
            case 3:
                p->hospitalize();
                break;
            case 4:
                Database::showAppointmentsOf(p->id);
                break;
            default:
                break;
            }
            getline(cin, buffer, '\n');
        } 
        cout << endl;
    }
}