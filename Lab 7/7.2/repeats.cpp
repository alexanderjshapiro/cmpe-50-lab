//
//  repeats.cpp
//  CMPE 50 Lab Project
//  Lab 7.2
//
//  Created by Alexander Shapiro on 10/26/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
using namespace std;

char* deleteRepeats(const char str[100], int size) {
    char* unique = new char[size];
    int uniqueCount = 1;
    unique[0] = str[0];
    
    for (int i = 0; i < size; i++) {
        bool isUnique = true;
        for (int j = 0; j < uniqueCount; j++) {
            if (str[i] == unique[j]) {
                isUnique = false;
            }
        }
        if (isUnique) {
            unique[uniqueCount++] = str[i];
        }
    }
    
    char* noRepeat = new char[uniqueCount];
    for (int i = 0; i < uniqueCount; i++) {
        noRepeat[i] = unique[i];
    }
    
    return noRepeat;
}

int main() {
    char str[100] = "to be or not to be";
    int size = int(strlen(str));
    char* noRepeat;
    noRepeat = deleteRepeats(str, size);

    cout << noRepeat << endl;
    
    return 0;
}

/* START CONSOLE OUTPUT
 to bern
 Program ended with exit code: 0
END CONSOLE OUTPUT */
