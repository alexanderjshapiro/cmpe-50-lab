//
//  Rational.cpp
//  CMPE 50 Lab Project
//  Lab 6.2
//
//  Created by Alexander Shapiro on 10/12/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
using namespace std;

class Rational {
private:
    int numerator;
    int denominator;
    
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }
    
    Rational(int num, int denom) {
        numerator = num;
        if (denom != 0) {
            denominator = denom;
        } else {
            cout << "Cannot divide by zero." << endl;
            exit(1);
        }
    }
    
    void input(istream& in) {
        int num, denom;
        cout << "Enter numerator: ";
        in >> num;
        cout << "Enter denominator: ";
        in >> denom;
        numerator = num;
        if (denom != 0) {
            denominator = denom;
        } else {
            cout << "Cannot divide by zero." << endl;
            exit(1);
        }
    }
    
    void output(ostream& out) {
        out << numerator << "/" << denominator << endl;
    }
    
    friend Rational simplify(Rational& rat) {
        int n1 = rat.numerator;
        int n2 = rat.denominator;
        int temp;
        while (n2 != 0)
        {
            temp = n1;
            n1 = n2;
            n2 = temp % n2;
        }
        int gcd = abs(n1);
        
        rat.numerator /= gcd;
        rat.denominator /= gcd;
        
        if (rat.denominator < 0) {
            rat.numerator *= -1;
            rat.denominator *= -1;
        }
        return rat;
    }
    
    
    friend Rational add(const Rational& rat1, const Rational& rat2) {
        int commonDenominator = rat1.denominator * rat2.denominator;
        int num1 = rat1.numerator * rat2.denominator;
        int num2 = rat2.numerator * rat1.denominator;
        Rational answer(num1 + num2, commonDenominator);
        return simplify(answer);
    }
    
    friend Rational subtract(const Rational& rat1, const Rational& rat2) {
        int commonDenominator = rat1.denominator * rat2.denominator;
        int num1 = rat1.numerator * rat2.denominator;
        int num2 = rat2.numerator * rat1.denominator;
        Rational answer(num1 - num2, commonDenominator);
        return simplify(answer);
    }
    
    friend Rational multiply(const Rational& rat1, const Rational& rat2) {
        int numerator = rat1.numerator * rat2.numerator;
        int denominator = rat1.denominator * rat2.denominator;
        Rational answer(numerator, denominator);
        return simplify(answer);
    }
    
    friend Rational divide(const Rational& rat1, const Rational& rat2) {
        int numerator = rat1.numerator * rat2.denominator;
        int denominator = rat1.denominator * rat2.numerator;
        Rational answer(numerator, denominator);
        return simplify(answer);
    }
    
    friend bool equal(const Rational& rat1, const Rational& rat2) {
        if (rat1.numerator * rat2.denominator == rat1.denominator * rat2.numerator) {
            return true;
        } else {
            return false;
        }
    }
    
    friend bool lessThan(const Rational& rat1, const Rational& rat2) {
        if (rat1.numerator * rat2.denominator < rat1.denominator * rat2.numerator) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Rational rational1;
    Rational rational2;
    
    rational1.input(cin);
    rational2.input(cin);
    
    cout << "Your numbers added are: ";
    add(rational1, rational2).output(cout);
    cout << "Your numbers subtracted are: ";
    subtract(rational1, rational2).output(cout);
    cout << "Your numbers multiplied are: ";
    multiply(rational1, rational2).output(cout);
    cout << "Your numbers divided are: ";
    divide(rational1, rational2).output(cout);
    cout << "Your numbers are: ";
    if (equal(rational1, rational2)) {
        cout << "equal" << endl;
    } else {
        cout << "not equal" << endl;
    }
    cout << "Rational 1 is: ";
    if (lessThan(rational1, rational2)) {
        cout << "less than rational 2" << endl;
    } else {
        cout << "not less than rational 2" << endl;
    }
    
    return 0;
}

/* START CONSOLE OUTPUT
 Enter numerator: 1
 Enter denominator: -2
 Enter numerator: 3
 Enter denominator: 4
 Your numbers added are: 1/4
 Your numbers subtracted are: -5/4
 Your numbers multiplied are: -3/8
 Your numbers divided are: -2/3
 Your numbers are: not equal
 Rational 1 is: not less than rational 2
 Program ended with exit code: 0
END CONSOLE OUTPUT */
