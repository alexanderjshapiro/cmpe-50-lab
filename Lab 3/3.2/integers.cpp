//
//  integers.cpp
//  CMPE 50 Lab Project
//  Lab 3.2
//
//  Created by Alexander Shapiro on 9/7/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
    // Declare file streams
    ifstream in;
    ofstream out;
    
    // Ask for input method
    char inputMethod[8];
    cout << "Would you like to use the keyboard or a file to input?\n";
    cin >> inputMethod;
    
    // Create and populate input array
    int input[49];
    int inputLength = 0;
    
    if (inputMethod[0] == 'f') {
        char inputFile[16];
        cout << "Enter the input file name (maximum of 15 characters):\n";
        cin >> inputFile;
        
        in.open(inputFile);
        if (in.fail()) {
            cout << "Input file opening failed.\n";
            exit(1);
        }
        
        while(in >> input[inputLength++]) { }
    } else if (inputMethod[0] == 'k') {
        cout << "Enter at most 49 integers (enter any letter to end input):\n";
        while (inputLength < 50 && cin >> input[inputLength++]) { }
    } else {
        cout << "Unrecognized input method.\n";
        exit(1);
    }
    
    out.open("output.txt");
    if (out.fail()) {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    
    // Sort array
    for (int i = inputLength-2; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (input[j] > input[j+1]) {
            // Swap the numbers
            int temp = input[j+1];
            input[j+1] = input[j];
            input[j] = temp;
            }
        }
    }
    
    int uniqueInput[49][2] = { 0 };
    int uniqueInputIndex = 0;
    bool uniqueInputHasZero = false;
    for (int i = 0; i < inputLength - 1; i++) {
        bool isUnique = true;
        for (int j = 0; j < uniqueInputIndex; j++) {
            // Try to find duplicate
            if ((input[i] == uniqueInput[j][0]) || (input[i] == 0 && uniqueInputHasZero)) {
                isUnique = false;
                uniqueInput[j][1]++;
            }
        }
        if (isUnique) {
            uniqueInput[uniqueInputIndex++][0] = input[i];
            uniqueInput[uniqueInputIndex - 1][1] = 1;
            if (input[i] == 0) {
                uniqueInputHasZero = true;
            }
        }
    }
    
    out << "  N   Count" << endl;
    cout << "  N   Count" << endl;
    for (int i = uniqueInputIndex - 1; i >= 0; i--) {
        for (int j = 0; j < 2; j++) {
            out.width(4);
            out << uniqueInput[i][j] << " ";
            
            cout.width(4);
            cout << uniqueInput[i][j] << " ";
        }
        out << endl;
        cout << endl;
    }
        
    in.close();
    out.close();
    
    return 0;

    
}
/* START CONSOLE OUTPUT
 Would you like to use the keyboard or a file to input?
 file
 Enter the input file name (maximum of 15 characters):
 input.txt
   N   Count
    4    2
    3    1
    1    2
   -3    1
 Program ended with exit code: 0
END CONSOLE OUTPUT */
