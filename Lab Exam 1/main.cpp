//
//  main.cpp
//  CMPE 50 Lab Project
//  Lab Exam 1
//
//  Created by Alexander Shapiro on 9/15/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void grocery() {
    // Declare and open file stream
    ifstream in;
    in.open("grocery_expenses.txt");
    if (in.fail()) {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    
    // Declare and populate input array
    double input[12];
    int inputLength = 0;
    while(in >> input[inputLength++]) { }
    
    // Process input
    double annual = 0, lowest = input[0], highest = input[0], average = 0;
    for (double month : input) {
        // Add each month to annual total
        annual += month;
        
        // Find lowest expense
        if (month < lowest) {
            lowest = month;
        }
        
        // Find highest expense
        if (month > highest) {
            highest = month;
        }
    }
    
    // Calculate average
    average = annual / 12;
    
    // Print results
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "\nGrocery Expense Report:\n"
    << "    Annual Expense:           $" << annual  << "\n"
    << "    Highest Monthly Expense:  $" << highest << "\n"
    << "    Lowest Monthly Expense:   $" << lowest  << "\n"
    << "    Average Monthly Expense:  $" << average << "\n"
    << endl;
    
    in.close();
}

void letters() {
    // Delare file streams
    ifstream in;
    ofstream out;
    
    // Ask for input method
    char inputMethod[20];
    cout << "\nWould you like to use the keyboard or a file to input?\n";
    cin >> inputMethod;
    
    // Declare input array
    char input[100];
    int inputLength = 0;
    
    // File input
    if (inputMethod[0] == 'f') {
        char inputFile[16];
        cout << "Enter the input file name (maximum of 15 characters):\n";
        cin >> inputFile;
        
        in.open(inputFile);
        if (in.fail()) {
            cout << "Input file opening failed.\n";
            exit(1);
        }
        
        // Populate input array
        while(in >> input[inputLength++]) { }
        inputLength--;
        
    // Keyboard input
    } else if (inputMethod[0] == 'k') {
        // Populate input array
        cout << "Enter letters (enter a period to end input):\n";
        while (inputLength < 100 && cin >> input[inputLength++] && input[inputLength - 1] != '.') { }
        inputLength--;
    } else {
        cout << "Unrecognized input method.\n";
        exit(1);
    }
    
    out.open("LabExamOutput1-3.txt");
    if (out.fail()) {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    
    // Declare unique letters and occurrences array
    char uniqueInput[100] = { ' ' };
    int uniqueInputIndex = 0;
    
    int occurrences[100] = { 0 };
    
    // Get unique letters from input array
    for (int i = 0; i < inputLength; i++) {
        bool isUnique = true;
        for (int j = 0; j < uniqueInputIndex; j++) {
            // Try to find duplicate
            if (input[i] == uniqueInput[j]) {
                isUnique = false;
                occurrences[j]++;
            }
        }
        if (isUnique) {
            uniqueInput[uniqueInputIndex] = input[i];
            occurrences[uniqueInputIndex++] = 1;
        }
    }
    
    // Sort array
    for (int i = uniqueInputIndex - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (occurrences[j] > occurrences[j + 1]) {
                // Swap the letters and occurrences
                int tempL = uniqueInput[j + 1];
                uniqueInput[j + 1] = uniqueInput[j];
                uniqueInput[j] = tempL;
                
                int tempO = occurrences[j + 1];
                occurrences[j + 1] = occurrences[j];
                occurrences[j] = tempO;
            }
        }
    }
    
    // Print results
    out << "Letter   Number of Occurrences" << endl;
    cout << "\n    Letter   Number of Occurrences" << endl;
    for (int i = uniqueInputIndex - 1; i >= 0; i--) {
            out.width(3);
            out << uniqueInput[i] << " ";
            out.width(15);
            out << occurrences[i] << " ";
            
            cout.width(7);
            cout << uniqueInput[i] << " ";
            cout.width(15);
            cout << occurrences[i] << " ";
        
        out << endl;
        cout << endl;
    }
    
    cout << endl;
    
    in.close();
    out.close();
}

int main() {
    int selection;
    do {
        cout << "Enter a number to use each function:\n"
        << "(1) execute grocery function\n"
        << "(2) execute letters function\n"
        << "(3) end the program"
        << endl;
        cin >> selection;
        
        if (selection == 1) {
            grocery();
        } else if (selection == 2) {
            letters();
        }
    } while (selection != 3);
    
    return 0;
}

/* START CONSOLE OUTPUT
 Enter a number to use each function:
 (1) execute grocery function
 (2) execute letters function
 (3) end the program
 1

 Grocery Expense Report:
     Annual Expense:           $2064.69
     Highest Monthly Expense:  $203.32
     Lowest Monthly Expense:   $103.48
     Average Monthly Expense:  $172.06

 Enter a number to use each function:
 (1) execute grocery function
 (2) execute letters function
 (3) end the program
 2

 Would you like to use the keyboard or a file to input?
 keyboard
 Enter letters (enter a period to end input):
 bananas and dinosaurs.

     Letter   Number of Occurrences
       a               5
       n               4
       s               3
       d               2
       r               1
       u               1
       o               1
       i               1
       b               1

 Enter a number to use each function:
 (1) execute grocery function
 (2) execute letters function
 (3) end the program
 2

 Would you like to use the keyboard or a file to input?
 file
 Enter the input file name (maximum of 15 characters):
 letters.txt

     Letter   Number of Occurrences
       o               3
       b               2
       d               2
       e               1

 Enter a number to use each function:
 (1) execute grocery function
 (2) execute letters function
 (3) end the program
 3
 Program ended with exit code: 0
END CONSOLE OUTPUT */
