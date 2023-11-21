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
        Doctor::menu();
        break; 
    case PATIENT_MENU:
        Patient::menu();
        break; 
    case NURSE_MENU:
        Nurse::menu();
        break; 
    case DRIVER_MENU:
        Driver::menu();
        break; 
    case AMBULANCE_MENU:
        Ambulance::menu();
        break; 
    case APPOINTMENT_MENU:
        Appointment::menu();
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