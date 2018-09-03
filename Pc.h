//
// Created by tanzeem on 8/14/2018.
//

#ifndef Pc_H
#define Pc_H

#include <string>
#include"User.h"
using namespace std;

class Pc {
public:
    // Get different information of Pc
    string GetCName() { return company; }
    string GetModel() { return model; }
    string GetUsage() { return usage; }
    int GetNumber() { return number; }
    string GetCategory() { return category; }
    double GetPrice() { return price; }
    double GetDiscount() { return discount; }
    int GetDisc_num() { return disc_num; }
    string GetInformation() { return information; }

    // Change different information of Pc
    void SetCName(string new_name) { company = new_name; }
    void SetModel(string new_model) { model = new_model; }
    void SetUsage(string new_usage) { usage = new_usage; }
    void SetNumber(int new_number) { number = new_number; }
    void SetCategory(string new_category) { category = new_category; }
    void SetPrice(double new_price) { price = new_price; }
    void SetDiscount(double new_discount) { discount = new_discount; }
    void SetDisc_num(int new_disc_num) { disc_num = new_disc_num; }
    void SetInformation(string new_imfor) { information = new_imfor; }

    // Calculate the money of buy (num) Pcs
    double NetPrice(int num) {
        if (num > number)
            return ((double)num * price * discount);
        else
            return ((double)num * price);
    }
private:
    string company;
    string model; //  model number
    string usage;
    int number; // The available number of Pc
    string category; // The category type
    double price; // Unit-price of Pc
    double discount; // The discount that give to customer if him buy a lot of Pcs
    int disc_num; // The at least number of Pc that customer can enjoy discount
    string information; // More commentary of that Pc
};

#endif