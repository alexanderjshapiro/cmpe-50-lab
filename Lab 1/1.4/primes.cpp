//
//  main.cpp
//  CMPE 50 Lab Project
//  Lab 1.4
//
//  Created by Alexander Shapiro on 8/25/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;
    
    if (k == 2 || k == 3) {
           cout << k;
    } else {
        for (int i = 3; i <= k; i++) {
            bool isPrime = true;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                }
            }
            if (isPrime) {
                cout << i;
                cout << " is a prime number.\n";
            }
        }
    }
    return 0;
}

/* START CONSOLE OUTPUT
 17
 3 is a prime number.
 5 is a prime number.
 7 is a prime number.
 11 is a prime number.
 13 is a prime number.
 17 is a prime number.
 Program ended with exit code: 0
END CONSOLE OUTPUT */
