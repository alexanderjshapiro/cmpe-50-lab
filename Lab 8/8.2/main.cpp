//
//  main.cpp
//  CMPE 50 Lab Project
//  Lab 8.2
//
//  Created by Alexander Shapiro on 11/10/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
#include "Complex.h"
using namespace std;

int main() {
    Complex complex1(2, 3);
    Complex complex2(1, 2);
    
    cout << "complex1: " << complex1 << endl;
    cout << "complex2: " << complex2 << endl;
    cout << "complex1 + complex2: " << (complex1 + complex2) << endl;
    cout << "complex1 - complex2: " << (complex1 - complex2) << endl;
    cout << "complex1 * complex2: " << (complex1 * complex2) << endl;
    cout << "complex1 == complex2: " << (complex1 == complex2) << endl;
    
    return 0;
}

/* START CONSOLE OUTPUT
 complex1: 2 + 3 * i
 complex2: 1 + 2 * i
 complex1 + complex2: 3 + 5 * i
 complex1 - complex2: 1 + 1 * i
 complex1 * complex2: -4 + 7 * i
 complex1 == complex2: 0
 Program ended with exit code: 0
END CONSOLE OUTPUT */
