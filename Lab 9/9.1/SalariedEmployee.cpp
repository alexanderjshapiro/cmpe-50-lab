//
//  SalariedEmployee.cpp
//  CMPE 50 Lab Project
//  Lab 9.1
//

#include <iostream>
#include <string>
#include "SalariedEmployee.h"
using namespace std;

SalariedEmployee::SalariedEmployee() : Employee() {
    salary = 0;
}

SalariedEmployee::SalariedEmployee(string name, string ssn, double salary) : Employee(name, ssn) {
    this->salary = salary;
}

double SalariedEmployee::getSalary() const {
    return salary;
}

void SalariedEmployee::setSalary(double salary) {
    this->salary = salary;
}

void SalariedEmployee::printCheck() {
    setNetPay(salary);
    cout << "\n__________________________________________________\n";
    cout << "Pay to the order of " << getName( ) << endl;
    cout << "The sum of " << getNetPay( ) << " Dollars\n";
    cout << "_________________________________________________\n";
    cout << "Check Stub NOT NEGOTIABLE \n";
    cout << "Employee Number: " << getSsn( ) << endl;
    cout << "Salaried Employee. Regular Pay: "
    << salary << endl;
    cout << "_________________________________________________\n";
}
