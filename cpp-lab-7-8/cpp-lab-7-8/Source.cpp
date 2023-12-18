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
        cout << "Марка машины: " << vehiclebrand << endl;
    }
    void printmileage() {
        cout << "Пробег: " << mileage << endl;
    }
    void printreleaseyear() {
        cout << "Год выпуска: " << releaseyear << endl;
    }
    void printstateregistrationnumber() {
        cout << "Государственный регистрационный номер: " << stateregistrationnumber << endl;
    }
    void printstatus() {
        cout << "Статус регистрации в салоне: " << status << endl;
    }
    void printAll() {
        cout << "Марка машины: " << vehiclebrand << endl;
        cout << "Пробег: " << mileage << endl;
        cout << "Год выпуска: " << releaseyear << endl;
        cout << "Государственный регистрационный номер: " << stateregistrationnumber << endl;
        cout << "Статус регистрации в салоне: " << status << endl;
       
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
        file.open("Daily_report.txt", ios_base::app);
        file << "Марка машины: " << vehiclebrand << endl;
        file << "Пробег: " << mileage << endl;
        file << "Год выпуска: " << releaseyear << endl;
        file << "Государственный регистрационный номер" << stateregistrationnumber << endl;
        file << "Статус регистрации в салоне: " << status << endl;
        file.close();
    }
protected:
    virtual void registration(const char* statusValue) {
        char status[] = "Постоянный";
        if (strcmp(status, statusValue)) {
            this->setstatus("Постоянный клиент");
            cout << "Рады приветствовать вновь! ";
        }
        else {
            this->setstatus("Регистрация пройдена успешно");
            cout << "Регистрация пройдена успешно" << endl;
        }
    }
    virtual void registrationfile(const char* statusValue) {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        char status[] = "Постоянный";
        if (strcmp(status, statusValue)) {
            this->setstatus("Постоянный клиент");
            file << "Рады приветствоватьвновь! ";
        }
        else {
            this->setstatus("Регистрация пройдена успешно");
            file << "Регистрация пройдена успешно" << endl;
        }
        file.close();
    }
    virtual void rentprice(const char* statusValue, int timeValue) {
        char status[] = "Постоянный";
        if (strcmp(statusValue, status)) {
            cout << "Стоимость аренды: " << (0-0*0.1) * timeValue << endl;
        }
        else {
            cout << "Стоимость аренды: " << setprecision(10) << 0 * timeValue << endl;
        }
        cout << "Транспортное средство было арендовано" << endl;
    }
    virtual void rentpriceFile(const char* statusValue, int timeValue) {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        char status[] = "Постоянный";
        if (strcmp(statusValue, status)) {
            file << "Стоимость аренды: " << (0 - 0 * 0.1) * timeValue << endl;
        }
        else {
            file << "Стоимость аренды: " << setprecision(10) << 0 * timeValue << endl;
        }
        file << "Транспортное средство арендовано." << endl;
        file.close();
    }
  
};

class Passenger_car : public Vehicle {
public:
    void getAllFileCar() {
        ofstream file;//открываем файл для записи
        file.open("Daily_report.txt", ios_base::app);//параметр app необходим для записи в конец(чтобы предыдущие клиенты не стирались)
        file << "Автомобиль" << endl;
        file.close();
        getAllFile();
    }
    void registration(const char* statusValue) {
        char status[] = "Постоянный";
        if (strcmp(status, statusValue)) {
            this->setstatus("Постоянный клиент");
            cout << "Рады приветствовать вновь! ";
        }
        else {
            this->setstatus("Регистрация пройдена успешно");
            cout << "Регистрация пройдена успешно" << endl;
        }
    }
    void registrationfile(const char* statusValue) {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        char status[] = "Постоянный";
        if (strcmp(status, statusValue)) {
            this->setstatus("Постоянный клиент");
            file << "Рады приветствовать вновь! ";
        }
        else {
            this->setstatus("Регистрация пройдена успешно");
            file << "Регистрация пройдена успешно" << endl;
        }
        file.close();
    }
    void rentprice(const char* statusValue, int timeValue) {
        char status[] = "Постоянный";
        if (strcmp(statusValue, status)) {
            cout << "Стоимость аренды: " << (5000 - 5000 * 0.1) * timeValue << endl;
        }
        else {
            cout << "Стоимость аренды: " << setprecision(10) << 5000 * timeValue << endl;
        }
        cout << "Транспортное средство было арендовано" << endl;
    }
    void rentpriceFile(const char* statusValue, int timeValue) {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        char status[] = "Постоянный";
        if (strcmp(statusValue, status)) {
            file << "Стоимость аренды: " << (5000 - 5000 * 0.1) * timeValue << endl;
        }
        else {
            file << "Стоимость аренды: " << setprecision(10) << 5000 * timeValue << endl;
        }
        file << "Транспортное средство арендовано." << endl;
        file.close();
    }
};

class Truck : public Vehicle {
public:
    void getAllFileTruck() {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        file << "Грузовик" << endl;
        file.close();
        getAllFile();
    }
    void registration(const char* statusValue) {
        char status[] = "Постоянный";
        if (strcmp(status, statusValue)) {
            this->setstatus("Постоянный клиент");
            cout << "Рады приветствоватьвновь! ";
        }
        else {
            this->setstatus("Регистрация пройдена успешно");
            cout << "Регистрация пройдена успешно" << endl;
        }
    }
    void registrationfile(const char* statusValue) {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        char status[] = "Постоянный";
        if (strcmp(status, statusValue)) {
            this->setstatus("Постоянный клиент");
            file << "Рады приветствовать вновь! ";
        }
        else {
            this->setstatus("Регистрация пройдена успешно");
            file << "Регистрация пройдена успешно" << endl;
        }
        file.close();
    }
    void rentprice(const char* statusValue, int timeValue) {
        char status[] = "Постоянный";
        if (strcmp(statusValue, status)) {
            cout << "Стоимость аренды: " << (10000 - 10000 * 0.1) * timeValue << endl;
        }
        else {
            cout << "Стоимость аренды: " << setprecision(10) << 10000 * timeValue << endl;
        }
        cout << "Транспортное средство было арендовано" << endl;
    }
    void rentpriceFile(const char* statusValue, int timeValue) {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        char status[] = "Постоянный";
        if (strcmp(statusValue, status)) {
            file << "Стоимость аренды: " << (10000 - 10000 * 0.1) * timeValue << endl;
        }
        else {
            file << "Стоимость аренды: " << setprecision(10) << 10000 * timeValue << endl;
        }
        file << "Транспортное средство арендовано." << endl;
        file.close();
    }
};

class Motorcycle : public Vehicle {
public:
    void getAllFileMotorcycle() {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        file << "Мотоцикл" << endl;
        file.close();
        getAllFile();
    }
    void registration(const char* statusValue) {
        char status[] = "Постоянный";
        if (strcmp(status, statusValue)) {
            this->setstatus("Постоянный клиент");
            cout << "Рады приветствоватьвновь! ";
        }
        else {
            this->setstatus("Регистрация пройдена успешно");
            cout << "Регистрация пройдена успешно" << endl;
        }
    }
    void registrationfile(const char* statusValue) {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        char status[] = "Постоянный";
        if (strcmp(status, statusValue)) {
            this->setstatus("Постоянный клиент");
            file << "Рады приветствоватьвновь! ";
        }
        else {
            this->setstatus("Регистрация пройдена успешно");
            file << "Регистрация пройдена успешно" << endl;
        }
        file.close();
    }
    void rentprice(const char* statusValue, int timeValue) {
        char status[] = "Постоянный";
        if (strcmp(statusValue, status)) {
            cout << "Стоимость аренды: " << (3000 - 3000 * 0.1) * timeValue << endl;
        }
        else {
            cout << "Стоимость аренды: " << setprecision(10) << 3000 * timeValue << endl;
        }
        cout << "Транспортное средство было арендовано" << endl;
    }
    void rentpriceFile(const char* statusValue, int timeValue) {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        char status[] = "Постоянный";
        if (strcmp(statusValue, status)) {
            file << "Стоимость аренды: " << (3000 - 3000 * 0.1) * timeValue << endl;
        }
        else {
            file << "Стоимость аренды: " << setprecision(10) << 3000 * timeValue << endl;
        }
        file << "Транспортное средство арендовано." << endl;
        file.close();
    }
};

class Customer {
private:
    char* name;
    char* surname;
    int number;
    char* status;
public:
    Customer() {
        char* name = nullptr;
        char* surname = nullptr;
        int number = 0;
        char* status = nullptr;
    }

    Customer(const char* nameValue, const char* surnameValue, int numberValue, const char* statusValue, const char* typeValue) {
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
        cout << "Имя: " << name << endl;
    }
    void printsurname() {
        cout << "Фамилия: " << surname << endl;
    }
    void printnumber() {
        cout << "Номер телефона" << number << endl;
    }
    void printstatus() {
        cout << "Статус регистрации в салоне: " << status << endl;
    }
    void printAll()const {
        cout << "Имя: " << name << endl;
        cout << "Фамилия: " << surname << endl;
        cout << "Номер телефона" << number << endl;
        cout << "Статус регистрации в салоне: " << status << endl;
    }
    void getAllFile(int number)const {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        file << "Клиент №" << number << endl;
        file << "Имя: " << name << endl;
        file << "Фамилия: " << surname << endl;
        file << "Номер телефона: " << number << endl;
        file << "Статус регистрации в салоне: " << status << endl;
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
    void setAll(const char* nameValue, const char* surnameValue, int numberValue,const char*statusValue, const char* typeValue) {
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
        cout << "Тип оказываемой услуги: " << typeofservice << endl;
    }
    void printAll() {
        cout << "Тип оказываемой услуги: " << typeofservice << endl;
    }
    void getAllFile() {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        file << "Тип оказываемой услуги: " << typeofservice << endl;
        file.close();
    }

    void settypeofservice(const char* typeofserviceValue) {
        delete[] typeofservice;
        typeofservice = new char[strlen(typeofserviceValue) + 1];
        strcpy(typeofservice, typeofserviceValue);
    }
    
  
    void technicalmaintenance(const char* statusValue) {
        cout << this->typeofservice;
        if (strcmp(statusValue, "Постоянный")) {
            cout << (7000 - 0.1*7000);
        }
        else {
            cout << 7000;
        }
    }

    void technicalmaintenance(const char* statusValue, const char* type) {
        cout << this->typeofservice;
        if (strcmp(type, "Серьезная")) {
            if (strcmp(statusValue, "Постоянный")) {
                cout << (10000 - 0.1 * 10000);
            }
            else {
                cout << 10000;
            }
        }
        else {
            if (strcmp(statusValue, "Постоянный")) {
                cout << (6000 - 0.1 * 6000);
            }
            else {
                cout << 6000;
            }
        }
    }
};


int main() {
    setlocale(LC_ALL, "ru");
    cout << "Здравствуйте! Рады приветсвовать Вас в нашем автосалоне! " << endl;
    char* name = new char[32];
    cout << "Введите Ваше имя: ";
    cin >> name;
    char* surname = new char[32];
    cout << "Введите Вашу фамилию: ";
    cin >> surname;
    int number;
    cout << "Введите Ваш номер телефона: ";
    cin >> number;
    char* status = new char[32];
    cout << "Вы впервые в нашем автосалоне или являететсь постоянным клиентом? ";
    cin >> status;

    char* vehiclebrand = new char[32];
    int mileage;
    int releaseyear;
    int stateregistrationnumber;

    char* A = new char[32];
    cout << "Вы хотите арендовать автомобиль или пройти техническое обслуживание? ";
    cin >> A;

   
    if (strcmp(A, "Аренда")) {
        char* B = new char[32];
        int time;
        cout << "На сколько часов Вы хотите арендовать автомобиль? ";
        cin >> time;
        cout << "Вы хотите арендовать легковой автомобиль, грузовик или мотоцикл? ";
        cin >> B;
        if (strcmp(B, "Легковой автомобиль")) {
            Passenger_car N;
            
            cout << "Введите марку машины: ";
            cin >> vehiclebrand;
            cout << "Введите желаемый пробег: ";
            cin >> mileage;
            cout << "Введите государственный регистрационныц номер: ";
            cin >> stateregistrationnumber;
            cout << "Введите желаемый год выпуска: ";
            cin >> releaseyear;
            N.rentprice(status, time);
        }
        else if (strcmp(B, "Грузовик")) {
            Truck N;
            
            cout << "Введите марку машины: ";
            cin >> vehiclebrand;
            cout << "Введите желаемый пробег: ";
            cin >> mileage;
            cout << "Введите государственный регистрационныц номер: ";
            cin >> stateregistrationnumber;
            cout << "Введите желаемый год выпуска: ";
            cin >> releaseyear;
            N.rentprice(status, time);
        }
        else {
            Motorcycle N;
            
            cout << "Введите марку машины: ";
            cin >> vehiclebrand;
            cout << "Введите желаемый пробег: ";
            cin >> mileage;
            cout << "Введите государственный регистрационныц номер: ";
            cin >> stateregistrationnumber;
            cout << "Введите желаемый год выпуска: ";
            cin >> releaseyear;
            N.rentprice(status, time);
        }
    }


    else {
        cout << "Введите марку своей машины: ";
        cin >> vehiclebrand;
        cout << "Введите пробег: ";
        cin >> mileage;
        cout << "Введите государственный регистрационныц номер: ";
        cin >> stateregistrationnumber;
        cout << "Введите год выпуска: ";
        cin >> releaseyear;
        char* C = new char[64];
        cout << "Вы хотите отремонтировать машину или пройти технический осмотр?";
        cin >> C;
        MaintenanceRecord M;
        if (strcmp(C, "Отремонтировать машину")) {
            M.settypeofservice("Отремонтировать машину");
            char* type = new char[32];
            cout << "Поломка серьезная или несерьезная? ";
            cin >> type;
            M.technicalmaintenance(status, type);
        }
        else {
            M.settypeofservice("Технический осмотр");
            M.technicalmaintenance(status);
        }
    }
    return 0;
}