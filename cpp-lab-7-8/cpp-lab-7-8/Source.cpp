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
    
};

class Customer {
private:
    char* name;
    char* surname;
    int number;
public:
    Customer() {
        char* name = nullptr;
        char* surname = nullptr;
        int number = 0;
    }

    Customer(const char* nameValue, const char* surnameValue, int numberValue) {
        name = new char[strlen(nameValue) + 1];
        strcpy(name, nameValue);
        surname = new char[strlen(surnameValue) + 1];
        strcpy(surname, surnameValue);
        number = numberValue;
    }

    Customer(Customer const& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        surname = new char[strlen(other.surname) + 1];
        strcpy(surname, other.surname);
        number = other.number;
    }

    ~Customer() {
        delete[] name;
        delete[] surname;
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
    void printAll()const {
        cout << "���: " << name << endl;
        cout << "�������: " << surname << endl;
        cout << "����� ��������" << number << endl;
    }
    void printAllFile(int number)const {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        file << "������ �" << number << endl;
        file << "���: " << name << endl;
        file << "�������: " << surname << endl;
        file << "����� ��������: " << number << endl;
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
    void setAll(const char* nameValue, const char* surnameValue, int numberValue) {
        delete[] name;
        name = new char[strlen(nameValue) + 1];
        strcpy(name, nameValue);
        delete[] surname;
        surname = new char[strlen(surnameValue) + 1];
        strcpy(surname, surnameValue);
        number = numberValue;
    }

};
class MaintenanceRecord {
private:
    char* typeofservice = nullptr;
    int cost;
public:
    MaintenanceRecord() {
        typeofservice = nullptr;
        cost = 0;
    }
    MaintenanceRecord(const char* typeofserviceValue, int costValue) {
        typeofservice = new char[strlen(typeofserviceValue) + 1];
        strcpy(typeofservice, typeofserviceValue);
        cost = costValue;
    }
    MaintenanceRecord(MaintenanceRecord const& other) {
        typeofservice = new char[strlen(other.typeofservice) + 1];
        strcpy(typeofservice, other.typeofservice);
        cost = other.cost;
    }
    ~MaintenanceRecord() {
        delete[] typeofservice;
    }

    void printtypeofservice() {
        cout << "��� ����������� ������: " << typeofservice << endl;
    }
    void printcost() {
        cout << "���� ������: " << cost << endl;
    }
    void printAll() {
        cout << "��� ����������� ������: " << typeofservice << endl;
        cout << "���� ������: " << cost << endl;
    }
    void getAllFile() {
        ofstream file;
        file.open("Daily_report.txt", ios_base::app);
        file << "��� ����������� ������: " << typeofservice << endl;
        file << "���� ������: " << cost << endl;
        file.close();
    }

    void settypeofservice(const char* typeofserviceValue) {
        delete[] typeofservice;
        typeofservice = new char[strlen(typeofserviceValue) + 1];
        strcpy(typeofservice, typeofserviceValue);
    }
    void setcost(int costValue) {
        cost = costValue;
    }
    void setAll(const char* typeofserviceValue, int costValue) {
        delete[] typeofservice;
        typeofservice = new char[strlen(typeofserviceValue) + 1];
        strcpy(typeofservice, typeofserviceValue);
        cost = costValue;
    }
   
};

