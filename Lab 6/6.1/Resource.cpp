//
//  Resource.cpp
//  CMPE 50 Lab Project
//  Lab 6.1
//
//  Created by Alexander Shapiro on 10/12/20.
//  Copyright © 2020 Alexander Shapiro. All rights reserved.
//

#include <iostream>
using namespace std;

class Resource {
private:
    int status;
    int writeTo;
    
public:
    Resource() {
        status = 0;
        writeTo = 0;
    }
    
    Resource(int val) {
        status = 0;
        if (val == 0 || val == 1) {
            writeTo = val;
        } else {
            cout << "writeTo value must be 0 or 1." << endl;
            exit(1);
        }
    }
    
    int getStatus() const {
        return status;
    }
    
    int getWriteTo() const{
        return writeTo;
    }
    
    void setStatus(int val) {
        if (val == 0 || val == 1) {
            status = val;
        } else {
            cout << "status value must be 0 or 1." << endl;
            exit(1);
        }
    }
    
    void setWriteTo(int val) {
        if (val == 0 || val == 1) {
            writeTo = val;
        } else {
            cout << "writeTo value must be 0 or 1." << endl;
            exit(1);
        }
    }
    
    void outputStatus(ostream& out) {
        out << status;
    }

    friend bool checkStatus(const Resource& res1, const Resource& res2) {
        if (res1.status == 1 && res2.status == 1) {
            cout << "Resource Available" << endl;
            return true;
        } else {
            cout << "Resource Unavailable" << endl;
            return false;
        }
    }
};

int main() {
    Resource resource1, resource2(1);
    
    cout << "Resource 1 status: ";
    resource1.outputStatus(cout);
    cout << "\n";
    cout << "Resource 2 status: ";
    resource2.outputStatus(cout);
    cout << "\n";
    
    checkStatus(resource1, resource2);
    
    resource1.setStatus(1);
    resource2.setStatus(1);
    
    cout << "Resource 1 status: ";
    resource1.outputStatus(cout);
    cout << "\n";
    cout << "Resource 2 status: ";
    resource2.outputStatus(cout);
    cout << "\n";
    
    checkStatus(resource1, resource2);
    
    return 0;
}

/* START CONSOLE OUTPUT
 Resource 1 status: 0
 Resource 2 status: 0
 Resource Unavailable
 Resource 1 status: 1
 Resource 2 status: 1
 Resource Available
 Program ended with exit code: 0
END CONSOLE OUTPUT */
