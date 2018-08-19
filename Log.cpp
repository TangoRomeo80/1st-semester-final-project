//
// Created by tanze on 8/14/2018.
//

#include "Log.h"
#include "Info.h"
#include "windows.h"

extern Info lib;

void Log::UserLog(string loginname, string username, string operation, int status) { // Add new information to UserLog.txt
    ofstream fout;
    fout.open("UserLog.txt", ios::app); // Open and append to UserLog.txt
    if (!fout) { // If can't open
        cerr << "UserLog.txt can't be opened" << endl;
        abort(); // Exit
    }
    SYSTEMTIME sys;
    GetLocalTime(&sys); // Get system time
    fout << "[ " << sys.wYear << "-" << sys.wMonth << "-" << sys.wDay << " " << sys.wHour << ":" << sys.wMinute << ":" << sys.wSecond << " ]"; // Output system tiime
    if (operation == "add")
        fout << " Admin(" << loginname << ") add a new user(" << username << ")" << endl;
    else if (operation == "del")
        fout << " Admin(" << loginname << ") delete a user(" << username << ")" << endl;
    else if (operation == "set")
        fout << " Admin(" << loginname << ") set user(" << username << ")'s status to (" << status <<") " << endl;
    else if (operation == "psw")
        fout << " User(" << loginname << ") change his/her password " << endl;
    fout.close(); // Close UserLog.txt
}

void Log::PcLog(string loginname, string Pcmodel, string operation, int number) { // Add new information to PcLog.txt
    ofstream fout;
    fout.open("PcLog.txt", ios::app); // Open and append to PcLog.txt
    if (!fout) { // If can't open
        cerr << "PcLog.txt can't be opened" << endl;
        abort(); // Exit
    }
    SYSTEMTIME sys;
    GetLocalTime(&sys); // Get system time
    fout << "[ " << sys.wYear << "-" << sys.wMonth << "-" << sys.wDay << " " << sys.wHour << ":" << sys.wMinute << ":" << sys.wSecond << " ]"; // Output system tiime
    if (operation == "buy")
        fout << " Customer(" << loginname << ") buy Pcs(model:" << Pcmodel << ") with " << number << " copy(s)" << endl;
    else if (operation == "ref")
        fout << " Customer(" << loginname << ") refund Pcs(model:" << Pcmodel << ") with " << number << " copy(s)" << endl;
    else if (operation == "add")
        fout << " Manager(" << loginname << ") add new Pcs(model:" << Pcmodel << ") with " << number << " copy(s)" << endl;
    else if (operation == "del")
        fout << " Manager(" << loginname << ") delete Pcs(model:" << Pcmodel << ") with " << number << " copy(s)" << endl;
    else if (operation == "set")
        fout << " Manager(" << loginname << ") change Pc(model:" << Pcmodel << ")'s information " << endl;
    fout.close(); // Close PcLog.txt
}

void Log::CashLog(string loginname, string Pcmodel, string operation, double money) { // Add new information to CashLog.txt
    ofstream fout;
    fout.open("CashLog.txt", ios::app); // Open and append to PcLog.txt
    if (!fout) { // If can't open
        cerr << "CashLog.txt can't be opened" << endl;
        abort(); // Exit
    }
    SYSTEMTIME sys;
    GetLocalTime(&sys); // Get system time
    fout << "[ " << sys.wYear << "-" << sys.wMonth << "-" << sys.wDay << " " << sys.wHour << ":" << sys.wMinute << ":" << sys.wSecond << " ]"; // Output system tiime
    if (operation == "add") {
        fout << " Manager(" << loginname << ") add new Pcs(model:" << Pcmodel << ") ---------- Outcome: " << money << endl;
        lib.SetOutcome(money + lib.GetOutcome());
    } else if (operation == "buy") {
        fout << " Customer(" << loginname << ") buy Pcs(model:" << Pcmodel << ") ---------- Income: " << money << endl;
        lib.SetIncome(money + lib.GetIncome());
    } else if (operation == "ref") {
        fout << " Customer(" << loginname << ") refund Pcs(model:" << Pcmodel << ") ---------- Outcome: " << money << endl;
        lib.SetOutcome(money + lib.GetOutcome());
    }
    fout.close(); // Close CashLog.txt
}

