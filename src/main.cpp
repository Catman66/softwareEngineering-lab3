#include"Database.h"
#include <cassert>

enum Menu_t{ 
    MAIN_MENU, 
    PATIENT_MENU, 
    DOCTOR_MENU, 
    NURSE_MENU, 
    DRIVER_MENU, 
    AMBULANCE_MENU, 
    APPOINTMENT_MENU,
    HELP_MENU,
    FEEDBACK_MENU
} ;

void intoMenu(Menu_t m);

void helpMenu(){
    cout << "\n======the direction of the system======\n"
     << "[main menu] \n"
     << "   ->[patient menu]\n"
     << "       ->[register a new patient]\n"
     << "       ->[show patient infomation]\n"
     << "       ->[remove patient infomation]\n"
     << "   ->[doctor menu]\n"
     << "       ->[register a new doctor]\n"
     << "       ->[show doctor infomation]\n"
     << "       ->[remove doctor infomation]\n"
     << "   ->[nurse menu]\n"
     << "       ->[register a new nurse]\n"
     << "       ->[show nurse infomation]\n"
     << "       ->[remove nurse infomation]\n"
     << "   ->[driver menu]\n"
     << "       ->[register a new driver]\n"
     << "       ->[show driver infomation]\n"
     << "       ->[remove driver infomation]\n"
     << "   ->[ambulance menu]\n"
     << "       ->[register a new ambulance]\n"
     << "       ->[show ambulance infomation]\n"
     << "       ->[remove ambulance infomation]\n"
     << "   ->[appointment menu]\n"
     << "       ->[book a new appointment]"
     << "       ->[show history appointment infomation]\n"
     << "       ->[recomend appintment infomation]\n"
     << "   ->[feedback menu]\n"
     << " ================================================"
     << endl;
}
void feedbackMenu(){
    cout << "please input your feedback "<< endl;
    cout << "input \"@@@@@\" to submit "<< endl;
    string feedback;
    string buffer;
    while(1){
        getline(cin, buffer);
        feedback += buffer + '\n';
        if (buffer.find("@@@@@") != string::npos) break;
    }
    Database::addFeedback(feedback);
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
        cout << "[" << HELP_MENU << "] : HELP\n";
        cout << "[" << FEEDBACK_MENU << "] : FEEDBACK\n";
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
    case HELP_MENU:
        helpMenu();
        break;
    case FEEDBACK_MENU:
        feedbackMenu();
        break;
    default :
        cout << "\nInvalid Choice!\n";
    }
}

int parseDate(string& date){
    // expected date in format: yyyy-mm-dd
    int yyyy, mm, dd;
    if (date.size() != 10) {
        return -1;
    }
    try {
        yyyy = stoi(date.substr(0, 4));
        mm = stoi(date.substr(5, 2));
        dd = stoi(date.substr(8, 2));
    } catch (const invalid_argument& err){
        return -1;
    }

    return (yyyy<<4) + (mm << 2) + dd;
}

int main(){
    string date;
    while (1) {
        cout << "please input the date(format yyyy-mm-dd)  \n" << endl;
        cin >> date;

        int parsed = parseDate(date);
        if (parsed > 0) {
            Database::date = parsed;
            break;
        }
    }
    
    
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