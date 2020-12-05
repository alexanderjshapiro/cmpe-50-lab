//
//  Figure.h
//  CMPE 50 Lab Project
//  Lab 9.2
//
//  Created by Alexander Shapiro on 11/30/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#ifndef Figure_h
#define Figure_h

#include <iostream>
using namespace std;

class Figure {
public:
    virtual void erase();
    virtual void draw();
    virtual void center();
};

#endif // Figure_h
