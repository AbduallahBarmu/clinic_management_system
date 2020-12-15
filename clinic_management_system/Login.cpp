#include "Login.h"
#include "WelcomeScreen.h"
#include "UiHelper.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


inline bool checkPasswordFileExists()
{
    ifstream login_file("medipolclinicsys.txt");
    if(login_file.good())
    {
        return true;
        login_file.close();
    }
    else
        return false;

}

string readPasswordFile()
{
    string password = "";
    ifstream login_file("medipolclinicsys.txt");

    if(login_file.is_open())
    {
        login_file >> password;
        login_file.close();
    }
    else
    {
        cout << "\nSomething went wrong" << endl;
        exit(1);
    }
    return password;
}

void writePasswordFile(string password)
{
    ofstream login_file("medipolclinicsys.txt", ios::out);

    if(login_file.is_open())
    {
        login_file << password;
        login_file.close();
    }
    else
    {
        cout << "\nSomething went wrong" << endl;
        exit(1);
    }
}

Login::Login()
{
    // const string DEFAULT_PASSWORD = "MedipolUniversity";
    hash<string> str_hash;
    string feedback = "";
    string input;

    if(checkPasswordFileExists())
    {
        string password;
        password = readPasswordFile();

        while(true)
        {
            system("cls");
            UiHelper::printTitle("LOGIN TO MEDIPOL CLINIC MANAGEMENT SYSTEM");
            UiHelper::printHorizontalLine();
            UiHelper::printFeedback(feedback);
            cout<<"\nPlease enter your password: ";
            feedback = "";
            cin>>input;
            if(password == to_string(str_hash(input)))
                break;
            else
                feedback = "Wrong password, try again";
        }
    }
    else
    {
        int passwordLenth = 0;
        while(true)
        {
            system("cls");
            UiHelper::printTitle("LOGIN TO MEDIPOL CLINIC MANAGEMENT SYSTEM");
            UiHelper::printHorizontalLine();
            UiHelper::printFeedback(feedback);
            feedback = "";
            cout<<"\nPlease enter new password: ";
            cin>>input;
            for (char const &c: input) {
                passwordLenth++;
            }
            if(passwordLenth >= 8)
            {
                writePasswordFile(to_string(str_hash(input)));
                break;
            }
            else
            {
                feedback = "Too short, enter least 8 characters and numbers";
                passwordLenth = 0;
            }
        }
    }
    WelcomeScreen();
}

Login::~Login()
{
    //dtor
}
