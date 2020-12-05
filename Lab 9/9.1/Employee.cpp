//
//  Employee.cpp
//  CMPE 50 Lab Project
//  Lab 9.1
//

#include <string>
#include <cstdlib>
#include <iostream>
#include "Employee.h"
using namespace std;

Employee::Employee() {
    name = "";
    ssn = "";
    netPay = 0;
}

Employee::Employee(string name, string ssn) {
    this->name = name;
    this->ssn = ssn;
    netPay = 0;
}

string Employee::getName( ) const {
    return name;
}

string Employee::getSsn( ) const {
    return ssn;
}

double Employee::getNetPay( ) const {
    return netPay;
}

void Employee::setName(string name) {
    this->name = name;
}

void Employee::setSsn(string ssn) {
    this->ssn = ssn;
}

void Employee::setNetPay (double netPay) {
    this->netPay = netPay;
}

void Employee::printCheck( ) const {
    cout << "\nERROR: print_check FUNCTION CALLED FOR AN \n"
    << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
    << "Check with the author of the program about this bug.\n";
    exit(1);
}

