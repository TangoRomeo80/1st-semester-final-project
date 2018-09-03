//
// Created by tanze on 8/14/2018.
//

#include "Log.h"
#include "Pc.h"
#include "User.h"
#include "Staff.h"
#include "Admin.h"
#include "Info.h"
#include "Customer.h"
#include "Password.h"

Log rec;
Info lib;
Password pwd;
string account;

int Login(string username, string password) { // Get user's status
    for (size_t i = 0; i < lib.UserArray.size(); i++ )
        if (username == lib.UserArray[i].GetUsername() && password == lib.UserArray[i].GetPassword()) // If find username and password in User.txt
            return lib.UserArray[i].GetStatus(); // Return status
    return 0;
}

void LoadData() { // Load all data from .txt
    lib.LoadUser(); // Load User.txt
    lib.LoadPc(); // Load Pc.txt
    lib.LoadCash(); // Load Cash.txt
}

void Welcome() { // Welcome interface
    system("cls");
    int status = 4;
    int time = 0;
    string choice;
    cout << "----------------------------------------\n";
    cout << "Welcome to RAMO Pc Store Management System \n";
    cout << "----------------------------------------\n"<< endl;
    cout << "Are you a customer or staff?\n\n1.Customer\n2.Staff\n";
    getline(cin,choice);
    if(choice[0]=='1'){
        status=3;
        Customer man;
        man.Interface(account);
    }
    else if(choice[0]=='2'){
        status=0;
    }
    while (status == 0) {
        cout << "Please login first~" << endl;
        cout << "Username: " << endl;
        getline(cin,account); // Input username
        cout << "Password: " << endl;
        pwd.InputPassword(); // Input password without showing what you input
        status = Login(account, pwd.GetPassword()); // Get user's status
        if (account == "Rahat" && pwd.GetPassword() == "bleh") status = 1; // Setter admin
        if (status < 1 || status > 3) {
            time++; // Try how many times
            if (time < 3) cout << "Oops! Login fail :(     Please try again.. " << endl;
            else if (time < 4) cout << "Are you sure you remember the password? = =   (Try again... " << endl;
            else if (time < 5) cout << "Oh My God ... give you one last chance.." << endl;
            else {
                cout << "Maybe you should register a new account = =" << endl; // Failed too many times, force to exit
                Sleep(1500);
                return;
            }
            Sleep(1500);
        } else { // Choose interface depend on status
            if (status == 1) {
                Admin man;
                man.Interface(account);
            } else if (status == 2) {
                Staff man;
                man.Interface(account);
            } else if (status == 3) {
                Customer man;
                man.Interface(account);
            }
            break;
        }
        system("cls");
    }
    while(status==4){
        cout<<"wrong input,use correct input"<<endl;
        getline(cin,choice);
        if(choice[0]=='1'){
            status=3;
            Customer man;
            man.Interface(account);
        }
        else if(choice[0]=='2'){
            status=0;
        }
        while (status == 0) {
            cout << "Please login first~" << endl;
            cout << "Username: " << endl;
            getline(cin,account); // Input username
            cout << "Password: " << endl;
            pwd.InputPassword(); // Input password without showing what you input
            status = Login(account, pwd.GetPassword()); // Get user's status
            if (account == "Rahat" && pwd.GetPassword() == "bleh") status = 1; // Setter admin
            if (status < 1 || status > 3) {
                time++; // Try how many times
                if (time < 3) cout << "Oops! Login fail :(     Please try again.. " << endl;
                else if (time < 4) cout << "Are you sure you remember the password? = =   (Try again... " << endl;
                else if (time < 5) cout << "Oh My God ... give you one last chance.." << endl;
                else {
                    cout << "Maybe you should register a new account = =" << endl; // Failed too many times, force to exit
                    Sleep(1500);
                    return;
                }
                Sleep(1500);
            } else { // Choose interface depend on status
                if (status == 1) {
                    Admin man;
                    man.Interface(account);
                } else if (status == 2) {
                    Staff man;
                    man.Interface(account);
                } else if (status == 3) {
                    Customer man;
                    man.Interface(account);
                }
                break;
            }
            system("cls");
        }
    }
}

int main() {
    LoadData(); // Load all data from .txt
    Welcome(); // Welcome interface
    return 0;
}