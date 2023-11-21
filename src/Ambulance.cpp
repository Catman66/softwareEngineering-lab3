#include "Ambulance.h"

ofstream &Ambulance::store(ofstream &ofs)
{
    ofs << registrationId << ','
    << driverId << ','
    << '\n';
    return ofs;
}
