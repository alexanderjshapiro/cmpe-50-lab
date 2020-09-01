//
//  overloading.cpp
//  CMPE 50 Lab Project
//  Lab 2.1
//
//  Created by Alexander Shapiro on 8/30/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
using namespace std;

void add(double first, double second) {
    cout << first + second << "\n";
}

void add(int first, int second) {
    cout << first + second << "\n";
}

void add(string first, string second) {
    cout << first + second << "\n";
}

int main() {
    string type;
    cout << "Do you want to add doubles, ints, or strings?\n";
    cin >> type;
    if (type == "doubles") {
        double first, second;
        cout << "Enter first double: ";
        cin >> first;
        cout << "Enter second double: ";
        cin >> second;
        
        add(first, second);
    } else if (type == "ints") {
        int first, second;
        cout << "Enter first int: ";
        cin >> first;
        cout << "Enter second int: ";
        cin >> second;
        
        add(first, second);
    } else if (type == "strings") {
        string first, second;
        cout << "Enter first string: ";
        cin >> first;
        cout << "Enter second string: ";
        cin >> second;
        
        add(first, second);
    }
    
    return 0;
}

/* START CONSOLE OUTPUT
 Do you want to add doubles, ints, or strings?
 doubles
 Enter first double: 1.2
 Enter second double: 3.4
 4.6
 Program ended with exit code: 0
END CONSOLE OUTPUT */
