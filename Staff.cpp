//
// Created by tanze on 8/14/2018.
//

#include "Staff.h"

extern Info lib;
extern Log rec;
extern string account;

void Staff::AddPc() { // Add new Pcs
    system("cls");
    Pc newPc;
    string money, number, category, price, name, model, usage, discount, disc_num, information;
    cout << "Please input the model number of the Pc" << endl;
    getline(cin,model); // Input model number of this new Pc
    for (size_t i = 0; i < lib.PcArray.size(); i++)
        if (lib.PcArray[i].GetModel() == model) {
            cout << "This model number already exist =. =" << endl; // model number already exist
            Sleep(1000);
            return;
        }
    cout << "Please input the company of the Pc" << endl;
    getline(cin,name); // Input Pcname
    cout << "Please input the usage of the Pc" << endl;
    getline(cin,usage); // Input usage
    cout << "Please input the copy number of the Pc" << endl;
    while (1) {
        getline(cin,number); // Input copy number
        if (IsAllDigit(number)) break;
        cout << "Please input a digital number :)   Try again." << endl;
    }
    cout << "Please input the category of the Pc" << endl;
    getline(cin,category); // Input category number
    cout << "Please input the price of the Pc" << endl;
    while (1) {
        getline(cin,price); // Input price
        if (IsAllDigit(price)) break;
        cout << "Please input a digital number :)   Try again." << endl;
    }
    cout << "Please input the discount of the Pc" << endl;
    while (1) {
        getline(cin,discount); // Input discount
        if (IsAllDigit(discount)) break;
        cout << "Please input a digital number :)   Try again." << endl;
    }
    cout << "Please input the number of the Pc at least that can give a discount " << endl;
    while (1) {
        getline(cin,disc_num); // Input disc_num
        if (IsAllDigit(disc_num)) break;
        cout << "Please input a digital number :)   Try again." << endl;
    }
    cout << "Please input some information of this Pc" << endl;
    getline(cin,information); // Input detail information
    cout << "Please input the money that those Pc costs" << endl;
    while (1) {
        getline(cin,money); // Input the cost of those Pc
        if (IsAllDigit(money)) break;
        cout << "Please input a digital number :)   Try again." << endl;
    }
    newPc.SetCName(name);
    newPc.SetModel(model);
    newPc.SetUsage(usage);
    newPc.SetNumber(stoi(number));
    newPc.SetCategory(category);
    newPc.SetPrice(stod(price));
    newPc.SetDiscount(stod(discount));
    newPc.SetDisc_num(stoi(disc_num));
    newPc.SetInformation(information);
    lib.PcArray.push_back(newPc); // Add this newPc to lib.PcArray
    cout << "Add Pc successful!~ " << endl;
    Sleep(1000);
    cout << "automatically quit after 3 seconds." << endl;
    Sleep(2000);
    rec.PcLog(account, model, "add", stoi(number)); // Update PcLog.txt with "add" operation
    rec.CashLog(account, model, "add", stod(money)); // Update CashLog.txt with "add" operation
    PrintPcArray(); // Output Pc information to Pc.txt
    PrintCash(); // Output cash information to Cash.txt
}

void Staff::DelPc() { // Delete some Pcs
    system("cls");
    string model, temp;
    cout << "Please input the model number of the Pc that you want to delete " << endl;
    getline(cin,model); // Input model number of the Pc that you want to delete
    for (size_t i = 0; i < lib.PcArray.size(); i++)
        if (lib.PcArray[i].GetModel() == model) {
            cout << "There are " << lib.PcArray[i].GetNumber() << " copies of this Pc, how many do you want to delete?  " << endl;
            while (1) {
                getline(cin,temp); // Input how many Pcs you want to delete
                if (IsAllDigit(temp)) break;
                cout << "Please input a digital number :)   Try again." << endl;
            }
            if (stoi(temp) > lib.PcArray[i].GetNumber()) { // Pc number is not enough to delete
                cout << "Pc number is not that much! " << endl;
                Sleep(1000);
                cout << "automatically quit after 3 seconds." << endl;
                Sleep(3000);
            } else {
                lib.PcArray[i].SetNumber(lib.PcArray[i].GetNumber() - stoi(temp)); // Change number of this Pc in lib.PcArray
                cout << "Deleted (" << stoi(temp) << ") this Pc successfully!~ " << endl;
                Sleep(1000);
                cout << "automatically quit after 3 seconds." << endl;
                Sleep(2000);
                rec.PcLog(account, model, "del", stoi(temp)); // Update PcLog.txt with "del" operation
                PrintPcArray(); // Output Pc information to Pc.txt
            }
            return;
        }
    cout << "Not found this Pc! " << endl; // Pc not exist in Pc.txt
    Sleep(1000);
}

void Staff::SetPc() { // Change Pcs' information
    system("cls");
    int choice;
    string number, category, price, name, model, usage, discount, disc_num, information;
    cout << "Please input the model number of the Pc that you want to change the information." << endl;
    getline(cin,model); // Input model number of the Pc that you want to change information
    for (size_t i = 0; i < lib.PcArray.size(); i++)
        if (lib.PcArray[i].GetModel() == model ) {
            cout << "Do you want to change the company of the Pc? (input 1 for YES and 0 for NO )" << endl;
            cin >> choice;
            getchar();
            if (choice == 1) {
                cout << "Please input the new company of the Pc" << endl;
                getline(cin,name); // Input new Pcname
                lib.PcArray[i].SetCName(name);
            }
            cout << "Do you want to change the model number of the Pc? (input 1 for YES and 0 for NO )" << endl;
            cin >> choice;
            getchar();
            if (choice == 1) {
                cout << "Please input the new model number of the Pc" << endl;
                getline(cin,model); // Input new model number
                lib.PcArray[i].SetModel(model);
            }
            cout << "Do you want to change the usage of the Pc? (input 1 for YES and 0 for NO )" << endl;
            cin >> choice;
            getchar();
            if (choice == 1) {
                cout << "Please input the new usage of the Pc" << endl;
                getline(cin,usage); // Input new usage
                lib.PcArray[i].SetUsage(usage);
            }
            /*cout << "Do you want to change the copy number of the Pc? (input 1 for YES and 0 for NO )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please input the new copy number of the Pc" << endl;
                while (1) {
                    cin >> number;
                    if (IsAllDigit(number)) break;
                    cout << "Please input a digital number :)   Try again." << endl;
                }
                lib.PcArray[i].SetNumber(stoi(number));
            }*/
            cout << "Do you want to change the category of the Pc? (input 1 for YES and 0 for NO )" << endl;
            cin >> choice;
            getchar();
            if (choice == 1) {
                cout << "Please input the new category of the Pc" << endl;
                getline(cin,category); // Input new category
                lib.PcArray[i].SetCategory(category);
            }
            cout << "Do you want to change the price of the Pc? (input 1 for YES and 0 for NO )" << endl;
            cin >> choice;
            getchar();
            if (choice == 1) {
                cout << "Please input the new price of the Pc" << endl;
                while (1) {
                    getline(cin,price); // Input new price
                    if (IsAllDigit(price)) break;
                    cout << "Please input a digital number :)   Try again." << endl;
                }
                lib.PcArray[i].SetPrice(stod(price));
            }
            cout << "Do you want to change the discount of the Pc? (input 1 for YES and 0 for NO )" << endl;
            cin >> choice;
            getchar();
            if (choice == 1) {
                cout << "Please input the new discount of the Pc" << endl;
                while (1) {
                    getline(cin,discount); // Input new discount
                    if (IsAllDigit(discount)) break;
                    cout << "Please input a digital number :)   Try again." << endl;
                }
                lib.PcArray[i].SetDiscount(stod(discount));
            }
            cout << "Do you want to change the disc_num of the Pc? (input 1 for YES and 0 for NO )" << endl;
            cin >> choice;
            getchar();
            if (choice == 1) {
                cout << "Please input the new disc_num of the Pc" << endl;
                while (1) {
                    getline(cin,disc_num); // Input new disc_num
                    if (IsAllDigit(disc_num)) break;
                    cout << "Please input a digital number :)   Try again." << endl;
                }
                lib.PcArray[i].SetDisc_num(stoi(disc_num));
            }
            cout << "Do you want to change the information of the Pc? (input 1 for YES and 0 for NO )" << endl;
            cin >> choice;
            getchar();
            if (choice == 1) {
                cout << "Please input the new information of the Pc" << endl;
                getline(cin,information); // Input new detail information
                lib.PcArray[i].SetInformation(information);
            }
            cout << "Change of Pc information successful!~ " << endl;
            Sleep(1000);
            cout << "automatically quit after 3 seconds." << endl;
            Sleep(2000);
            rec.PcLog(account, model, "set", 0); // Update PcLog.txt with "set" operation
            PrintPcArray(); // Output Pc information to Pc.txt
            return;
        }
    cout << "Not found this Pc! " << endl; // Pc not exist in Pc.txt
    Sleep(1000);
}

void Staff::ViewProfit() { // Lookup net profit
    system("cls");
    string temp;
    cout << "Total income: " << lib.GetIncome() << endl;
    cout << "Total outcome: " << lib.GetOutcome() << endl;
    cout << "Total net profit: " << lib.GetIncome() - lib.GetOutcome() << endl;
    cout << "Input 0 to exit" << endl;
    getline(cin,temp);
    while (temp != "0")
        getline(cin,temp);
}

void Staff::Interface(string username) { // Staff interface
    string command;
    int stop = 0;
    string str;
    while (1) {
        system("cls");
        cout << "Welcome! " << username << " You are staff~" << endl;
        cout << "Please choose what you want to do by inputting a number " << endl;
        while (1) { // The operation list
            cout << "1 ----- Add new Pc" << endl;
            cout << "2 ----- Delete Pc" << endl;
            cout << "3 ----- Change Pc information" << endl;
            cout << "4 ----- List Pc (ALL)" << endl;
            cout << "5 ----- List Pc (By Category)" << endl;
            cout << "6 ----- List Pc (By Name)" << endl;
            cout << "7 ----- Show more Pc information by model number" << endl;
            cout << "8 ----- Lookup net profit" << endl;
            cout << "9 ----- Change my password" << endl;
            cout << "0 ----- Exit;" << endl;
            getline(cin,command);
            if (command[0] < '0' || command[0] > '9') { // If command doesn't match input rule
                cout << endl << "Wrong!! You should input number between 0-9 " << endl;
                cout << "Please reselect a number :) " << endl; // Ask to input again
            } else break;
        }
        switch (command[0]) {
            case '1':
                AddPc(); // Add new Pcs
                break;
            case '2':
                DelPc(); // Delete some Pcs
                break;
            case '3':
                SetPc(); // Change Pcs' information
                break;
            case '4':
                ListPcAll(); // List all Pc
                break;
            case '5':
                ListPcByC(); // List Pc by category
                break;
            case '6':
                ListPcByN(); // List Pc by company
                break;
            case '7':
                PcInfor(); // See more information of one Pc
                break;
            case '8':
                ViewProfit(); // Lookup profit
                break;
            case '9':
                ChangePsw(); // Change password
                break;
            case '0':
                stop = 1;
                cout << "System will quit after 3 seconds " <<endl;
                Sleep(3000);
                break;
        }
        if (stop) break;
    }
}