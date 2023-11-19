

class Appointment{
    int id;
    int patientId;
    int doctorId;
    int date, hour;

public:
    Appointment(int id, int patientId, int doctorId, int date, int hour);
    ~Appointment();
    void showInfomation();
} ;