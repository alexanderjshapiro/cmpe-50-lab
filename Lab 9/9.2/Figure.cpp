//
//  Figure.cpp
//  CMPE 50 Lab Project
//  Lab 9.2
//
//  Created by Alexander Shapiro on 11/30/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
#include "Figure.h"
using namespace std;

void Figure::erase() {
    cout << "Erase Figure" << endl;
}

void Figure::draw() {
    cout << "Draw Figure" << endl;
}

void Figure::center() {
    cout << "Center Figure" << endl;
    cout << " ";
    erase();
    cout << " ";
    draw();
}
