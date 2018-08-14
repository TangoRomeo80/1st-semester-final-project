//
// Created by tanzeem on 010115 AUG F 2018.
//

#include "User.h"
#include "Info.h"

extern Log rec;
extern Info lib;
extern string account;

void User::PrintUserArray() { // Output user information to User.txt
    ofstream fout;
    fout.open("User.txt"); // Open and cover User.txt
    if (!fout) { // If can't open
        cerr << "User.txt can't open" << endl;
        abort(); // Exit
    }
    for (size_t i = 0; i < lib.UserArray.size(); i++ ) // Output each user's information
        fout << lib.UserArray[i].GetUsername() << " " << lib.UserArray[i].GetPassword() << " " << lib.UserArray[i].GetStatus() << endl;
    fout.close(); // Close User.txt
}


