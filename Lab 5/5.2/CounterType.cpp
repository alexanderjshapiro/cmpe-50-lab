//
//  CounterType.cpp
//  CMPE 50 Lab Project
//  Lab 5.2
//
//  Created by Alexander Shapiro on 10/5/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
using namespace std;

class CounterType {
private:
    int count;
    
public:
    CounterType() {
        count = 0;
    }
    
    CounterType(int val) {
        if (val >= 0) count = val;
        else cout << "The counter cannot become negative." << endl;
    }
    
    int getCount() {
        return count;
    }
    
    void incrementCounter() {
        count++;
    }
    
    void decrementCounter() {
        if (count > 0) count--;
        else cout << "The counter cannot become negative." << endl;;
    }
    
    void outputCounter(ostream &output = cout) {
        output << count << endl;;
    }
};

int main() {
    // Start at zero
    CounterType counter;
    counter.outputCounter();
    
    // Add two
    counter.incrementCounter();
    counter.incrementCounter();
    counter.outputCounter();
    
    // Subtract one
    counter.decrementCounter();
    counter.outputCounter();
    
    // Subtract two
    counter.decrementCounter();
    counter.decrementCounter();
    counter.outputCounter();
    
    return 0;
}

/* START CONSOLE OUTPUT
 0
 2
 1
 The counter cannot become negative.
 0
 Program ended with exit code: 0
END CONSOLE OUTPUT */
