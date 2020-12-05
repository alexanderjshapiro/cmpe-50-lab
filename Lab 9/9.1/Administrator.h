//
//  Administrator.h
//  CMPE 50 Lab Project
//  Lab 9.1
//
//  Created by Alexander Shapiro on 11/30/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#ifndef Administrator_h
#define Administrator_h

#include <iostream>
#include "SalariedEmployee.h"

class Administrator : public SalariedEmployee {
private:
    string title;
    string division;
    string supervisor;
public:
    Administrator();
    Administrator(string name, string ssn, double salary, string title, string division, string supervisor);
    void setSupervisor(string supervisor);
    void input();
    void print(ostream& out) const;
    void printCheck();
};

#endif // Administrator_h
