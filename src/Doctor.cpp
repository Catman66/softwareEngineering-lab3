#include"Doctor.h"
#include"Database.h"


using namespace std;


void Doctor::showInfomation(){
    // ask the database to get the infomation
    showPersonInfo();
    cout << "Available time: " << timeAvailable << '\n'
    << "booked: " << (booked ? 'Y' : 'N')
    << endl;
}

int Doctor::registeInfomation()
{
    int result = registerPersonGetId();

    category = Database::getNewId();
    
    cout << " available time" << endl;
    cin >> timeAvailable;

    booked = false;
    int id = Database::getNewId();
    Database::doctors.insert_or_assign(id, *this);
    return result;
}

ofstream &Doctor::store(ofstream &ofs)
{
    storePerson(ofs) << timeAvailable << ','
    << (booked ? 'Y' : 'N')
    << '\n'; 

    return ofs;
}

void Doctor::menu(){
    while(1){
        int choice = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect a choice:\n\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        
        cout << "[1] : register a new doctor\n";
        cout << "[2] : show doctor infomation\n";
        cout << "[3] : remove doctor infomation\n";
        cout << "[-1] : EXIT\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n";

        if (choice == -1) {
            break;
        } else if (choice == 1) {
            Doctor p;
            while(1){
                int id = p.registeInfomation();
                if (id == -1)   break;
                else if (id >= 1) {
                    cout << "register succeed, id allocted: " << id << endl;
                    break;
                }
            } 
            
            break;
        } else if (choice == 2 || choice == 3){
            int id;
            
            cout << "please input doctor id, intput -1 to exit" << endl;
            while (1){
                cin >> id;
                if (id == -1) {
                    break;
                }                
                
                Doctor* d = Database::lookupDoctor(id);
                if (d == nullptr) {
                    cout << "invalid id, please check you input" << endl;
                    continue;
                } 

                if (choice == 2) {
                    d->showInfomation();
                } else {
                    Database::doctors.erase(id);
                    cout << "remove success" << endl;
                }
            }
        } else {
            cout << "invalid choice: " << choice << endl; 
        }
        cout << endl;
    }
}