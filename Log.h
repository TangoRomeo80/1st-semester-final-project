//
// Created by tanze on 8/14/2018.
//

#ifndef LOG_H
#define LOG_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Log {
public:
    void UserLog(string loginname, string username, string operation, int status); // Add new information to UserLog.txt
    void PcLog(string loginname, string Pcisbn, string operation, int number); // Add new information to PcLog.txt
    void CashLog(string loginname, string Pcisbn, string operation, double money); // Add new information to CashLog.txt
};

#endif
