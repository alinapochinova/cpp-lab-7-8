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
        cout << "����� ������: " << vehiclebrand << endl;
    }
    void printmileage() {
        cout << "������: " << mileage << endl;
    }
    void printreleaseyear() {
        cout << "��� �������: " << releaseyear << endl;
    }
    void printstateregistrationnumber() {
        cout << "��������������� ��������������� �����: " << stateregistrationnumber << endl;
    }
    void printstatus() {
        cout << "������ ����������� � ������: " << status << endl;
    }
    void printAll() {
        cout << "����� ������: " << vehiclebrand << endl;
        cout << "������: " << mileage << endl;
        cout << "��� �������: " << releaseyear << endl;
        cout << "��������������� ��������������� �����: " << stateregistrationnumber << endl;
        cout << "������ ����������� � ������: " << status << endl;
       
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
        file << "����� ������: " << vehiclebrand << endl;
        file << "������: " << mileage << endl;
        file << "��� �������: " << releaseyear << endl;
        file << "��������������� ��������������� �����" << stateregistrationnumber << endl;
        file << "������ ����������� � ������: " << status << endl;
        file.close();
    }
protected:
    virtual void registration(const char* statusValue) {
        char status[] = "����������";
        if (strcmp(status, statusValue)) {
            this->setstatus("���������� ������");
            cout << "���� �������������� �����! ";
        }
        else {
            this->setstatus("����������� �������� �������");
            cout << "����������� �������� �������" << endl;
        }
    }
    virtual void registrationfile(const char* statusValue) {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        char status[] = "����������";
        if (strcmp(status, statusValue)) {
            this->setstatus("���������� ������");
            file << "���� �������������������! ";
        }
        else {
            this->setstatus("����������� �������� �������");
            file << "����������� �������� �������" << endl;
        }
        file.close();
    }
    virtual void rentprice(const char* statusValue, int timeValue) {
        char status[] = "����������";
        if (strcmp(statusValue, status)) {
            cout << "��������� ������: " << (0-0*0.1) * timeValue << endl;
        }
        else {
            cout << "��������� ������: " << setprecision(10) << 0 * timeValue << endl;
        }
        cout << "������������ �������� ���� ����������" << endl;
    }
    virtual void rentpriceFile(const char* statusValue, int timeValue) {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        char status[] = "����������";
        if (strcmp(statusValue, status)) {
            file << "��������� ������: " << (0 - 0 * 0.1) * timeValue << endl;
        }
        else {
            file << "��������� ������: " << setprecision(10) << 0 * timeValue << endl;
        }
        file << "������������ �������� ����������." << endl;
        file.close();
    }
  
};

class Passenger_car : public Vehicle {
public:
    void getAllFileCar() {
        ofstream file;//��������� ���� ��� ������
        file.open("Daily_report.txt", ios_base::app);//�������� app ��������� ��� ������ � �����(����� ���������� ������� �� ���������)
        file << "����������" << endl;
        file.close();
        getAllFile();
    }
    void registration(const char* statusValue) {
        char status[] = "����������";
        if (strcmp(status, statusValue)) {
            this->setstatus("���������� ������");
            cout << "���� �������������� �����! ";
        }
        else {
            this->setstatus("����������� �������� �������");
            cout << "����������� �������� �������" << endl;
        }
    }
    void registrationfile(const char* statusValue) {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        char status[] = "����������";
        if (strcmp(status, statusValue)) {
            this->setstatus("���������� ������");
            file << "���� �������������� �����! ";
        }
        else {
            this->setstatus("����������� �������� �������");
            file << "����������� �������� �������" << endl;
        }
        file.close();
    }
    void rentprice(const char* statusValue, int timeValue) {
        char status[] = "����������";
        if (strcmp(statusValue, status)) {
            cout << "��������� ������: " << (5000 - 5000 * 0.1) * timeValue << endl;
        }
        else {
            cout << "��������� ������: " << setprecision(10) << 5000 * timeValue << endl;
        }
        cout << "������������ �������� ���� ����������" << endl;
    }
    void rentpriceFile(const char* statusValue, int timeValue) {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        char status[] = "����������";
        if (strcmp(statusValue, status)) {
            file << "��������� ������: " << (5000 - 5000 * 0.1) * timeValue << endl;
        }
        else {
            file << "��������� ������: " << setprecision(10) << 5000 * timeValue << endl;
        }
        file << "������������ �������� ����������." << endl;
        file.close();
    }
};

class Truck : public Vehicle {
public:
    void getAllFileTruck() {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        file << "��������" << endl;
        file.close();
        getAllFile();
    }
    void registration(const char* statusValue) {
        char status[] = "����������";
        if (strcmp(status, statusValue)) {
            this->setstatus("���������� ������");
            cout << "���� �������������������! ";
        }
        else {
            this->setstatus("����������� �������� �������");
            cout << "����������� �������� �������" << endl;
        }
    }
    void registrationfile(const char* statusValue) {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        char status[] = "����������";
        if (strcmp(status, statusValue)) {
            this->setstatus("���������� ������");
            file << "���� �������������� �����! ";
        }
        else {
            this->setstatus("����������� �������� �������");
            file << "����������� �������� �������" << endl;
        }
        file.close();
    }
    void rentprice(const char* statusValue, int timeValue) {
        char status[] = "����������";
        if (strcmp(statusValue, status)) {
            cout << "��������� ������: " << (10000 - 10000 * 0.1) * timeValue << endl;
        }
        else {
            cout << "��������� ������: " << setprecision(10) << 10000 * timeValue << endl;
        }
        cout << "������������ �������� ���� ����������" << endl;
    }
    void rentpriceFile(const char* statusValue, int timeValue) {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        char status[] = "����������";
        if (strcmp(statusValue, status)) {
            file << "��������� ������: " << (10000 - 10000 * 0.1) * timeValue << endl;
        }
        else {
            file << "��������� ������: " << setprecision(10) << 10000 * timeValue << endl;
        }
        file << "������������ �������� ����������." << endl;
        file.close();
    }
};

class Motorcycle : public Vehicle {
public:
    void getAllFileMotorcycle() {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        file << "��������" << endl;
        file.close();
        getAllFile();
    }
    void registration(const char* statusValue) {
        char status[] = "����������";
        if (strcmp(status, statusValue)) {
            this->setstatus("���������� ������");
            cout << "���� �������������������! ";
        }
        else {
            this->setstatus("����������� �������� �������");
            cout << "����������� �������� �������" << endl;
        }
    }
    void registrationfile(const char* statusValue) {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        char status[] = "����������";
        if (strcmp(status, statusValue)) {
            this->setstatus("���������� ������");
            file << "���� �������������������! ";
        }
        else {
            this->setstatus("����������� �������� �������");
            file << "����������� �������� �������" << endl;
        }
        file.close();
    }
    void rentprice(const char* statusValue, int timeValue) {
        char status[] = "����������";
        if (strcmp(statusValue, status)) {
            cout << "��������� ������: " << (3000 - 3000 * 0.1) * timeValue << endl;
        }
        else {
            cout << "��������� ������: " << setprecision(10) << 3000 * timeValue << endl;
        }
        cout << "������������ �������� ���� ����������" << endl;
    }
    void rentpriceFile(const char* statusValue, int timeValue) {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        char status[] = "����������";
        if (strcmp(statusValue, status)) {
            file << "��������� ������: " << (3000 - 3000 * 0.1) * timeValue << endl;
        }
        else {
            file << "��������� ������: " << setprecision(10) << 3000 * timeValue << endl;
        }
        file << "������������ �������� ����������." << endl;
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
        cout << "���: " << name << endl;
    }
    void printsurname() {
        cout << "�������: " << surname << endl;
    }
    void printnumber() {
        cout << "����� ��������" << number << endl;
    }
    void printstatus() {
        cout << "������ ����������� � ������: " << status << endl;
    }
    void printAll()const {
        cout << "���: " << name << endl;
        cout << "�������: " << surname << endl;
        cout << "����� ��������" << number << endl;
        cout << "������ ����������� � ������: " << status << endl;
    }
    void getAllFile(int number)const {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        file << "������ �" << number << endl;
        file << "���: " << name << endl;
        file << "�������: " << surname << endl;
        file << "����� ��������: " << number << endl;
        file << "������ ����������� � ������: " << status << endl;
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
        cout << "��� ����������� ������: " << typeofservice << endl;
    }
    void printAll() {
        cout << "��� ����������� ������: " << typeofservice << endl;
    }
    void getAllFile() {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        file << "��� ����������� ������: " << typeofservice << endl;
        file.close();
    }

    void settypeofservice(const char* typeofserviceValue) {
        delete[] typeofservice;
        typeofservice = new char[strlen(typeofserviceValue) + 1];
        strcpy(typeofservice, typeofserviceValue);
    }
    
  
    void technicalmaintenance(const char* statusValue) {
        cout << this->typeofservice;
        if (strcmp(statusValue, "����������")) {
            cout << (7000 - 0.1*7000);
        }
        else {
            cout << 7000;
        }
    }

    void technicalmaintenance(const char* statusValue, const char* type) {
        cout << this->typeofservice;
        if (strcmp(type, "���������")) {
            if (strcmp(statusValue, "����������")) {
                cout << (10000 - 0.1 * 10000);
            }
            else {
                cout << 10000;
            }
        }
        else {
            if (strcmp(statusValue, "����������")) {
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
    cout << "������������! ���� ������������� ��� � ����� ����������! " << endl;
    char* name = new char[32];
    cout << "������� ���� ���: ";
    cin >> name;
    char* surname = new char[32];
    cout << "������� ���� �������: ";
    cin >> surname;
    int number;
    cout << "������� ��� ����� ��������: ";
    cin >> number;
    char* status = new char[32];
    cout << "�� ������� � ����� ���������� ��� ���������� ���������� ��������? ";
    cin >> status;

    
    char* A = new char[32];
    cout << "�� ������ ���������� ���������� ��� ������ ����������� ������������? ";
    cin >> A;

   
    if (strcmp(A, "������")) {
        char* B = new char[32];
        int time;
        cout << "�� ������� ����� �� ������ ���������� ����������? ";
        cin >> time;
        cout << "�� ������ ���������� �������� ����������, �������� ��� ��������? ";
        cin >> B;
        if (strcmp(B, "�������� ����������")) {
            Passenger_car N;
            char* vehiclebrand = new char[32];
            int mileage;
            int releaseyear;
            int stateregistrationnumber;
            cout << "������� ����� ������: ";
            cin >> vehiclebrand;
            cout << "������� �������� ������: ";
            cin >> mileage;
            cout << "������� ��������������� ��������������� �����: ";
            cin >> stateregistrationnumber;
            cout << "������� �������� ��� �������: ";
            cin >> releaseyear;
            N.rentprice(status, time);
        }
        else if (strcmp(B, "��������")) {
            Truck N;
            char* vehiclebrand = new char[32];
            int mileage;
            int releaseyear;
            int stateregistrationnumber;
            cout << "������� ����� ������: ";
            cin >> vehiclebrand;
            cout << "������� �������� ������: ";
            cin >> mileage;
            cout << "������� ��������������� ��������������� �����: ";
            cin >> stateregistrationnumber;
            cout << "������� �������� ��� �������: ";
            cin >> releaseyear;
            N.rentprice(status, time);
        }
        else {
            Motorcycle N;
            char* vehiclebrand = new char[32];
            int mileage;
            int releaseyear;
            int stateregistrationnumber;
            cout << "������� ����� ������: ";
            cin >> vehiclebrand;
            cout << "������� �������� ������: ";
            cin >> mileage;
            cout << "������� ��������������� ��������������� �����: ";
            cin >> stateregistrationnumber;
            cout << "������� �������� ��� �������: ";
            cin >> releaseyear;
            N.rentprice(status, time);
        }
    }


    else {
        char* vehiclebrand = new char[32];
        int mileage;
        int releaseyear;
        int stateregistrationnumber;
        cout << "������� ����� ����� ������: ";
        cin >> vehiclebrand;
        cout << "������� ������: ";
        cin >> mileage;
        cout << "������� ��������������� ��������������� �����: ";
        cin >> stateregistrationnumber;
        cout << "������� ��� �������: ";
        cin >> releaseyear;
        char* C = new char[64];
        cout << "�� ������ ��������������� ������ ��� ������ ����������� ������?";
        cin >> C;
        MaintenanceRecord M;
        if (strcmp(C, "��������������� ������")) {
            M.settypeofservice("��������������� ������");
            char* type = new char[32];
            cout << "������� ��������� ��� �����������? ";
            cin >> type;
            M.technicalmaintenance(status, type);
        }
        else {
            M.settypeofservice("����������� ������");
            M.technicalmaintenance(status);
        }
    }
    return 0;
}