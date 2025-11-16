# Hospital Patient Management System

A simple **console-based Hospital Patient Management System**, built in **C++**, that manages patients, doctors, appointments, and medical history. It demonstrates the use of data structures, OOP concepts, priority queues, and basic menu-driven interaction.

---

## 🚀 Features

### **1. Patient Management**

* Register new patients
* Auto-generated patient ID
* Store name, age, gender, contact, and medical history

### **2. Doctor Management**

* Add new doctors
* Auto-generated doctor ID
* Store doctor name and specialization

### **3. Appointment Booking**

* Book appointments between patient and doctor
* Includes date, time, and urgency level (1 = high priority)
* Prevents duplicate bookings for the same time slot
* Stores appointments in a **priority queue** (min-heap) to process urgent cases first

### **4. Appointment Processing**

* Retrieves the next appointment based on urgency
* Allows doctor to add consultation notes
* Automatically updates patient's medical history

### **5. Patient History Viewing**

* Display all recorded consultation notes
* Shows patient details and visit logs

---

## 🛠️ Technologies Used

* **C++17**
* STL Containers:

  * `map`
  * `vector`
  * `priority_queue`
* Custom structs for Patients, Doctors, and Appointments
* Custom comparator for urgency-based appointment sorting

---

## 📂 Project Structure

```
Hospital-Management/
│
├── main.cpp     # Full program code
└── README.md    # Project documentation
```

---

## 🔧 How It Works

### **1. Data Structures**

* **Patient**: ID, personal info, consultation history
* **Doctor**: ID, specialization, booked schedule
* **Appointment**: patient ID, doctor ID, date, time, urgency

### **2. Priority Queue for Appointments**

A custom comparator ensures that the smallest urgency value (highest priority) is processed first.

### **3. Schedule Checking**

Before booking, the system ensures no conflicting time slot already exists for a doctor.

---

## 📌 Example Menu

```
===== Hospital Patient Management System =====
1. Register Patient
2. Add Doctor
3. Book Appointment
4. Process Next Appointment
5. View Patient History
6. Exit
```

---

## ▶️ Compilation & Execution

### **Compile:**

```bash
g++ -std=c++17 -O2 -o hospital main.cpp
```

### **Run:**

```bash
./hospital
```

---

## ⚠️ Current Limitations

* Doctor schedule only tracks **time**, not date
* All data stored **in-memory** (lost on exit)
* No strong input validation
* Console-based, single-user interaction

---

## 🌟 Future Improvements

* Add file or database persistence (CSV / JSON / SQLite)
* Track full timestamps (`date + time`) for accurate scheduling
* Add appointment cancellation & rescheduling
* Web or GUI interface
* Improved error handling and validation
* Use `unordered_map` for faster lookups

---

## ✔️ Author

A simple C++ project built for learning **data structures**, **program flow**, and **management system design**.

If you'd like improvements, diagrams, or feature additions, feel free to ask!
