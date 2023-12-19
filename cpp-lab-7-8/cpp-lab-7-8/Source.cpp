#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Vehicle {
private:
    char* vehiclebrand;
    int mileage;
    int releaseyear;
    int stateregistrationnumber;
    char* status;
public:
    Vehicle() {
        vehiclebrand = nullptr;
        mileage = 0;
        releaseyear = 0;
        stateregistrationnumber = 0;
        status = nullptr;

    }
    Vehicle(const char* vehiclebrandValue, int mileageValue, int releaseyearValue, int stateregistrationnumberValue, const char* statusValue) {
        vehiclebrand = new char[strlen(vehiclebrandValue) + 1];
        strcpy(vehiclebrand, vehiclebrandValue);
        mileage = mileageValue;
        releaseyear = releaseyearValue;
        stateregistrationnumber = stateregistrationnumberValue;
        status = new char[strlen(statusValue) + 1];
        strcpy(status, statusValue);

    }
    Vehicle(Vehicle const& other) {
        vehiclebrand = new char[strlen(other.vehiclebrand) + 1];
        strcpy(vehiclebrand, other.vehiclebrand);
        mileage = other.mileage;
        releaseyear = other.releaseyear;
        stateregistrationnumber = other.stateregistrationnumber;
        status = new char[strlen(other.status) + 1];
        strcpy(status, other.status);
    }
    ~Vehicle() {
        delete[] vehiclebrand;
        delete[] status;
    }


    void printvehiclebrand() {
        cout << "The brand of the car: " << vehiclebrand << endl;
    }
    void printmileage() {
        cout << "Mileage: " << mileage << endl;
    }
    void printreleaseyear() {
        cout << "Year of release: " << releaseyear << endl;
    }
    void printstateregistrationnumber() {
        cout << "State registration number: " << stateregistrationnumber << endl;
    }
    void printstatus() {
        cout << "Registration status in the salon: " << status << endl;
    }
    void printAll() {
        cout << "The brand of the car: " << vehiclebrand << endl;
        cout << "Mileage: " << mileage << endl;
        cout << "Year of release: " << releaseyear << endl;
        cout << "State registration number: " << stateregistrationnumber << endl;
        cout << "Registration status in the salon: " << status << endl;
       
    }

    void setvehiclebrand(const char* vehiclebrandValue) {
        delete[] vehiclebrand;
        vehiclebrand = new char[strlen(vehiclebrandValue) + 1];
        strcpy(vehiclebrand, vehiclebrandValue);
    }
    void setmileage(int mileageValue) {
        mileage = mileageValue;
    }
    void setreleaseyear(int releaseyearValue) {
        releaseyear = releaseyearValue;
    }
    void setstateregistrationnumber(int stateregistrationnumberValue) {
        stateregistrationnumber = stateregistrationnumberValue;
    }
    void setstatus(const char* statusValue) {
        delete[] status;
        status = new char[strlen(statusValue) + 1];
        strcpy(status, statusValue);
    }
   
    void setAll(const char* vehiclebrandValue, int mileageValue, int releaseyearValue, int stateregistrationnumberValue, const char* statusValue) {
        delete[] vehiclebrand;
        vehiclebrand = new char[strlen(vehiclebrandValue) + 1];
        strcpy(vehiclebrand, vehiclebrandValue);
        mileage = mileageValue;
        releaseyear = releaseyearValue;
        stateregistrationnumber = stateregistrationnumberValue;
        delete[] status;
        status = new char[strlen(statusValue) + 1];
        strcpy(status, statusValue);

    }
    void getAllFile()const {
        ofstream file;
        file.open("1.txt", ios_base::app);
        file << "The brand of the car: " << vehiclebrand << endl;
        file << "Mileage: " << mileage << endl;
        file << "Year of release: " << releaseyear << endl;
        file << "State registration number:" << stateregistrationnumber << endl;
        file << "Registration status in the salon: " << status << endl;
        file.close();
    }
    
    bool equals(const char* one, const char* two) {
        int i = 0;
        while (true) {
            if (one[i] != two[i]) {
                return false;
            }
            if (one[i] == '\0') {
                return true;
            }
            i++;
        }
    }

    virtual void registration(const char* statusValue) {
        char status[] = "Regular";
        if (equals(status, statusValue)) {
            this->setstatus("Regular");
            cout << "We are glad to welcome you again! ";
        }
        else {
            this->setstatus("Registration completed successfully");
            cout << "Registration completed successfully" << endl;
        }
    }
    virtual void registrationfile(const char* statusValue) {
        ofstream file;
        file.open("1.txt", ios_base::app); 
        char status[] = "Regular";
        if (equals(status, statusValue)) {
            this->setstatus("Regular client");
            file << "We are glad to welcome you again! ";
        }
        else {
            this->setstatus("Registration completed successfully");
            file << "Registration completed successfully" << endl;
        }
        file.close();
    }
    virtual void rentprice(const char* statusValue, int timeValue) {
        char status[] = "Regular";
        if (equals(statusValue, status)) {
            cout << "The cost of rent: " << (0 - 0 * 0.1) * timeValue << endl;
        }
        else {
            cout << "The cost of rent: " << setprecision(10) << 0 * timeValue << endl;
        }
        cout << "The vehicle was rented" << endl;
    }
    virtual void rentpriceFile(const char* statusValue, int timeValue) {
        ofstream file;
        file.open("1.txt", ios_base::app);
        char status[] = "Regular";
        if (equals(statusValue, status)) {
            file << "The cost of rent: " << (0 - 0 * 0.1) * timeValue << endl;
        }
        else {
            file << "The cost of rent: " << setprecision(10) << 0 * timeValue << endl;
        }
        file << "The vehicle was rented" << endl;
        file.close();
    }
  
};

class Passenger_car : public Vehicle {
public:
    void getAllFileCar() {
        ofstream file;//открываем файл для записи
        file.open("1.txt", ios_base::app);//параметр app необходим для записи в конец(чтобы предыдущие клиенты не стирались)
        file << "Passenger car" << endl;
        file.close();
        getAllFile();
    }
    void registration(const char* statusValue) {
        char status[] = "Regular";
        if (equals(status, statusValue)) {
            this->setstatus("Regular");
            cout << "We are glad to welcome you again! ";
        }
        else {
            this->setstatus("Registration completed successfully");
            cout << "Registration completed successfully" << endl;
        }
    }
    void registrationfile(const char* statusValue) {
        ofstream file;
        file.open("1.txt", ios_base::app);
        char status[] = "Regular";
        if (equals(status, statusValue)) {
            this->setstatus("Regular client");
            file << "We are glad to welcome you again! ";
        }
        else {
            this->setstatus("Registration completed successfully");
            file << "Registration completed successfully" << endl;
        }
        file.close();
    }
    void rentprice(const char* statusValue, int timeValue) {
        char status[] = "Regular";
        if (equals(statusValue, status)) {
            cout << "The cost of rent: " << (5000 - 5000 * 0.1) * timeValue << endl;
        }
        else {
            cout << "The cost of rent: " << setprecision(10) << 5000 * timeValue << endl;
        }
        cout << "The vehicle was rented" << endl;
    }
    void rentpriceFile(const char* statusValue, int timeValue) {
        ofstream file;
        file.open("1.txt", ios_base::app);
        char status[] = "Regular";
        if (equals(statusValue, status)) {
            file << "The cost of rent: " << (5000 - 5000 * 0.1) * timeValue << endl;
        }
        else {
            file << "The cost of rent: " << setprecision(10) << 5000 * timeValue << endl;
        }
        file << "The vehicle was rented" << endl;
        file.close();
    }
};

class Truck : public Vehicle {
public:
    void getAllFileTruck() {
        ofstream file;
        file.open("1.txt", ios_base::app);
        file << "Truck" << endl;
        file.close();
        getAllFile();
    }
    void registration(const char* statusValue) {
        char status[] = "Regular";
        if (equals(status, statusValue)) {
            this->setstatus("Regular");
            cout << "We are glad to welcome you again! ";
        }
        else {
            this->setstatus("Registration completed successfully");
            cout << "Registration completed successfully" << endl;
        }
    }
    void registrationfile(const char* statusValue) {
        ofstream file;
        file.open("1.txt", ios_base::app);
        char status[] = "Regular";
        if (equals(status, statusValue)) {
            this->setstatus("Regular client");
            file << "We are glad to welcome you again! ";
        }
        else {
            this->setstatus("Registration completed successfully");
            file << "Registration completed successfully" << endl;
        }
        file.close();
    }
    void rentprice(const char* statusValue, int timeValue) {
        char status[] = "Regular";
        if (equals(statusValue, status)) {
            cout << "The cost of rent: " << (10000 - 10000 * 0.1) * timeValue << endl;
        }
        else {
            cout << "The cost of rent: " << setprecision(10) << 10000 * timeValue << endl;
        }
        cout << "The vehicle was rented" << endl;
    }
    void rentpriceFile(const char* statusValue, int timeValue) {
        ofstream file;
        file.open("1.txt", ios_base::app);
        char status[] = "Regular";
        if (equals(statusValue, status)) {
            file << "The cost of rent: " << (10000 - 10000 * 0.1) * timeValue << endl;
        }
        else {
            file << "The cost of rent: " << setprecision(10) << 10000 * timeValue << endl;
        }
        file << "The vehicle was rented" << endl;
        file.close();
    }
};

class Motorcycle : public Vehicle {
public:
    void getAllFileMotorcycle() {
        ofstream file;
        file.open("1.txt", ios_base::app);
        file << "Motorcycle" << endl;
        file.close();
        getAllFile();
    }
    void registration(const char* statusValue) {
        char status[] = "Regular";
        if (equals(status, statusValue)) {
            this->setstatus("Regular");
            cout << "We are glad to welcome you again! ";
        }
        else {
            this->setstatus("Registration completed successfully");
            cout << "Registration completed successfully" << endl;
        }
    }
    void registrationfile(const char* statusValue) {
        ofstream file;
        file.open("1.txt", ios_base::app);
        char status[] = "Regular";
        if (equals(status, statusValue)) {
            this->setstatus("Regular client");
            file << "We are glad to welcome you again! ";
        }
        else {
            this->setstatus("Registration completed successfully");
            file << "Registration completed successfully" << endl;
        }
        file.close();
    }
    void rentprice(const char* statusValue, int timeValue) {
        char status[] = "Regular";
        if (equals(statusValue, status)) {
            cout << "The cost of rent: " << (5000 - 5000 * 0.1) * timeValue << endl;
        }
        else {
            cout << "The cost of rent: " << setprecision(10) << 5000 * timeValue << endl;
        }
        cout << "The vehicle was rented" << endl;
    }
    void rentpriceFile(const char* statusValue, int timeValue) {
        ofstream file;
        file.open("1.txt", ios_base::app);
        char status[] = "Regular";
        if (equals(statusValue, status)) {
            file << "The cost of rent: " << (5000 - 5000 * 0.1) * timeValue << endl;
        }
        else {
            file << "The cost of rent: " << setprecision(10) << 5000 * timeValue << endl;
        }
        file << "The vehicle was rented" << endl;
        file.close();
    }
};

class Customer {
private:
    char* name;
    char* surname;
    long long int number;
    char* status;
public:
    Customer() {
        char* name = nullptr;
        char* surname = nullptr;
        long long int number = 0;
        char* status = nullptr;
    }

    Customer(const char* nameValue, const char* surnameValue, long long int numberValue, const char* statusValue, const char* typeValue) {
        name = new char[strlen(nameValue) + 1];
        strcpy(name, nameValue);
        surname = new char[strlen(surnameValue) + 1];
        strcpy(surname, surnameValue);
        number = numberValue;
        status = new char[strlen(statusValue) + 1];
        strcpy(status, statusValue);
    }

    Customer(Customer const& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        surname = new char[strlen(other.surname) + 1];
        strcpy(surname, other.surname);
        number = other.number;
        status = new char[strlen(other.status) + 1];
        strcpy(status, other.status);
    }

    ~Customer() {
        delete[] name;
        delete[] surname;
        delete[] status;
    }

    void printname() {
        cout << "Name: " << name << endl;
    }
    void printsurname() {
        cout << "Surname: " << surname << endl;
    }
    void printnumber() {
        cout << "Phone number:" << number << endl;
    }
    void printstatus() {
        cout << "Registration status in the salon: " << status << endl;
    }
    void printAll()const {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Phone number:" << number << endl;
        cout << "Registration status in the salon: " << status << endl;
    }
    void getAllFile(int number)const {
        ofstream file;
        file.open("1.txt", ios_base::app);
        file << "Client №" << number << endl;
        file << "Name: " << name << endl;
        file << "Surname: " << surname << endl;
        file << "Phone number: " << number << endl;
        file << "Registration status in the salon: " << status << endl;
        file.close();
    }
    void setname(const char* nameValue) {
        delete[] name;
        name = new char[strlen(nameValue) + 1];
        strcpy(name, nameValue);
    }
    void setsurname(const char* surnameValue) {
        delete[] surname;
        surname = new char[strlen(surnameValue) + 1];
        strcpy(surname, surnameValue);
    }
    void setnumber(int numberValue) {
        number = numberValue;
    }
    void setstatus(const char* statusValue) {
        delete[] status;
        status = new char[strlen(statusValue) + 1];
        strcpy(status, statusValue);
    }
    void setAll(const char* nameValue, const char* surnameValue, int numberValue,const char*statusValue) {
        delete[] name;
        name = new char[strlen(nameValue) + 1];
        strcpy(name, nameValue);
        delete[] surname;
        surname = new char[strlen(surnameValue) + 1];
        strcpy(surname, surnameValue);
        number = numberValue;
        delete[] status;
        status = new char[strlen(statusValue) + 1];
        strcpy(status, statusValue);
    }

};

class MaintenanceRecord {
private:
    char* typeofservice = nullptr;
public:
    MaintenanceRecord() {
        typeofservice = nullptr;
    }
    MaintenanceRecord(const char* typeofserviceValue) {
        typeofservice = new char[strlen(typeofserviceValue) + 1];
        strcpy(typeofservice, typeofserviceValue);
    }
    MaintenanceRecord(MaintenanceRecord const& other) {
        typeofservice = new char[strlen(other.typeofservice) + 1];
        strcpy(typeofservice, other.typeofservice);
    }
    ~MaintenanceRecord() {
        delete[] typeofservice;
    }

    void printtypeofservice() {
        cout << "Type of service provided: " << typeofservice << endl;
    }
    void printAll() {
        cout << "Type of service provided: " << typeofservice << endl;
    }
    void getAllFile() {
        ofstream file;
        file.open("1.txt", ios_base::app);
        file << "Type of service provided: " << typeofservice << endl;
        file.close();
    }

    void settypeofservice(const char* typeofserviceValue) {
        delete[] typeofservice;
        typeofservice = new char[strlen(typeofserviceValue) + 1];
        strcpy(typeofservice, typeofserviceValue);
    }
    
    bool equals(const char* one, const char* two) {
        int i = 0;
        while (true) {
            if (one[i] != two[i]) {
                return false;
            }
            if (one[i] == '\0') {
                return true;
            }
            i++;
        }
    }
  
    void technicalmaintenance(const char* statusValue) {
        cout << this->typeofservice;
        if (equals(statusValue, "Regular")) {
            cout << (7000 - 0.1*7000);
        }
        else {
            cout << 7000;
        }
    }

    void getAllFile(const char* statusValue) {
        ofstream file;
        file.open("1.txt", ios_base::app);
        file << this->typeofservice;
        if (equals(statusValue, "Regular")) {
            file << "The cost is " << (7000 - 0.1 * 7000);
        }
        else {
            file << "The cost is " << 7000;
        }
        file.close();
    }

    void technicalmaintenance(const char* statusValue, const char* type) {
        cout << this->typeofservice;
        if (equals(type, "Serious")) {
            if (equals(statusValue, "Regular")) {
                cout << (10000 - 0.1 * 10000);
            }
            else {
                cout << 10000;
            }
        }
        else {
            if (equals(statusValue, "Regular")) {
                cout << (6000 - 0.1 * 6000);
            }
            else {
                cout << 6000;
            }
        }
    }
    void getAllFile(const char* statusValue, const char* type) {
        ofstream file;
        file.open("1.txt", ios_base::app);
        file << this->typeofservice;
        if (equals(type, "Serious")) {
            if (equals(statusValue, "Regular")) {
                file << (10000 - 0.1 * 10000);
            }
            else {
                file << 10000;
            }
        }
        else {
            if (equals(statusValue, "Regular")) {
                file << (6000 - 0.1 * 6000);
            }
            else {
                 file << 6000;
            }
        }
        file.close();
    }
};

bool equals(const char* one, const char* two) {
    int i = 0;
    while (true) {
        if (one[i] != two[i]) {
            return false;
        }
        if (one[i] == '\0') {
            return true;
        }
        i++;
    }
}

void operator!(const string& filename) {
    // Открываем файл для записи
    ofstream ofs(filename);

    // Если файл открыт успешно, то очищаем его содержимое
    if (ofs.is_open()) {
        ofs << "";
        ofs.close();
        cout << "Файл \"" << filename << "\" был успешно очищен.\n";
    }
    else {
        cerr << "Не удалось открыть файл \"" << filename << "\" для очистки.\n";
    }
}


int main() {

    std::string filename = "1.txt";

    !(filename);

    cout << "Hello! We are glad to welcome you to our showroom! " << endl;
    char* name = new char[32];
    cout << "Enter your name: " << endl;
    cin >> name;
    char* surname = new char[32];
    cout << "Enter your last name: " << endl;
    cin >> surname;
    long long int number;
    cout << "Enter your phone number: " << endl;
    cin >> number;
    char* status = new char[32];
    cout << "Is this your first time in our showroom or are you a regular customer? (First/Regular) " << endl;
    cin >> status;

    Customer client;
    client.setAll(name, surname, number, status);

    

    client.getAllFile(1);
     

    char* vehiclebrand = new char[32];
    int mileage;
    int releaseyear;
    int stateregistrationnumber;

    char* work = new char[32];
    cout << "Do you want to rent a car or undergo maintenance?(Rent/Maintenance)" << endl;
    cin >> work;
    
    char A[] = "Rent";
    char L[] = "Passengercar";
    char G[] = "Truck";
    char M[] = "Motorcycle";

    char R[] = "Repair";
    char O[] = "Inspection";


    if (equals(work, A)) {
        char* B = new char[32];
        int time;
        cout << "How many hours do you want to rent a car for? " << endl;
        cin >> time;
        cout << "Do you want to rent a passenger car, truck or motorcycle?(Car/Truck/Motorcycle)" << endl;
        cin >> B;
        if (equals(B, L)) {
            Passenger_car N;
            
            cout << "Enter the brand of the car: " << endl;
            cin >> vehiclebrand;
            cout << "Enter the desired mileage: " << endl;
            cin >> mileage;
            cout << "Enter the state registration number: " << endl;
            cin >> stateregistrationnumber;
            cout << "Enter the desired year of release: " << endl;
            cin >> releaseyear;
            N.setAll(vehiclebrand, mileage, releaseyear, stateregistrationnumber, status);
            N.rentprice(status, time);

            N.getAllFileCar();
            
            N.registrationfile(status);
            N.rentpriceFile(status, time);
        }
        else if (equals(B, G)) {
            Truck N;
            
            cout << "Enter the brand of the car: " << endl;
            cin >> vehiclebrand;
            cout << "Enter the desired mileage: " << endl;
            cin >> mileage;
            cout << "Enter the state registration number: " << endl;
            cin >> stateregistrationnumber;
            cout << "Enter the desired year of release: " << endl;
            cin >> releaseyear;
            N.setAll(vehiclebrand, mileage, releaseyear, stateregistrationnumber, status);
            N.rentprice(status, time);

            N.getAllFileTruck();
            
            N.registrationfile(status);
            N.rentpriceFile(status, time);
        }
        else {
            Motorcycle N;
            
            cout << "Enter the brand of the car: " << endl;
            cin >> vehiclebrand;
            cout << "Enter the desired mileage: " << endl;
            cin >> mileage;
            cout << "Enter the state registration number: " << endl;
            cin >> stateregistrationnumber;
            cout << "Enter the desired year of release: " << endl;
            cin >> releaseyear;
            N.setAll(vehiclebrand, mileage, releaseyear, stateregistrationnumber, status);
            N.rentprice(status, time);

            N.getAllFileMotorcycle();
            
            N.registrationfile(status);
            N.rentpriceFile(status, time);
        }
    }


    else{

        cout << "Enter the brand of your car: " << endl;
        cin >> vehiclebrand;
        cout << "Enter the mileage: " << endl;
        cin >> mileage;
        cout << "Enter the state registration number: " << endl;
        cin >> stateregistrationnumber;
        cout << "Enter the year of release: ";
        cin >> releaseyear;
        char* C = new char[64];
        cout << "Do you want to repair the car or undergo a technical inspection?(Repair/Inspectation)" << endl;
        cin >> C;
        Vehicle N;
        N.setAll(vehiclebrand, mileage, releaseyear, stateregistrationnumber, status);
        N.getAllFile();
        MaintenanceRecord M;
        if (equals(C,R)) {
            M.settypeofservice("To repair the car: ");
            char* type = new char[32];
            cout << "Is the breakdown serious or not serious?(Serious/Unserious)" << endl;
            cin >> type;
            
            M.technicalmaintenance(status, type);
            M.getAllFile();
            M.getAllFile(status, type);
        }
        else {
            M.settypeofservice("Technical inspection: ");
            M.technicalmaintenance(status);
            M.getAllFile();
            M.getAllFile(status);
        }

    }
    return 0;
}