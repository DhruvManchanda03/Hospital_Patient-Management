#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// -------------------- Data Structures --------------------

struct Patient {
    int id;
    string name;
    int age;
    string gender;
    string contact;
    vector<string> history; // medical notes
};

struct Doctor {
    int id;
    string name;
    string specialization;
    vector<string> schedule; // booked time slots
};

struct Appointment {
    int patientID;
    int doctorID;
    string date;
    string time;
    int urgency; // lower value = higher priority
};

// For priority queue (urgency)
struct CompareUrgency {
    bool operator()(Appointment const& a, Appointment const& b) {
        return a.urgency > b.urgency; // min-heap (smallest urgency first)3
    }
};

// -------------------- Global Storage --------------------
map<int, Patient> patients;
map<int, Doctor> doctors;
priority_queue<Appointment, vector<Appointment>, CompareUrgency> appointmentQueue;

int patientCounter = 100;
int doctorCounter = 500;

// -------------------- Functions --------------------

// Register a new patient
void registerPatient() {
    Patient p;
    p.id = ++patientCounter;
    cout << "Enter Name: ";
    cin >> ws;
    getline(cin, p.name);
    cout << "Enter Age: ";
    cin >> p.age;
    cout << "Enter Gender: ";
    cin >> p.gender;
    cout << "Enter Contact: ";
    cin >> p.contact;

    patients[p.id] = p;
    cout << "Patient registered successfully! ID = " << p.id << endl;
}

// Add a new doctor
void addDoctor() {
    Doctor d;
    d.id = ++doctorCounter;
    cout << "Enter Doctor Name: ";
    cin >> ws;
    getline(cin, d.name);
    cout << "Enter Specialization: ";
    cin >> d.specialization;

    doctors[d.id] = d;
    cout << "Doctor added successfully! ID = " << d.id << endl;
}

// Book an appointment
void bookAppointment() {
    int pid, did, urgency;
    string date, time;

    cout << "Enter Patient ID: ";
    cin >> pid;
    if (patients.find(pid) == patients.end()) {
        cout << "Invalid Patient ID!" << endl;
        return;
    }

    cout << "Enter Doctor ID: ";
    cin >> did;
    if (doctors.find(did) == doctors.end()) {
        cout << "Invalid Doctor ID!" << endl;
        return;
    }

    cout << "Enter Date (dd-mm-yyyy): ";
    cin >> date;
    cout << "Enter Time (hh:mm): ";
    cin >> time;
    cout << "Enter Urgency Level (1=High, 5=Low): ";
    cin >> urgency;

    // Check if time slot already booked1
    for (auto &t : doctors[did].schedule) {
        if (t == time) {
            cout << "This time slot is already booked!" << endl;
            return;
        }
    }

    Appointment appt = {pid, did, date, time, urgency};
    appointmentQueue.push(appt);
    doctors[did].schedule.push_back(time);

    cout << "Appointment booked successfully!" << endl;
}

// Process next appointment (doctor consultation)
void processAppointment() {
    if (appointmentQueue.empty()) {
        cout << "No appointments scheduled!" << endl;
        return;
    }

    Appointment appt = appointmentQueue.top();
    appointmentQueue.pop();

    cout << "\n--- Next Appointment ---" << endl;
    cout << "Patient: " << patients[appt.patientID].name
         << " (ID: " << appt.patientID << ")" << endl;
    cout << "Doctor: " << doctors[appt.doctorID].name
         << " (" << doctors[appt.doctorID].specialization << ")" << endl;
    cout << "Date: " << appt.date << "  Time: " << appt.time << endl;

    cout << "Enter consultation notes: ";
    string notes;
    cin >> ws;
    getline(cin, notes);
    patients[appt.patientID].history.push_back(notes);

    cout << "Consultation completed and notes added!" << endl;
}

// View patient history
void viewPatientHistory() {
    int pid;
    cout << "Enter Patient ID: ";
    cin >> pid;

    if (patients.find(pid) == patients.end()) {
        cout << "Invalid Patient ID!" << endl;
        return;
    }

    Patient &p = patients[pid];
    cout << "\n--- Patient History ---" << endl;
    cout << "Name: " << p.name << ", Age: " << p.age
         << ", Gender: " << p.gender << endl;
    cout << "Contact: " << p.contact << endl;

    if (p.history.empty()) {
        cout << "No history available." << endl;
    } else {
        for (size_t i = 0; i < p.history.size(); i++) {
            cout << "Visit " << i + 1 << ": " << p.history[i] << endl;
        }
    }
}

// -------------------- Main --------------------
int main() {
    int choice;
    while (true) {
        cout << "\n===== Hospital Patient Management System =====" << endl;
        cout << "1. Register Patient" << endl;
        cout << "2. Add Doctor" << endl;
        cout << "3. Book Appointment" << endl;
        cout << "4. Process Next Appointment" << endl;
        cout << "5. View Patient History" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerPatient(); break;
            case 2: addDoctor(); break;
            case 3: bookAppointment(); break;
            case 4: processAppointment(); break;
            case 5: viewPatientHistory(); break;
            case 6: cout << "Exiting... Goodbye!" << endl; return 0;
            default: cout << "Invalid choice!" << endl;
        }
    }
}
