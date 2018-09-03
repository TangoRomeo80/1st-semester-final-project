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
        cerr << "User.txt can't be opened" << endl;
        abort(); // Exit
    }
    for (size_t i = 0; i < lib.UserArray.size(); i++ ) // Output each user's information
        fout << lib.UserArray[i].GetUsername() << "_" << lib.UserArray[i].GetPassword() << "_" << lib.UserArray[i].GetStatus() << endl;
    fout.close(); // Close User.txt
}

void User::PrintPcArray() { // Output Pc information to Pc.txt
    ofstream fout;
    fout.open("Pc.txt"); // Open and cover Pc.txt
    if  (!fout) { // If can't open
        cerr << "Pc.txt can't be opened" << endl;
        abort(); // Exit
    }
    for (size_t i = 0; i < lib.PcArray.size(); i++ ) // Output each Pc's information
        fout << lib.PcArray[i].GetCName() << "_" << lib.PcArray[i].GetModel() << "_" << lib.PcArray[i].GetUsage()
             << "_" << lib.PcArray[i].GetNumber() << "_" << lib.PcArray[i].GetCategory()
             << "_" << lib.PcArray[i].GetPrice() << "_" << lib.PcArray[i].GetDiscount()
             << "_" << lib.PcArray[i].GetDisc_num() << "_" << lib.PcArray[i].GetInformation() << endl;
    fout.close(); // Close Pc.txt
}

void User::PrintCash() { // Output cash information to Cash.txt
    ofstream fout;
    fout.open("Cash.txt"); // Open and cover Cash.txt
    if (!fout) { // If can't open
        cerr << "Cash.txt can't be opened" << endl;
        abort(); // Exit
    }
    fout << lib.GetIncome() << endl; // Output income
    fout << lib.GetOutcome() << endl; // Output outcome
    fout.close(); // Close Pc.txt
}

int User::IsAllDigit(const string& str) { // Check if str is all made of digital number
    int i ;
    for(i = 0; i != str.length(); i++)
        if (!isdigit(str[i]) && (str[i]!='.')) return 0; // '.' for double number
    return 1;
}

void User::ListPcAll() { // List all Pc
    system("cls");
    string temp;
    cout << "This is the list of all the Pc:" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "|       Model       |             Name            | Number |    Price    |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    for (size_t i = 0; i < lib.PcArray.size(); i++) { // Output each Pc information
        cout << "|" << setw(18) << lib.PcArray[i].GetModel() << "|" <<  setw(29) << lib.PcArray[i].GetCName() <<  "|"
             <<  setw(8) << lib.PcArray[i].GetNumber() << "|"<<  setw(13) << setiosflags(ios::fixed) << setprecision(2) <<lib.PcArray[i].GetPrice()  << "|" << endl;
    }
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Input 0 to exit" << endl;
    getline(cin,temp);
    while (temp[0]!= '0')
        getline(cin,temp);
}

void User::ListPcByC() { // List Pc by category
    system("cls");
    string temp, category;
    cout << "Please input the category that you want to list: " << endl;
    while (true) {
        getline(cin,category);
        if (IsAllDigit(category)) break;
        cout << "Pleass input a digital number :)   Try again." << endl;
    }
    system("cls");
    cout << "This is the list of all the Pc in category " << category << " :" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "|       Model       |             Name            | Number |    Price    |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    for (size_t i = 0; i < lib.PcArray.size(); i++) // Output each Pc information in this category
        if (lib.PcArray[i].GetCategory() == (category)) {
            cout << "|" << setw(18) << lib.PcArray[i].GetModel() << "|" <<  setw(29) << lib.PcArray[i].GetCName() <<  "|"
                 <<  setw(8) << lib.PcArray[i].GetNumber() << "|"<<  setw(13) << setiosflags(ios::fixed) << setprecision(2) <<lib.PcArray[i].GetPrice()  << "|" << endl;
        }
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Input 0 to exit" << endl;
    getline(cin,temp);
    while (temp[0]!= '0')
        getline(cin,temp);
}

void User::ListPcByN() { // List Pc by company
    system("cls");
    string temp, name;
    cout << "Please input the company that you want to find: " << endl;
    getline(cin,name);
    system("cls");
    cout << "This is the list of all the Pc that company contains string \"" << name << " \" :" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "|       Model       |             Name            | Number |    Price    |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    for (size_t i = 0; i < lib.PcArray.size(); i++) // Output each Pc information match this company
        if (lib.PcArray[i].GetCName().find(name) != string::npos) {
            cout << "|" << setw(18) << lib.PcArray[i].GetModel() << "|" <<  setw(29) << lib.PcArray[i].GetCName() <<  "|"
                 <<  setw(8) << lib.PcArray[i].GetNumber() << "|"<<  setw(13) << setiosflags(ios::fixed) << setprecision(2) <<lib.PcArray[i].GetPrice()  << "|" << endl;
        }
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Input 0 to exit" << endl;
    getline(cin,temp);
    while (temp[0]!= '0')
        getline(cin,temp);
}

void User::PcInfor() { // See more information of one Pc
    system("cls");
    string temp, model;
    cout << "Please input the model number of the Pc that you want to find: " << endl;
    getline(cin,model);
    for (size_t i = 0; i < lib.PcArray.size(); i++)
        if (lib.PcArray[i].GetModel() == model ) { // If exist, list its detail information
            system("cls");
            cout << "Detail information of the Pc with model number " << model << " : " << endl;
            cout << "Name            : " << lib.PcArray[i].GetCName() << endl;
            cout << "Usage            : " << lib.PcArray[i].GetUsage() << endl;
            cout << "Number            : " << lib.PcArray[i].GetNumber() << endl;
            cout << "Category        : " << lib.PcArray[i].GetCategory() << endl;
            cout << "Price            : " << setiosflags(ios::fixed) << setprecision(2) << lib.PcArray[i].GetPrice() << endl;
            cout << "Discount        : " << setiosflags(ios::fixed) << setprecision(2) << lib.PcArray[i].GetDiscount()  << endl;
            cout << "Discount_num        : " << lib.PcArray[i].GetDisc_num() << endl;
            cout << "Information        : " << lib.PcArray[i].GetInformation() << endl;
            cout << endl;
            cout << "Input 0 to exit" << endl;
            getline(cin,temp);
            while (temp[0]!= '0')
                getline(cin,temp);
            return;
        }
    cout << "This Pc not found! " << endl;
    Sleep(1000);
}

void User::ChangePsw() { // User choose to change his or her password
    system("cls");
    string temp, password;
    cout << "Please input the new password that you want: " << endl;
    getline(cin,password);
    cout << "Please repeat it: " << endl;
    getline(cin,temp);
    if (temp != password) { // If two input are not match then exit
        cout << "Two password doesn't match!! Changing password failed... " << endl;
        Sleep(1500);
        return;
    } else {
        for (size_t i = 0; i < lib.PcArray.size(); i++)
            if (lib.UserArray[i].GetUsername() == account )
                lib.UserArray[i].SetPassword(password); // Change password
        cout << "Password changed successfully !~~ " << endl;
        rec.UserLog(account, account, "psw", 0); // Update UserLog.txt with "psw" operation
        PrintUserArray(); // Output user information to User.txt
        Sleep(2000);
    }
}