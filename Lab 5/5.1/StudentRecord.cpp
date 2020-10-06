//
//  StudentRecord.cpp
//  CMPE 50 Lab Project
//  Lab 5.1
//
//  Created by Alexander Shapiro on 10/5/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
using namespace std;

class StudentRecord {
private:
    double quiz1;
    double quiz2;
    double midtermExam;
    double finalExam;
    double weightedAverage;
    
public:
    StudentRecord() {
        quiz1 = 0;
        quiz2 = 0;
        midtermExam = 0;
        finalExam = 0;
        weightedAverage = 0;
    }
    
    void setQuiz1(double score) {
        if (score >= 0) quiz1 = score;
        else {
            cout << "Score cannot be negative." << endl;
            exit(1);
        }
        
    }
    void setQuiz2(double score) {
        if (score >= 0) quiz2 = score;
        else {
            cout << "Score cannot be negative." << endl;
            exit(1);
        }
    }
    void setMidtermExam(double score) {
        if (score >= 0) midtermExam = score;
        else {
            cout << "Score cannot be negative." << endl;
            exit(1);
        }
    }
    void setFinalExam(double score) {
        if (score >= 0) finalExam = score;
        else {
            cout << "Score cannot be negative." << endl;
            exit(1);
        }
    }
    
    double getQuiz1() { return quiz1; }
    double getQuiz2() { return quiz2; }
    double getMidtermExam() { return midtermExam; }
    double getFinalExam() { return finalExam; }
    double getWeightedAverage() { return weightedAverage; }
    
    void calculateWeightedAverage() {
        weightedAverage = ((((quiz1 + quiz2) / 20) * 0.25) + ((midtermExam / 100) * 0.25) + ((finalExam / 100) * 0.5)) * 100;
    }
};

int main() {
    StudentRecord student1;
    
    double val;
    cout << "Enter Quiz 1 Score out of 10: ";
    cin >> val;
    student1.setQuiz1(val);
    cout << "Enter Quiz 2 Score out of 10: ";
    cin >> val;
    student1.setQuiz2(val);
    cout << "Enter Midterm Exam Score out of 100: ";
    cin >> val;
    student1.setMidtermExam(val);
    cout << "Enter Final Exam Score out of 100: ";
    cin >> val;
    student1.setFinalExam(val);
    
    student1.calculateWeightedAverage();
    
    cout << "The weighted average is: " << student1.getWeightedAverage() << endl;
    
    
    return 0;
}

/* START CONSOLE OUTPUT
 Enter Quiz 1 Score: 9
 Enter Quiz 2 Score: 8.5
 Enter Midterm Exam Score: 78.25
 Enter Final Exam Score: 92
 The weighted average is: 87.4375
 Program ended with exit code: 0
END CONSOLE OUTPUT */
