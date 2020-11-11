//
//  Polynomial.cpp
//  CMPE 50 Lab Project
//  Lab 8.1
//
//  Created by Chao-Li Tarng on 10/24/13.
//  Copyright © 2013 Chao-Li Tarng. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "Polynomial.h"
using namespace std;

Polynomial::Polynomial() {
    deg = 4;
    
    coeff = new double[deg + 1];
    for (int degree = deg; degree >= 0; degree--) {
        int indexOfDegree = deg - degree;
        coeff[indexOfDegree] = 0;
    }
}


Polynomial::Polynomial(int degree) {
    deg = degree;
    
    coeff = new double[deg + 1];
    for (int degree = deg; degree >= 0; degree--) {
        int indexOfDegree = deg - degree;
        coeff[indexOfDegree] = 0;
    }
}

Polynomial::Polynomial(const Polynomial &polynomial) {
    deg = polynomial.getDegree();
    
    coeff = new double[deg + 1];
    for (int degree = deg; degree >= 0; degree--) {
        int indexOfDegree = deg - degree;
        coeff[indexOfDegree] = polynomial.getCoeff(indexOfDegree);
    }
}

Polynomial::Polynomial(int degree, double coefficients[]) {
    deg = degree;
    
    coeff = new double[deg + 1];
    for (int degree = deg; degree >= 0; degree--) {
        int indexOfDegree = deg - degree;
        coeff[indexOfDegree] = coefficients[indexOfDegree];
    }
}

Polynomial::Polynomial(double constant) {
    deg = 0;
    
    coeff = new double[1];
    coeff[0] = constant;
}

Polynomial::~Polynomial() {
    delete [] coeff;
}

int Polynomial::getDegree() const {
    return deg;
}

double Polynomial::getCoeff(int degree) const {
    if (deg < degree) {
        cout << "Degree exceeded." << endl;
        return 0;
    } else {
        int indexOfDegree = deg - degree;
        return coeff[indexOfDegree];
    }
}

void Polynomial::setCoeff(int degree, double value) {
    if (deg < degree) {
        cout << "Degree exceeded." << endl;
        return;
    } else {
        int indexOfDegree = deg - degree;
        coeff[indexOfDegree] = value;
    }
}

void Polynomial::operator=(const Polynomial &polynomial) {
	if (this == &polynomial) {
        return;
    } else {
        deg = polynomial.getDegree();
        
        delete [] coeff;
        coeff = new double[deg + 1];
        for (int degree = deg; degree >= 0; degree--) {
            int indexOfDegree = deg - degree;
            coeff[indexOfDegree] = polynomial.getCoeff(degree);
        }
    }
}

Polynomial operator+(const Polynomial &left, const Polynomial &right) {
    Polynomial sum;
    
    if (left.deg > right.deg) {
        sum = left;
        
        for (int degree = right.deg; degree >= 0; degree--) {
            int indexOfDegreeSum = sum.deg - degree;
            int indexOfDegreeRight = right.deg - degree;
            sum.coeff[indexOfDegreeSum] += right.coeff[indexOfDegreeRight];
        }
    } else {
        sum = right;
        
        for (int degree = left.deg; degree >= 0; degree--) {
            int indexOfDegreeSum = sum.deg - degree;
            int indexOfDegreeLeft = left.deg - degree;
            sum.coeff[indexOfDegreeSum] += right.coeff[indexOfDegreeLeft];
        }
    }
    
    return sum;
}

Polynomial operator+(const Polynomial &left, const double &right) {
    return left + Polynomial(right);
}

Polynomial operator+(const double &left, const Polynomial &right) {
    return Polynomial(left) + right;
}

Polynomial operator-(const Polynomial &left, const Polynomial &right) {
    Polynomial difference;
    if (left.deg > right.deg) {
        difference = left;
    } else {
        difference = Polynomial(right.deg);
        difference = difference + left;
    }
    
    for (int i = 0; i <= right.deg; i++) {
        difference.coeff[difference.deg - i] -= right.coeff[right.deg - i];
    }
    
    return difference;
}

Polynomial operator-(const Polynomial &left, const double &right) {
    return left - Polynomial(right);
}

Polynomial operator-(const double &left, const Polynomial &right) {
    return Polynomial(left) - right;
}

Polynomial operator*(const Polynomial &left, const Polynomial &right) {
    Polynomial product(left.deg + right.deg);
    
    for (int i = 0; i <= left.deg; i++) {
        for (int j = 0; j <= right.deg; j++) {
            int index = product.deg - ((left.deg - i) + (right.deg - j));
            product.coeff[index] += left.coeff[i] * right.coeff[j];
        }
    }
    
    return product;
}

Polynomial operator*(const Polynomial &left, const double &right) {
    return left * Polynomial(right);
}

Polynomial operator*(const double &left, const Polynomial &right) {
    return Polynomial(left) * right;
}

ostream& operator<<(ostream& out, const Polynomial &polynomial) {
    for (int i = 0; i < polynomial.deg - 1; i++) {
        out << "(" << polynomial.coeff[i] << "x^" << polynomial.deg - i << ") + ";
    }
    out << "(" << polynomial.coeff[polynomial.deg - 1] << "x) + "
    << "(" << polynomial.coeff[polynomial.deg] << ")";
    
    return out;
}

double Polynomial::evaluate(double value) {
    double total = 0;
    for (int i = 0; i < deg; i++) {
        total += coeff[i] * pow(value, deg - i);
    }
    total += coeff[deg];
    
    return total;
}
