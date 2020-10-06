//
//  gender.cpp
//  CMPE 50 Lab Project
//  Lab 4.2
//
//  Created by Alexander Shapiro on 9/21/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

// Write a program that can be used to train the user to use less sexist language by suggesting alternative versions of sentences given by the user. The program will ask for a sentence, read the sentence into a string variable, and replace all occurrences of masculine pronouns with gender-neutral pronouns. For example, it will replace “he” with “she or he”, and “him” with “her or him”. Thus, the input sentence
//
//See an adviser, talk to him, and listen to him.
//
//should produce the following suggested changed version of the sentence:
//
//See an adviser, talk to her or him, and listen to her or him.
//
//Be sure to preserve uppercase letters for the first word of the sentence. The pronoun “his” can be replaced by “her(s) or his”; your program need not decide between “her” and “hers”. Allow the user to repeat this for more sentences until the user says she or he is done.


#include <iostream>
using namespace std;

int main() {
    int selection = 2;
    while (selection != 1) {
        string word;
        string sentence;
        cout << "Enter sentence to be corrected:\n";
        while(word.back() != '.' && cin >> word) {
            string punctuation;
            if (!isalpha(word.back())) {
                punctuation = word.back();
            }
            
            if (word.find("Hers") == 0 && word.length() == 4) {
                word = "His or hers" + punctuation;
            } else if (word.find("Her") == 0 && word.length() == 3) {
                word = "Him or her" + punctuation;
            } else if (word.find("She's") == 0 && word.length() == 4) {
                word = "He or she's" + punctuation;
            } else if (word.find("She") == 0 && word.length() == 3) {
                word = "He or she" + punctuation;
            } else if (word.find("His") == 0 && word.length() == 3) {
                word = "His or hers" + punctuation;
            } else if (word.find("Him") == 0 && word.length() == 3) {
                word = "Him or her" + punctuation;
            } else if (word.find("He's") == 0 && word.length() == 4) {
                word = "He or she's" + punctuation;
            } else if (word.find("He") == 0 && word.length() == 2) {
                word = "He or she" + punctuation;
            }
            
            if (word.find("hers") == 0 && word.length() == 4) {
                word = "his or hers" + punctuation;
            } else if (word.find("her") == 0 && word.length() == 3) {
                word = "him or her" + punctuation;
            } else if (word.find("she's") == 0 && word.length() == 4) {
                word = "he or she's" + punctuation;
            } else if (word.find("she") == 0 && word.length() == 3) {
                word = "he or she" + punctuation;
            } else if (word.find("his") == 0 && word.length() == 3) {
                word = "his or hers" + punctuation;
            } else if (word.find("him") == 0 && word.length() == 3) {
                word = "him or her" + punctuation;
            } else if (word.find("he's") == 0 && word.length() == 4) {
                word = "he or she's" + punctuation;
            } else if (word.find("he") == 0 && word.length() == 2) {
                word = "he or she" + punctuation;
            }
            
            sentence += word  + " ";
        }
        
        cout << sentence << endl;
        
        cout << "\nAre you done?\n"
        << "(1) Yes, exit program\n"
        << "(2) No, continue with new input\n"
        << endl;
        cin >> selection;
    }
    
    return 0;
}

/* START CONSOLE OUTPUT
 Enter sentence to be corrected:
 He washes the dishes with her.
 He or she washes the dishes with him or her.

 Are you done?
 (1) Yes, exit program
 (2) No, continue with new input

 2
 Enter sentence to be corrected:
 Alas, he's not ready to go here or there.
 Alas, he or she's not ready to go here or there.

 Are you done?
 (1) Yes, exit program
 (2) No, continue with new input

 1
 Program ended with exit code: 0
END CONSOLE OUTPUT */
