//
//  SalariedEmployee.h
//  CMPE 50 Lab Project
//  Lab 9.1
//

#ifndef SalariedEmployee_h
#define SalariedEmployee_h

#include <string>
#include "Employee.h"

using namespace std;

class SalariedEmployee : public Employee {
protected:
    double salary;
public:
    SalariedEmployee();
    SalariedEmployee (string name, string ssn, double salary);
    double getSalary() const;
    void setSalary(double salary);
    void printCheck();
};

#endif // SalariedEmployee_h

