//
//  Triangle.h
//  CMPE 50 Lab Project
//  Lab 9.2
//
//  Created by Alexander Shapiro on 11/30/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#ifndef Triangle_h
#define Triangle_h

#include <iostream>
#include "Figure.h"
using namespace std;

class Triangle : public Figure {
public:
    void erase();
    void draw();
    void center();
};

#endif // Triangle_h
