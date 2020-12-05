//
//  main.cpp
//  CMPE 50 Lab Project
//  Lab Exam 3
//
//  Created by Alexander Shapiro on 11/17/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
#include "Stack.h"
using namespace std;

void reverseCString(char str[], int length) {
    char* front = str;
    char* rear = str + (length - 1);
    char temp;
    
    for (int i = 0; i < (length / 2); i++) {
        temp = *front;
        *front = *rear;
        *rear = temp;
        
        front++;
        rear--;
    }
    
    for (int i = 0; i < length; i++) {
        cout << str[i];
    }
    cout << endl;
}

void reverseCString() {
    int length;
    cout << "Enter length of string: ";
    cin >> length;
    char* array = new char[length];
    cout << "Enter string to be reversed: ";
    cin >> array;
    reverseCString(array, length);
}

int main() {
    int selection = 0;

    while (selection != 3) {
        cout << "Select an option:\n"
        << "(1) test reverseCString\n"
        << "(2) test Stack\n"
        << "(3) exit" << endl;
        
        cin >> selection;
        if (selection == 1) {
            char saturday[] = { 'S', 'a', 't', 'u', 'r', 'd', 'a', 'y' };
            char wednesday[] = { 'w', 'e', 'd', 'n', 'e', 's', 'd', 'a', 'y' };
            reverseCString(saturday, 8);
            reverseCString(wednesday, 9);
            reverseCString();
        } else if (selection == 2) {
            Stack stk1;
            for (int num = 1; num <= 20; num++) {
                stk1.addLast(num);
            }
            cout << "stk1 = " << stk1 << endl;
            
            Stack stk2(stk1);
            Stack stk3;
            
            while (!stk2.isEmpty()) {
                stk3.addLast(stk2.getLast());
                stk2.deleteLast();
            }
            
            stk1 = stk3;
            
            cout << "stk1 = " << stk1 << endl;
            cout << "stk2 = " << stk2 << endl;
            cout << "stk3 = " << stk3 << endl;
        } else if (selection == 3) {
            cout << "Exiting program" << endl;
        } else {
            cout << "Invalid selection" << endl;
        }
        cout << endl;
    }
    
    return 0;
}

/* START CONSOLE OUTPUT
 Select an option:
 (1) test reverseCString
 (2) test Stack
 (3) exit
 1
 yadrutaS
 yadsendew
 Enter length of string: 5
 Enter string to be reversed: hello
 olleh

 Select an option:
 (1) test reverseCString
 (2) test Stack
 (3) exit
 2
 stk1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 }
 stk1 = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }
 stk2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
 stk3 = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }

 Select an option:
 (1) test reverseCString
 (2) test Stack
 (3) exit
 3
 Exiting program

 Program ended with exit code: 0
END CONSOLE OUTPUT */
