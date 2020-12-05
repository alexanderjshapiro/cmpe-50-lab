//
//  Triangle.cpp
//  CMPE 50 Lab Project
//  Lab 9.2
//
//  Created by Alexander Shapiro on 11/30/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include "Triangle.h"
using namespace std;

void Triangle::erase() {
    cout << "Erase Triangle" << endl;
}

void Triangle::draw() {
    cout << "Draw Triangle" << endl;
}

void Triangle::center() {
    cout << "Center Triangle" << endl;
    cout << " ";
    erase();
    cout << " ";
    draw();
}
