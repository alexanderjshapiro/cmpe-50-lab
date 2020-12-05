//
//  Circle.cpp
//  CMPE 50 Lab Project
//  Lab 9.2
//
//  Created by Alexander Shapiro on 11/30/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include "Circle.h"
using namespace std;

void Circle::erase() {
    cout << "Erase Circle" << endl;
}

void Circle::draw() {
    cout << "Draw Circle" << endl;
}

void Circle::center() {
    cout << "Center Circle" << endl;
    cout << " ";
    erase();
    cout << " ";
    draw();
}
