#include"Database.h"
#include <cassert>


enum Menu_t{ 
    MAIN_MENU, 
    DOCTOR_MENU, 
    PATIENT_MENU, 
    NURSE_MENU, 
    DRIVER_MENU, 
    AMBULANCE_MENU, 
    APPOINTMENT_MENU 
} ;


void intoMainMenu(){
    int category = 0;
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\nSelect a category:\n\n";

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "./HOME\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "[01] : APPOINTMENTS\n";
    cout << "[02] : PATIENTS\n";
    cout << "[03] : DOCTORS\n";
    cout << "[04] : NURSES\n";
    cout << "[05] : DRIVERS\n";
    cout << "[06] : AMBULANCES\n\n";
    cout << "[-1] : EXIT\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "Enter your choice: ";
    cin >> category;
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\n";
    

    int category = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect a category:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : APPOINTMENTS\n";
        cout << "[02] : PATIENTS\n";
        cout << "[03] : DOCTORS\n";
        cout << "[04] : NURSES\n";
        cout << "[05] : DRIVERS\n";
        cout << "[06] : AMBULANCES\n\n";
        cout << "[-1] : EXIT\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> category;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n";
        if (category == -1)
        {
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "\nShutting Down System...\n";
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            break;
        }
        else if (category == 1)
        {
            appointmentsMenu();
        }
        else if (category == 2)
        {
            patientsMenu();
        }
        else if (category == 3)
        {
            doctorsMenu();
        }
        else if (category == 4)
        {
            nursesMenu();
        }
        else if (category == 5)
        {
            driversMenu();
        }
        else if (category == 6)
        {
            ambulancesMenu();
        }
        else
        {
            cout << "\nInvalid Choice!\n";
        }

        cout << endl;
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
        intoDirverMenu();
        break; 
    case AMBULANCE_MENU:
        intoAmbulanceMenu();
        break; 
    case APPOINTMENT_MENU:
        intoAppointmentMenu();
        break;
    default :
        assert(0);
    }
}

int main(){

    Database::loadMaps();
    
    intoMenu(MAIN_MENU);

    Database::storeMaps();
    return 0;
}