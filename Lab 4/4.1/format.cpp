//
//  format.cpp
//  CMPE 50 Lab Project
//  Lab 4.1
//
//  Created by Alexander Shapiro on 9/21/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    string word;
    string sentence;
    cout << "Enter sentence to be corrected:\n";
    while(word.back() != '.' && cin >> word) {
        for (char character : word) {
            sentence += tolower(character);
        }
        sentence += " ";
    }
    
    sentence[0] = toupper(sentence[0]);
    
    cout << sentence << endl;
    return 0;
}

/* START CONSOLE OUTPUT
 Enter sentence to be corrected:
    noW  iS   thE    TiMe  fOr  aLl
          gOOD MEN TO  ComE TO   tHe
           aId
 oF


    ThE  CounTRY.
 Now is the time for all good men to come to the aid of the country.
 Program ended with exit code: 0
END CONSOLE OUTPUT */
