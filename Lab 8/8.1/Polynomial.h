//
//  Polynomial.h
//  CMPE 50 Lab Project
//  Lab 8.1
//
//  Created by Chao-Li Tarng on 10/24/13.
//  Copyright © 2013 Chao-Li Tarng. All rights reserved.
//

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
using namespace std;

class Polynomial {
private:
    int deg;
    double *coeff;
    
public:
    // Default deg and coeff to zero
    Polynomial();
    
    // Set deg and default coeff to zero
    Polynomial(int degree);
    
    // Copy values of deg and coeff to new object
    Polynomial(const Polynomial &polynomial);
    
    // Set deg and coeff
    Polynomial(int degree, double coefficients[]);
    
    // Convert a constant to a polynomial with a deg of zero
    Polynomial(double constant);
    
    // Return dynamically assigned memory to freestore
    ~Polynomial();
    
    // Return deg
    int getDegree() const;
    
    // Return coeff of degree
    double getCoeff(int degree) const;
    
    // Set coeff of degree
    void setCoeff(int degree, double value);
    
    // Overwrite a Polynomial with deg and coeff from polynomial
    void operator=(const Polynomial &polynomial);
    
    // Add polynomials
    friend Polynomial operator+(const Polynomial &left, const Polynomial &right);
    
    // Add polynomial and constant
    friend Polynomial operator+(const Polynomial &left, const double &right);
    
    // Add constant and polynomial
    friend Polynomial operator+(const double &left, const Polynomial &right);
    
    // Subract polynomials
    friend Polynomial operator-(const Polynomial &left, const Polynomial &right);
    
    // Subract polynomial and constant
    friend Polynomial operator-(const Polynomial &left, const double &right);
    
    // Subract constant and polynomial
    friend Polynomial operator-(const double &left, const Polynomial &right);
    
    // Multiply polynomials
    friend Polynomial operator*(const Polynomial &left, const Polynomial &right);
    
    // Multiply polynomial and constant
    friend Polynomial operator*(const Polynomial &left, const double &right);
    
    // Multiply constant and polynomial
    friend Polynomial operator*(const double &left, const Polynomial &right);
    
    // Print out formatted Polynomial
    friend ostream& operator<<(ostream& ost, const Polynomial &polynomial);
    
    // Evaluate the polynomial for a value
    double evaluate(double value);
};

#endif /* POLYNOMIAL_H_ */
