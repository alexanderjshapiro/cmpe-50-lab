//
//  main.cpp
//  CMPE 50 Lab Project
//
//  Created by Alexander Shapiro on 11/30/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
#include "Figure.h"
#include "Circle.h"
#include "Triangle.h"
using namespace std;

void myDraw(Figure *fig)
{
    fig->draw();
    cout << "\nmyDraw: Derived class object calling center(). \n";
    fig->center();
}

int main(){
    Figure *fig;
    
    Triangle *tri = new Triangle;
    fig = tri;
    fig->draw();
    cout << "\nDerived class Triangle object calling center(). \n";
    fig->center();
    myDraw(tri);
    
    cout << endl;
    
    Circle *cir = new Circle;
    fig = cir;
    cir->draw();
    cout << "\nDerived class Circle object calling center(). \n";
    cir->center();
    myDraw(cir);

    return 0;
}

/* START CONSOLE OUTPUT
 Draw Figure

 Derived class Triangle object calling center().
 Center Figure
  Erase Figure
  Draw Figure
 Draw Figure

 myDraw: Derived class object calling center().
 Center Figure
  Erase Figure
  Draw Figure

 Draw Circle

 Derived class Circle object calling center().
 Center Circle
  Erase Circle
  Draw Circle
 Draw Figure

 myDraw: Derived class object calling center().
 Center Figure
  Erase Figure
  Draw Figure
 Program ended with exit code: 0
END CONSOLE OUTPUT */

/* START CONSOLE OUTPUT
 Draw Triangle

 Derived class Triangle object calling center().
 Center Triangle
  Erase Triangle
  Draw Triangle
 Draw Triangle

 myDraw: Derived class object calling center().
 Center Triangle
  Erase Triangle
  Draw Triangle

 Draw Circle

 Derived class Circle object calling center().
 Center Circle
  Erase Circle
  Draw Circle
 Draw Circle

 myDraw: Derived class object calling center().
 Center Circle
  Erase Circle
  Draw Circle
 Program ended with exit code: 0
END CONSOLE OUTPUT */

// When the base class member functions are virtual, the correct derived class overridden member functions are run when called on a pointer to an object of that type. When they are not virtual, the base class member funtions are run.
