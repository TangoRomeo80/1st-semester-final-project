//
// Created by tanzem on 8/14/2018.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "Info.h"

class Customer : public User {
public:
    void BuyPc(); // Customer buy Pcs
    void Refund(); // Customer ask for refund
    void Interface(string username); // Customer interface
};

#endif