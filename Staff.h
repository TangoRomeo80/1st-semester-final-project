//
// Created by tanze on 8/14/2018.
//

#ifndef STAFF_H
#define STAFF_H

#include "User.h"
#include "Info.h"

class Staff : public User {
public:
    void AddPc(); // Add new Pcs
    void DelPc(); // Delete some Pcs
    void SetPc(); // Change Pcs' information
    void Interface(string username); // Staff interface
protected:
    void ViewProfit(); // Lookup net profit
};

#endif
