//
//  characters.cpp
//  CMPE 50 Lab Project
//  Lab 3.1
//
//  Created by Alexander Shapiro on 9/7/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
    ifstream in;
    ofstream out;
    
    in.open("input.txt");
    if (in.fail()) {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    
    out.open("output.txt");
    if (out.fail()) {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    
    char input[1000];
    
    for (int i = 0; i < sizeof(input); i++) {
        in >> input[i];
        input[i] = toupper(input[i]);
        if (input[i] == ' ' || input[i] == '\n') {
            i--;
        }
    }
    
    for (int i = 0; i < sizeof(input); i++) {
        out << input[i]
        << endl;
    }
        
    in.close();
    out.close();
    
    return 0;
}

/* START CONSOLE OUTPUT
 Program ended with exit code: 0
END CONSOLE OUTPUT */
