//
//  seats.cpp
//  CMPE 50 Lab Project
//  Lab 7.1
//
//  Created by Alexander Shapiro on 10/26/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Ask for input method
    int inputSelection = 1;
    cout << "Choose input method:\n"
    << "(1) Console\n"
    << "(2) File\n";
    cin >> inputSelection;
    
    // Set up file input
    ifstream in;
    if (inputSelection == 2) {
        in.open("input.txt");
        if (in.fail()) {
            cout << "Failed to input file." << endl;
            exit(1);
        }
    }
    
    char** seatMap;
    
    // Get number of rows and seats per row
    int row;
    cout << "Enter the number of rows (up to 9): ";
    if (inputSelection == 2) {
        in >> row;
        cout << row << endl;
    } else {
        cin >> row;
    }
    cout << "\n";
    
    const int col = 4;

    
    // Dynamically allocate space for array
    seatMap = new char*[row];
    for (int i = 0; i < row; i++){
        seatMap[i] = new char[col];
    }
    
    // Populate array
    for(int i = 0; i < row; i++){
        seatMap[i][0] = 48 + i + 1;
        for(int j = 1; j < col; j++){
            seatMap[i][j] = 64 + j;
        }
    }
    
    // Display array
    cout << "Seat Map: " << endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << seatMap[i][j] << ' ';
        }
        cout << endl;
    }
    
    int count = row * (col - 1);
    bool finished = false;
    while (!finished) {
        // Make seat selection
        cout << "\nEnter seat to reserve (e.g. 3B), or 00 to finish: ";
        char input[2];
        if (inputSelection == 2) {
            in >> input[0] >> input[1];
            cout << input[0] << input[1] << endl;
        } else {
            cin >> input[0] >> input[1];
        }
        
        // Check if user wants to end input
        if (input[0] == '0' && input[1] == '0') {
            finished = true;
            break;
        }
        
        // Convert char to index values and reserve seat
        int inputRow = input[0] - 49;
        int inputCol = input[1] - 64;
        if (inputRow < 0 || inputRow > row - 1 || inputCol < 1 || inputCol > col - 1) {
            cout << "Invalid seat." << endl;
        } else if (seatMap[inputRow][inputCol] == 'X') {
            cout << "Seat has already been reserved." << endl;
        } else {
            seatMap[inputRow][inputCol] = 'X';
            count--;
        }
        
        // Display array
        cout << "\nUpdated Seat Map: " << endl;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cout << seatMap[i][j] << ' ';
            }
            cout << endl;
        }
        
        // Check if seats have been filled
        if (count == 0) {
            cout << "\nAll seats have been filled." << endl;
            finished = true;
            break;
        }
    }
    
    delete [] seatMap;
    
    return 0;
}

/* START CONSOLE OUTPUT
 Choose input method:
 (1) Console
 (2) File
 2
 Enter the number of rows (up to 9): 7

 Seat Map:
 1 A B C D
 2 A B C D
 3 A B C D
 4 A B C D
 5 A B C D
 6 A B C D
 7 A B C D

 Enter seat to reserve (e.g. 3B), or 00 to finish: 1A

 Updated Seat Map:
 1 X B C D
 2 A B C D
 3 A B C D
 4 A B C D
 5 A B C D
 6 A B C D
 7 A B C D

 Enter seat to reserve (e.g. 3B), or 00 to finish: 1B

 Updated Seat Map:
 1 X X C D
 2 A B C D
 3 A B C D
 4 A B C D
 5 A B C D
 6 A B C D
 7 A B C D

 Enter seat to reserve (e.g. 3B), or 00 to finish: 2C

 Updated Seat Map:
 1 X X C D
 2 A B X D
 3 A B C D
 4 A B C D
 5 A B C D
 6 A B C D
 7 A B C D

 Enter seat to reserve (e.g. 3B), or 00 to finish: 4C

 Updated Seat Map:
 1 X X C D
 2 A B X D
 3 A B C D
 4 A B X D
 5 A B C D
 6 A B C D
 7 A B C D

 Enter seat to reserve (e.g. 3B), or 00 to finish: 6B

 Updated Seat Map:
 1 X X C D
 2 A B X D
 3 A B C D
 4 A B X D
 5 A B C D
 6 A X C D
 7 A B C D

 Enter seat to reserve (e.g. 3B), or 00 to finish: 7C

 Updated Seat Map:
 1 X X C D
 2 A B X D
 3 A B C D
 4 A B X D
 5 A B C D
 6 A X C D
 7 A B X D

 Enter seat to reserve (e.g. 3B), or 00 to finish: 7D

 Updated Seat Map:
 1 X X C D
 2 A B X D
 3 A B C D
 4 A B X D
 5 A B C D
 6 A X C D
 7 A B X X

 Enter seat to reserve (e.g. 3B), or 00 to finish: 00
 Program ended with exit code: 0
END CONSOLE OUTPUT */
