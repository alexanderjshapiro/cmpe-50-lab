//
//  Employee.h
//  CMPE 50 Lab Project
//  Lab 9.1
//

#ifndef Employee_h
#define Employee_h

#include <string>
using namespace std;

class Employee {
private:
    string name;
    string ssn;
    double netPay;
public:
    Employee();
    Employee(string the_name, string the_ssn);
    string getName() const;
    string getSsn() const;
    double getNetPay() const;
    void setName(string new_name);
    void setSsn(string new_ssn);
    void setNetPay(double new_net_pay);
    void printCheck() const;
};

#endif // Employee_h
