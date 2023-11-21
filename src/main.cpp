#include"Database.h"
#include <cassert>

enum Menu_t{ 
    MAIN_MENU, 
    PATIENT_MENU, 
    DOCTOR_MENU, 
    NURSE_MENU, 
    DRIVER_MENU, 
    AMBULANCE_MENU, 
    APPOINTMENT_MENU 
} ;


void intoMenu(Menu_t m);
void intoPatientMenu(){     
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
            default:
                break;
            }
            getline(cin, buffer, '\n');
        }
        cout << endl;
    }
}
void intoDoctorMenu(){
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

        if (choice == -1)        {
            break;
        }
        else {
            cout << "your choice: " << choice << endl; 
        }
        cout << endl;
    }
}
void intoNurseMenu(){
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
        }
        else {
            cout << "your choice: " << choice << endl; 
        }
        cout << endl;
    }
}
void intoDriverMenu(){
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
        }
        else {
            cout << "your choice: " << choice << endl; 
        }
        cout << endl;
    }
}
void intoAmbulanceMenu(){
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
        }
        else {
            cout << "your choice: " << choice << endl; 
        }
        cout << endl;
    }

}
void intoAppointmentMenu(){
    while(1){
        int choice = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect a choice:\n\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        
        cout << "[1] : new appointment\n";
        cout << "[2] : show history appointments\n";
        cout << "[3] : recomend a doctor\n";
        cout << "[-1] : EXIT\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n";

        if (choice == -1)        {
            break;
        }
        else {
            cout << "your choice: " << choice << endl; 
        }
        cout << endl;
    }
}
void intoMainMenu(){
    while(1){
        int choice = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect a choice:\n\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[" << PATIENT_MENU << "] : PATIENT\n";
        cout << "[" << DOCTOR_MENU << "] : DOCTOR\n";
        cout << "[" << NURSE_MENU << "] : NURSE\n";
        cout << "[" << DRIVER_MENU << "] : DRIVER\n";
        cout << "[" << AMBULANCE_MENU << "] : AMBULANCE\n";
        cout << "[" << APPOINTMENT_MENU << "] : APPOINTMENT\n";
        cout << "[0] : EXIT\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n";

        if (choice == 0)        {
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "\nShutting Down System...\n";
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            break;
        }
        else {
            intoMenu((Menu_t) choice);
        }
        cout << endl;
    }
        
}


void intoMenu(Menu_t m){
    switch (m) {
    case MAIN_MENU:
        intoMainMenu();
        break;
    case DOCTOR_MENU:
        intoDoctorMenu();
        break; 
    case PATIENT_MENU:
        intoPatientMenu();
        break; 
    case NURSE_MENU:
        intoNurseMenu();
        break; 
    case DRIVER_MENU:
        intoDriverMenu();
        break; 
    case AMBULANCE_MENU:
        intoAmbulanceMenu();
        break; 
    case APPOINTMENT_MENU:
        intoAppointmentMenu();
        break;
    default :
        cout << "\nInvalid Choice!\n";
    }
}

int main(){

    Database::loadMaps();
    
    intoMenu(MAIN_MENU);

    Database::storeMaps();
    return 0;
}



/* 

Patient
Doctor
Nurse
Driver
AmbulanceMe
Appointment

*/