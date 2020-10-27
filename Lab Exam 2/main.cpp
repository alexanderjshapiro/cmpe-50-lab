//
//  main.cpp
//  CMPE 50 Lab Project
//  Lab Exam 2
//
//  Created by Alexander Shapiro on 10/20/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

void replaceDigits() {
    // Declare and open file streams
    ifstream in;
    ofstream out;
    
    in.open("input.txt");
    if (in.fail()) {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    
    out.open("output.txt");
    if (in.fail()) {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    
    // Get input from file
    string input;
    string output;
    string num[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    while(in >> input) {
        // Find and replace digit with text
        if (input.find("0") == 0) {
            input = num[0];
        } else if (input.find("1") == 0) {
            input = num[1];
        } else if (input.find("2") == 0) {
            input = num[2];
        } else if (input.find("3") == 0) {
            input = num[3];
        } else if (input.find("4") == 0) {
            input = num[4];
        } else if (input.find("5") == 0) {
            input = num[5];
        } else if (input.find("6") == 0) {
            input = num[6];
        } else if (input.find("7") == 0) {
            input = num[7];
        } else if (input.find("8") == 0) {
            input = num[8];
        } else if (input.find("9") == 0) {
            input = num[9];
        }
        
        output += input + " ";
    }
    
    // Output to file and close
    cout << output << "\n" << endl;
    out << output << endl;
    
    in.close();
    out.close();
}

class Diner {
private:
    string name;
    string category;
    int ratings[5];
    double averageRating;
    
public:
    Diner(string dinerName, string dinerCategory) {
        name = dinerName;
        category = dinerCategory;
        ratings[0] = 0;
        ratings[1] = 0;
        ratings[2] = 0;
        ratings[3] = 0;
        ratings[4] = 0;
    }
    string getName() {
        return name;
    }
    
    string getCategory() {
        return category;
    }
    
    int* getRatings() {
        return ratings;
    }
    
    void addRating(int rating) {
        switch (rating) {
            case 1:
                ratings[0]++;
                break;
                
            case 2:
                ratings[1]++;
                break;
                
            case 3:
                ratings[2]++;
                break;
                
            case 4:
                ratings[3]++;
                break;
                
            case 5:
                ratings[4]++;
                break;
                
            default:
                break;
        }
    }
    
    double getAverage() {
        averageRating = (1 * ratings[0] + 2 * ratings[1] + 3 * ratings[2] + 4 * ratings[3] + 5 * ratings[4]) / double(ratings[0] + ratings[1] + ratings[2] + ratings[3] + ratings[4]);
        return averageRating;
    }
    
    friend bool equalRating(Diner& dinerOne, Diner& dinerTwo) {
        if (dinerOne.getAverage() == dinerTwo.getAverage()) {
            return true;
        } else {
            return false;
        }
    }
};

void dinerTest() {
    Diner dinerOne("Bob's Pizza", "American");
    Diner dinerTwo("Alice's Bakery", "Bakery");
    
    dinerOne.addRating(5);
    dinerOne.addRating(4);
    dinerOne.addRating(4);
    dinerOne.addRating(3);
    dinerOne.addRating(2);
    
    dinerTwo.addRating(5);
    dinerTwo.addRating(1);
    dinerTwo.addRating(4);
    dinerTwo.addRating(3);
    dinerTwo.addRating(4);
    
    cout << "Diner One: " << dinerOne.getName() << " (" << dinerOne.getCategory() <<"), average rating of " << dinerOne.getAverage() << " stars." << endl;
    cout << "Diner Two: " << dinerTwo.getName() << " (" << dinerTwo.getCategory() <<"), average rating of " << dinerTwo.getAverage() << " stars." << endl;
    cout << "Their ratings are ";
    if (!equalRating(dinerOne, dinerTwo)) {
        cout << "not ";
    }
    cout << "equal.\n" << endl;
}

int main() {
    int selection;
    do {
        cout << "Select an option:\n"
        << "(1) execute sentences program\n"
        << "(2) execute Diner test program\n"
        << "(3) end the program\n"
        << endl;
        cin >> selection;
        cout << endl;
        
        switch (selection) {
            case 1:
                replaceDigits();
                break;
                
            case 2:
                dinerTest();
                break;
                
            case 3:
                break;
                
            default:
                break;
        }
    } while (selection != 3);
    
    return 0;
}

/* START CONSOLE OUTPUT
 Select an option:
 (1) execute sentences program
 (2) execute Diner test program
 (3) end the program

 1

 The price of the cup is four dollars. But it's on sale today at two for six dollars. If you buy more, you can get three for eight dollars.

 Select an option:
 (1) execute sentences program
 (2) execute Diner test program
 (3) end the program

 2

 Diner One: Bob's Pizza (American), average rating of 3.6 stars.
 Diner Two: Alice's Bakery (Bakery), average rating of 3.4 stars.
 Their ratings are not equal.

 Select an option:
 (1) execute sentences program
 (2) execute Diner test program
 (3) end the program

 3

 Program ended with exit code: 0
END CONSOLE OUTPUT */
