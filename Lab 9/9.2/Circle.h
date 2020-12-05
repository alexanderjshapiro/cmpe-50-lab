//
//  Circle.h
//  CMPE 50 Lab Project
//  Lab 9.2
//
//  Created by Alexander Shapiro on 11/30/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#ifndef Circle_h
#define Circle_h

#include <iostream>
#include "Figure.h"
using namespace std;

class Circle : public Figure {
public:
    void erase();
    void draw();
    void center();
};

#endif // Circle_h
