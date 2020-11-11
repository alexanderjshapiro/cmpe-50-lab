//
//  Complex.h
//  CMPE 50 Lab Project
//  Lab 8.2
//
//  Created by Alexander Shapiro on 11/10/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;
public:
    // Default real and imaginary to zero
    Complex();
    
    // Set real and default imaginary to zero
    Complex(double real);
    
    // Set real and imaginary
    Complex(double real, double imaginary);
    
    // Compare complex numbers
    friend bool operator==(const Complex& left, const Complex& right);
    
    // Add complex numbers
    friend Complex operator+(const Complex& left, const Complex& right);
    
    // Subtract complex numbers
    friend Complex operator-(const Complex& left, const Complex& right);
    
    // Multiply complex numbers
    friend Complex operator*(const Complex& left, const Complex& right);
    
    // Input a complex number
    friend istream& operator>>(istream& in, Complex& complex);
    
    // Output a complex number
    friend ostream& operator<<(ostream& out, const Complex& complex);
};

const Complex i(0, 1);

#endif /* COMPLEX_H_ */
