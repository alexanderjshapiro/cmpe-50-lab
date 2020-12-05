//
//  Administrator.cpp
//  CMPE 50 Lab Project
//  Lab 9.1
//
//  Created by Alexander Shapiro on 11/30/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include "Administrator.h"
using namespace std;

Administrator::Administrator() : SalariedEmployee() {
    title = "";
    division = "";
    supervisor = "";
}

Administrator::Administrator(string name, string ssn, double salary, string title, string division, string supervisor) : SalariedEmployee(name, ssn, salary) {
    this->title = title;
    this->division = division;
    this->supervisor = supervisor;
}

void Administrator::setSupervisor(string supervisor) {
    this->supervisor = supervisor;
}

void Administrator::input() {
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter division: ";
    cin >> division;
}

void Administrator::print(ostream& out) const {
    out << "Title: " << title
    << "\nDivision: " << division
    << "\nSupervisor: " << supervisor;
}

void Administrator::printCheck() {
    setNetPay(salary);
    cout << "\n__________________________________________________\n";
    cout << "Pay to the order of " << getName( ) << endl;
    cout << "The sum of " << getNetPay( ) << " Dollars\n";
    cout << "_________________________________________________\n";
    cout << "Check Stub NOT NEGOTIABLE \n";
    cout << "Employee Number: " << getSsn( ) << endl;
    cout << "Administrator. Regular Pay: "
    << salary << endl;
    cout << "_________________________________________________\n";
}
