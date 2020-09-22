//
//  merge.cpp
//  CMPE 50 Lab Project
//  Lab 3.3
//
//  Created by Alexander Shapiro on 9/7/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void merge(ifstream *in1, ifstream *in2, ofstream *out) {
    in1->open("input1.txt");
    if (in1->fail()) {
        cout << "Input 1 file opening failed.\n";
        exit(1);
    }
    
    in2->open("input2.txt");
    if (in2->fail()) {
        cout << "Input 2 file opening failed.\n";
        exit(1);
    }
    
    out->open("output.txt");
    if (out->fail()) {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    
    // Populate arrays from input
    int first[100];
    int second[100];
    
    int count1 = 0;
    while (*in1 >> first[count1++]) { }
    count1--;

    int count2 = 0;
    while (*in2 >> second[count2++]) { }
    count2--;
    
    // Merge arrays
    int merged[count1 + count2];
    
    for (int i = 0; i < count1; i++) {
        merged[i] = first[i];
    }
    
    for (int i = 0; i < count2; i++) {
           merged[count1 + i] = second[i];
    }
    
    // Sort merged array
    int length = count1 + count2;
    for (int i = length-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (merged[j] > merged[j+1]) {
            // Swap the numbers
            int temp = merged[j+1];
            merged[j+1] = merged[j];
            merged[j] = temp;
            }
        }
    }
    
    // Output to file
    for (int i = 0; i < length; i++) {
        *out << merged[i]
        << endl;
    }
}

int main() {
    ifstream in1;
    ifstream in2;
    ofstream out;
    
    merge(&in1, &in2, &out);
    
    in1.close();
    in2.close();
    out.close();
    
    return 0;
}

/* START CONSOLE OUTPUT
 Program ended with exit code: 0
END CONSOLE OUTPUT */
