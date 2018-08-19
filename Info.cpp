//
// Created by tanzeem on 8/14/2018.
//

#include "Info.h"

void Info::LoadUser() { // Load User.txt
    User olduser;
    string str;
//  ofstream fout("User.txt");
    ifstream fin("User.txt"); // Open and read User.txt
    if(!fin) { // If can't open
        cerr << "User.txt can't open" << endl;
        abort(); // Exit
    }
    while (getline(fin, str)) {
        size_t i = str.find(" "); // Find fisrt spacebar
        olduser.SetUsername(str.substr(0, i)); // Divide str by spacebar and get username
        str = str.substr(i+1);

        i = str.find(" "); // Find second spacebar
        olduser.SetPassword(str.substr(0, i)); // Divide str by spacebar and get password
        olduser.SetStatus(stoi(str.substr(i+1))); // Divide str by spacebar and get status

        UserArray.push_back(olduser); // Add to lib.UserArray
    }
    fin.close(); // Close User.txt
}

void Info::LoadPc() { // Load Pc.txt
    Pc oldPc;
    string str;
//  ofstream fout("Pc.txt");
    ifstream fin("Pc.txt"); // Open and read Pc.txt
    if(!fin) { // If can't open
        cerr << "Pc.txt can't be opened" << endl;
        abort(); // Exit
    }
    while (getline(fin, str)) {
        size_t i = str.find(" "); // Find fisrt spacebar
        oldPc.SetCName(str.substr(0, i)); // Divide str by spacebar and get Pcname
        str = str.substr(i+1);

        i = str.find(" "); // Find second spacebar
        oldPc.SetModel(str.substr(0, i)); // Divide str by spacebar and get model number
        str = str.substr(i+1);

        i = str.find(" ");
        oldPc.SetUsage(str.substr(0, i)); // Divide str by spacebar and get usage
        str = str.substr(i+1);

        i = str.find(" ");
        oldPc.SetNumber(stoi(str.substr(0, i))); // Divide str by spacebar and get copy number
        str = str.substr(i+1);

        i = str.find(" ");
        oldPc.SetCategory(stoi(str.substr(0, i))); // Divide str by spacebar and get category number
        str = str.substr(i+1);

        i = str.find(" ");
        oldPc.SetPrice(stoi(str.substr(0, i))); // Divide str by spacebar and get price
        str = str.substr(i+1);

        i = str.find(" ");
        oldPc.SetDiscount(stod(str.substr(0, i))); // Divide str by spacebar and get discount
        str = str.substr(i+1);

        i = str.find(" ");
        oldPc.SetDisc_num(stoi(str.substr(0, i))); // Divide str by spacebar and get disc_num
        oldPc.SetInformation(str.substr(i+1)); // Divide str by spacebar and get more Pc information

        PcArray.push_back(oldPc); // Add to lib.PcArray
    }
    fin.close(); // Close Pc.txt
}

void Info::LoadCash() { // Load Cash.txt
//    ofstream fout("Cash.txt");
    ifstream fin("Cash.txt"); // Open and read Pc.txt
    if(!fin) { // If can't open
        cerr << "Cash.txt can't be opened" << endl;
        abort(); // Exit
    }
    fin >> income; // Input income
    fin >> outcome; // Input outcome
    fin.close(); // Close Cash.txt
}
