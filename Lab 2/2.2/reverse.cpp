//
//  reverse.cpp
//  CMPE 50 Lab Project
//  Lab 2.2
//
//  Created by Alexander Shapiro on 8/30/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    const int ARRAY_SIZE = 10; // define upper limit of the array size
    char input, array[ARRAY_SIZE];
    int index = 0;
    cin >> input;
    while (input != '.') {
        array[index] = input;
        index++;
        if (index >= ARRAY_SIZE)
        {
            // Array limit is reached
            return 1; // exit the program with status 1
        }
        cin >> input;
    }
    for (int i = index-1; i >= 0; i--) {
        cout << array[i];
    }
    
    cout << "\n";
    return 0;
}

/* START CONSOLE OUTPUT
 abcdef.
 fedcba
 Program ended with exit code: 0
END CONSOLE OUTPUT */
