//
//  Complex.cpp
//  CMPE 50 Lab Project
//  Lab 8.2
//
//  Created by Alexander Shapiro on 11/10/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
#include "Complex.h"
using namespace std;

Complex::Complex() {
    real = 0;
    imaginary = 0;
}

Complex::Complex(double real) {
    this->real = real;
    imaginary = 0;
}

Complex::Complex(double real, double imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}

bool operator==(const Complex& left, const Complex& right) {
    if (left.real == right.real && left.imaginary == right.imaginary) {
        return true;
    } else {
        return false;
    }
}

Complex operator+(const Complex& left, const Complex& right) {
    Complex sum;
    
    sum.real = left.real + right.real;
    sum.imaginary = left.imaginary + right.imaginary;
    
    return sum;
}

Complex operator-(const Complex& left, const Complex& right) {
    Complex difference;
    
    difference.real = left.real - right.real;
    difference.imaginary = left.imaginary - right.imaginary;
    
    return difference;
}

Complex operator*(const Complex& left, const Complex& right) {
    Complex product;
    
    product.real = left.real * right.real - left.imaginary * right.imaginary;
    product.imaginary = left.real * right.imaginary + left.imaginary * right.real;
    
    return product;
}

istream& operator>>(istream& in, Complex& complex) {
    in >> complex.real >> complex.imaginary;
    
    return in;
}

ostream& operator<<(ostream& out, const Complex& complex) {
    out << complex.real << " + " << complex.imaginary << " * i";
    
    return out;
}
