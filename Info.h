//
// Created by tanze on 8/14/2018.
//

#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Pc.h"
#include "User.h"

class Info {
public:
    void LoadUser(); // Load User.txt
    void LoadPc(); // Load Pc.txt
    void LoadCash(); // Load Cash.txt
    void SetIncome(double new_income) { income = new_income; }; // Change income
    void SetOutcome(double new_outcome) { outcome = new_outcome; }; // Change outcome
    double GetIncome() { return income; };
    double GetOutcome() { return outcome; };
    vector<Pc> PcArray; // Store all Pcs in vector
    vector<User> UserArray; // Store all users in vector
private:
    double income; // Total income
    double outcome; // Total outcome
};

#endif
