
fnames = [
    'Patient',
    'Doctor',
    'Nurse',
    'Driver',
    'AmbulanceMe',
    'Appointment',
]

for f in fnames:
    open('data/' + f + '.csv', 'w+')