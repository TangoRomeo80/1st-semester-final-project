//
// Created by tanzeem on 8/14/2018.
//

#include "Customer.h"

extern Log rec;
extern Info lib;
extern string account;

void Customer::BuyPc() { // Customer buy Pcs
    system("cls");
    string model, temp;
    cout << "Please input the model number of the Pc that you want to buy " << endl;
    cin >> model; // Input the model number
    for (size_t i = 0; i < lib.PcArray.size(); i++)
        if (lib.PcArray[i].GetModel() == model) { // If find that model number
            cout << "There are " << lib.PcArray[i].GetNumber() << " copies of this Pc, how many do you want to buy?  " << endl;
            while (1) {
                cin >> temp; // Input how many Pc customer want to buy
                if (IsAllDigit(temp)) break;
                cout << "Pleass input a digital number :)   Try again." << endl;
            }
            if (stoi(temp) > lib.PcArray[i].GetNumber()) { // If Pc is not enough for customer to buy
                cout << "Pc number is not that much! " << endl;
                Sleep(1000);
            } else {
                lib.PcArray[i].SetNumber(lib.PcArray[i].GetNumber() - stoi(temp)); // Decrease the number of this Pc in lib.PcArray
                cout << "Buy " << stoi(temp) << " copies of that Pc, succsessfully!~ " << endl;
                Sleep(1000);
                cout << "System will quit after 3 seconds." << endl;
                Sleep(2000);
                rec.PcLog(account, model, "buy", stoi(temp)); // Update PcLog.txt with "buy" operation
                rec.CashLog(account, model, "buy", lib.PcArray[i].NetPrice(stoi(temp))); // Update CashLog.txt with "buy" operation
                PrintPcArray(); // Output Pc information to Pc.txt
                PrintCash(); // Output cash information to Cash.txt
            }
            return;
        }
    cout << "Not found this Pc! " << endl; // Pc not found in Pc.txt
    Sleep(1000);
}

void Customer::Refund() { // Customer ask for refund
    system("cls");
    string model, temp;
    cout << "Please input the model number of the Pc that you want to ask for refund " << endl;
    cin >> model; // Input the model number
    for (size_t i = 0; i < lib.PcArray.size(); i++)
        if (lib.PcArray[i].GetModel() == model) { // If find that model number
            cout << " How many copies of that Pc do you want toask for refund?  " << endl;
            while (1) {
                cin >> temp; // Input how many Pc customer want to refund
                if (IsAllDigit(temp)) break;
                cout << "Pleass input a digital number :)   Try again." << endl;
            }
            lib.PcArray[i].SetNumber(lib.PcArray[i].GetNumber() + stoi(temp)); // Increase the number of this Pc in lib.PcArray
            cout << "Refund " << stoi(temp) << " copies of that Pcs, succsessfully!~ " << endl;
            Sleep(1000);
            cout << "Automatic quit after 3 seconds." << endl;
            Sleep(2000);
            rec.PcLog(account, model, "ref", stoi(temp)); // Update PcLog.txt with "buy" operation
            rec.CashLog(account, model, "ref", lib.PcArray[i].NetPrice(stoi(temp))); // Update CashLog.txt with "buy" operation
            PrintPcArray(); // Output Pc information to Pc.txt
            PrintCash(); // Output cash information to Cash.txt
            return;
        }
    cout << "This is not our store's Pc! " << endl; // Pc not found in Pc.txt
    Sleep(1000);
}

void Customer::Interface(string username) { // Admin interface
    string command;
    int stop = 0;
    while (1) {
        system("cls");
        cout << "Welcome! " << username << " You are a customer~" << endl;
        cout << "Please choose what you want to do by inputting a number " << endl;
        while (1) { // The operation list
            cout << "1 ----- Buy Pc" << endl;
            cout << "2 ----- Refund" << endl;
            cout << "3 ----- List Pc (ALL)" << endl;
            cout << "4 ----- List Pc (By Category)" << endl;
            cout << "5 ----- List Pc (By Name)" << endl;
            cout << "6 ----- Show more Pc information by model number" << endl;
            //cout << "7 ----- Change my password" << endl;
            cout << "0 ----- Exit;" << endl;
            cin >> command;
            if (command[0] < '0' || command[0] > '7') {
                cout << endl << "Wrong input!! You should input number between 0-7 " << endl;
                cout << "Please reselect a number :) " << endl;
            } else break;
        }
        switch (command[0]) {
            case '1':
                BuyPc(); // Customer buy Pcs
                break;
            case '2':
                Refund(); // Customer ask for refund
                break;
            case '3':
                ListPcAll(); // List all Pc
                break;
            case '4':
                ListPcByC(); // List Pc by category
                break;
            case '5':
                ListPcByN(); // List Pc by company
                break;
            case '6':
                PcInfor(); // See more information of one Pc
                break;
            case '7':
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
