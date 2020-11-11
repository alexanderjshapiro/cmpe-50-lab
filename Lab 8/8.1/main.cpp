//
//  main.cpp
//  CMPE 50 Lab Project
//  Lab 8.1
//
//  Created by Alexander Shapiro on 11/9/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() {
    double coefficients1[3] = {2, 5, -3};
    double coefficients2[2] = {1, 2};
    Polynomial polynomial1(2, coefficients1);
    Polynomial polynomial2(1, coefficients2);
    
    cout << "polynomial1: " << polynomial1 << endl;
    cout << "polynomial2: " << polynomial2 << endl;
    cout << "polynomial1 + polynomial2: " << polynomial1 + polynomial2 << endl;
    cout << "2 + polynomial2: " << 2 + polynomial2 << endl;
    cout << "polynomial1 - polynomial2: " << polynomial1 - polynomial2 << endl;
    cout << "polynomial1 * polynomial2: " << polynomial1 * polynomial2 << endl;
    cout << "polynomial1 * 2: " << polynomial1 * 2 << endl;
    
    cout << "polynomial2 where x = 1: " << polynomial2.evaluate(1) << endl;
    cout << "degree 1 coefficient of polynomial2: " << polynomial2.getCoeff(1) << endl;
    
    return 0;
}

/* START CONSOLE OUTPUT
 polynomial1: (2x^2) + (5x) + (-3)
 polynomial2: (1x) + (2)
 polynomial1 + polynomial2: (2x^2) + (6x) + (-1)
 2 + polynomial2: (1x) + (3)
 polynomial1 - polynomial2: (2x^2) + (4x) + (-5)
 polynomial1 * polynomial2: (2x^3) + (9x^2) + (7x) + (-6)
 polynomial1 * 2: (4x^2) + (10x) + (-6)
 polynomial2 where x = 1: 3
 degree 1 coefficient of polynomial2: 1
 Program ended with exit code: 0
END CONSOLE OUTPUT */
