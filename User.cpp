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

void User::PrintPcArray() { // Output Pc information to Pc.txt
    ofstream fout;
    fout.open("Pc.txt"); // Open and cover Pc.txt
    if  (!fout) { // If can't open
        cerr << "Pc.txt can't open" << endl;
        abort(); // Exit
    }
    for (size_t i = 0; i < lib.PcArray.size(); i++ ) // Output each Pc's information
        fout << lib.PcArray[i].GetCName() << " " << lib.PcArray[i].GetModel() << " " << lib.PcArray[i].GetUsage()
             << " " << lib.PcArray[i].GetNumber() << " " << lib.PcArray[i].GetCategory()
             << " " << lib.PcArray[i].GetPrice() << " " << lib.PcArray[i].GetDiscount()
             << " " << lib.PcArray[i].GetDisc_num() << " " << lib.PcArray[i].GetInformation() << endl;
    fout.close(); // Close Pc.txt
}

void User::PrintCash() { // Output cash information to Cash.txt
    ofstream fout;
    fout.open("Cash.txt"); // Open and cover Cash.txt
    if (!fout) { // If can't open
        cerr << "Cash.txt can't open" << endl;
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
    cin >> temp;
    while (temp != "0")
        cin >> temp;
}

void User::ListPcByC() { // List Pc by category
    system("cls");
    string temp, category;
    cout << "Please input the category that you want to list: " << endl;
    while (1) {
        cin >> category;
        if (IsAllDigit(category)) break;
        cout << "Pleass input a digital number :)   Try again." << endl;
    }
    system("cls");
    cout << "This is the list of all the Pc in category " << category << " :" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "|       Model       |             Name            | Number |    Price    |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    for (size_t i = 0; i < lib.PcArray.size(); i++) // Output each Pc information in this category
        if (lib.PcArray[i].GetCategory() == stoi(category)) {
            cout << "|" << setw(18) << lib.PcArray[i].GetModel() << "|" <<  setw(29) << lib.PcArray[i].GetCName() <<  "|"
                 <<  setw(8) << lib.PcArray[i].GetNumber() << "|"<<  setw(13) << setiosflags(ios::fixed) << setprecision(2) <<lib.PcArray[i].GetPrice()  << "|" << endl;
        }
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Input 0 to exit" << endl;
    cin >> temp;
    while (temp != "0")
        cin >> temp;
}

void User::ListPcByN() { // List Pc by company
    system("cls");
    string temp, name;
    cout << "Please input the company that you want to find: " << endl;
    cin >> name;
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
    cin >> temp;
    while (temp != "0")
        cin >> temp;
}

void User::PcInfor() { // See more information of one Pc
    system("cls");
    string temp, model;
    cout << "Please input the model number of the Pc that you want to find: " << endl;
    cin >> model;
    for (size_t i = 0; i < lib.PcArray.size(); i++)
        if (lib.PcArray[i].GetModel() == model ) { // If exist, list its detail information
            system("cls");
            cout << "Detail information of the Pc with model number " << model << " : " << endl;
            cout << "Name            : " << lib.PcArray[i].GetCName() << endl;
            cout << "Author            : " << lib.PcArray[i].GetUsage() << endl;
            cout << "Number            : " << lib.PcArray[i].GetNumber() << endl;
            cout << "Category        : " << lib.PcArray[i].GetCategory() << endl;
            cout << "Price            : " << setiosflags(ios::fixed) << setprecision(2) << lib.PcArray[i].GetPrice() << endl;
            cout << "Discount        : " << setiosflags(ios::fixed) << setprecision(2) << lib.PcArray[i].GetDiscount()  << endl;
            cout << "Disc_num        : " << lib.PcArray[i].GetDisc_num() << endl;
            cout << "Information        : " << lib.PcArray[i].GetInformation() << endl;
            cout << endl;
            cout << "Input 0 to exit" << endl;
            cin >> temp;
            while (temp != "0")
                cin >> temp;
            return;
        }
    cout << "Not found this Pc! " << endl;
    Sleep(1000);
}

void User::ChangePsw() { // User choose to change his or her password
    system("cls");
    string temp, password;
    cout << "Please input the new password that you want: " << endl;
    cin >> password;
    cout << "Please repeat it: " << endl;
    cin >> temp;
    if (temp != password) { // If two input are not match then exit
        cout << "Two password doesn't match!! Change password failed... " << endl;
        Sleep(1500);
        return;
    } else {
        for (size_t i = 0; i < lib.PcArray.size(); i++)
            if (lib.UserArray[i].GetUsername() == account )
                lib.UserArray[i].SetPassword(password); // Change password
        cout << "Password change successfully !~~ " << endl;
        rec.UserLog(account, account, "psw", 0); // Update UserLog.txt with "psw" operation
        PrintUserArray(); // Output user information to User.txt
        Sleep(2000);
    }
}
