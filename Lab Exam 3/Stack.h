//
//  Stack.h
//  CMPE 50 Lab Project
//  Lab Exam 3
//
//  Created by Alexander Shapiro on 11/17/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class Stack {
private:
    double* values;
    int size;
    int maxSize;
public:
    Stack();
    Stack(int maxSize);
    Stack(const Stack &stack);
    ~Stack();
    
    void operator=(Stack &stack);
    void addLast(double value);
    double getLast();
    void deleteLast();
    bool isEmpty();
    friend ostream& operator<<(ostream &out, const Stack &stack);
};

#endif // STACK_H
