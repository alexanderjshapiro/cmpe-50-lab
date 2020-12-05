//
//  main.cpp
//  CMPE 50 Lab Project
//  Lab 9.1
//
//  Created by Alexander Shapiro on 11/30/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
#include "Administrator.h"
using namespace std;

int main() {
    Administrator test("Bob", "123-45-6789", 2000.00, "Manager", "R&D", "Alice");
    cout << "Name: " << test.getName() << endl;
    test.print(cout);
    test.printCheck();
    
    cout << endl;
    return 0;
}

/* START CONSOLE OUTPUT
 Name: Bob
 Title: Manager
 Division: R&D
 Supervisor: Alice
 __________________________________________________
 Pay to the order of Bob
 The sum of 2000 Dollars
 _________________________________________________
 Check Stub NOT NEGOTIABLE
 Employee Number: 123-45-6789
 Administrator. Regular Pay: 2000
 _________________________________________________

 Program ended with exit code: 0
END CONSOLE OUTPUT */
