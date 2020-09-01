//
//  grades.cpp
//  CMPE 50 Lab Project
//  Lab 2.3
//
//  Created by Alexander Shapiro on 8/30/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    const int TYPES_OF_ASSIGNMENTS = 2, ROW_METRICS = 1, ASSIGNMENTS_PER_TYPE = 5, COLUMN_METRICS = 3;
    double val[TYPES_OF_ASSIGNMENTS + ROW_METRICS][ASSIGNMENTS_PER_TYPE + COLUMN_METRICS];
    
    // Input the HW assignments
    cout << "Please enter five homework scores [0 – 100]:\n";
    for (int i = 0; i < ASSIGNMENTS_PER_TYPE; i++) {
        cin >> val[0][i];
    }
    
    // Input the exams
    cout << "Please enter five lab scores [0 – 100]:\n";
    for (int i = 0; i < ASSIGNMENTS_PER_TYPE; i++) {
        cin >> val[1][i];
    }
    
    // Find best, worst, and average values
    for (int r = 0; r < TYPES_OF_ASSIGNMENTS; r++) {
        // Set initial values to compare against
        val[r][5] = -1;
        val[r][6] = 101;
        val[r][7] = 0;
        
        for (int c = 0; c < ASSIGNMENTS_PER_TYPE; c++) {
            // Find the intermediate best score
            if (val[r][c] > val[r][5]) {
                val[r][5] = val[r][c];
            }
            
            // Find the intermediate best score
            if (val[r][c] < val[r][6]) {
                val[r][6] = val[r][c];
            }
            
            // Find the average score
            val[r][7] += val[r][c];
        }
        
        // Divide to get average
        val[r][7] /= (ASSIGNMENTS_PER_TYPE);
    }
    
    for  (int c = 0; c < ASSIGNMENTS_PER_TYPE; c++) {
        val[2][c] = (val[0][c] + val[1][c]) / 2;
    }
    
    
    double grade = (val[0][7] + val[1][7]) / 2;
    bool passed = false;
    string failedComponent;
    if (val[0][7] >= 50 && val[1][7] >= 50) {
        passed = true;
    } else {
        if (val[0][7] < 50 && val[1][7] < 50) {
            failedComponent = "homework and lab";
        } else if (val[0][7] < 50) {
            failedComponent = "homework";
        } else if (val[1][7] < 50){
            failedComponent = "lab";
        } else {
            failedComponent = "some component";
        }
    }
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    
    cout << "        1      2      3      4      5     BEST  WORST   AVG  \n"
         << "     ********************************************************\n";
    
    cout << "HW   ";
    for (int i = 0; i < ASSIGNMENTS_PER_TYPE + COLUMN_METRICS; i++) {
        cout.width(7);
        cout << val[0][i];
    }
    cout << "\n";
    
    cout << "LAB  ";
    for (int i = 0; i < ASSIGNMENTS_PER_TYPE + COLUMN_METRICS; i++) {
        cout.width(7);
        cout << val[1][i];
    }
    cout << "\n\n";
    
    cout << "AVG  ";
    for (int i = 0; i < ASSIGNMENTS_PER_TYPE; i++) {
        cout.width(7);
        cout << val[2][i];
    }
    cout << " Overall: " << grade << "\n\n";

    if (passed) {
        cout << "Congratulations! You passed the class!\n";
    } else {
        cout << "I’m sorry to inform you that you failed the class, because your performance in " << failedComponent << " was <50%. Try again next semester.\n";
    }
    
    return 0;
}

/* START CONSOLE OUTPUT
 Please enter five homework scores [0 – 100]:
 100.00  90.00  80.00 100.00 100.00
 Please enter five lab scores [0 – 100]:
 100.00 100.00  70.00  60.00  90.00
         1      2      3      4      5     BEST  WORST   AVG
      ********************************************************
 HW    100.00  90.00  80.00 100.00 100.00 100.00  80.00  94.00
 LAB   100.00 100.00  70.00  60.00  90.00 100.00  60.00  84.00

 AVG   100.00  95.00  75.00  80.00  95.00 Overall: 89.00

 Congratulations! You passed the class!
 Program ended with exit code: 0
END CONSOLE OUTPUT */
