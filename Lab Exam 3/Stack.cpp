//
//  Stack.cpp
//  CMPE 50 Lab Project
//  Lab Exam 3
//
//  Created by Alexander Shapiro on 11/17/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include "Stack.h"
using namespace std;

Stack::Stack() {
    maxSize = 10;
    values = new double[maxSize];
    size = 0;
}

Stack::Stack(int maxSize) {
    this->maxSize = maxSize;
    values = new double[this->maxSize];
    size = 0;
}

Stack::Stack(const Stack &stack) {
    maxSize = stack.maxSize;
    
    values = new double[maxSize];
    for (int i = 0; i < maxSize; i++) {
        values[i] = stack.values[i];
    }
    
    size = stack.size;
}

Stack::~Stack() {
    delete [] values;
}

void Stack::operator=(Stack &stack) {
    if (this == &stack) {
        return;
    } else {
        maxSize = stack.maxSize;
        
        delete [] values;
        values = new double[maxSize];
        for (int i = 0; i < maxSize; i++) {
            values[i] = stack.values[i];
        }
        
        size = stack.size;
    }
}

void Stack::addLast(double value) {
    if (size < maxSize) {
        values[size++] = value;
    } else {
        Stack old(*this);
        
        delete [] values;
        maxSize *= 2;
        values = new double[maxSize];
        for (int i = 0; i < old.maxSize; i++) {
            values[i] = old.values[i];
        }
        
        values[size++] = value;
    }
    
}

double Stack::getLast() {
    return values[size - 1];
}

void Stack::deleteLast() {
    values[size-- - 1] = NULL;
}

bool Stack::isEmpty() {
    if (size == 0) {
        return true;
    } else {
        return false;
    }
}

ostream& operator<<(ostream &out, const Stack &stack) {
    out << "{ ";
    for (int i = 0; i < stack.maxSize - 1; i++) {
        out << stack.values[i] << ", ";
    }
    out << stack.values[stack.maxSize - 1] << " }";
    return out;
}
