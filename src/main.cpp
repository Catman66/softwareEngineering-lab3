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
        cout << "[3] : EXIT\n";
        cout << "[4] : EXIT\n";
        cout << "[-1] : EXIT\n";
        cout << "[-1] : EXIT\n";
        cout << "[-1] : EXIT\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n";

        if (choice == -1)        {
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
void intoDoctorMenu(){      cout << "this is " << "Doctor"      << "menu" << endl;}
void intoNurseMenu(){       cout << "this is " << "Nurse"       << "menu" << endl;}
void intoDriverMenu(){      cout << "this is " << "Driver"      << "menu" << endl;}
void intoAmbulanceMenu(){   cout << "this is " << "AmbulanceMe" << "menu" << endl;}
void intoAppointmentMenu(){ cout << "this is " << "Appointment" << "menu" << endl;}
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
        cout << "[-1] : EXIT\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n";

        if (choice == -1)        {
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