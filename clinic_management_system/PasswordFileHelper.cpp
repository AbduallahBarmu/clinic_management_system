#include "PasswordFileHelper.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

string PasswordFileHelper::getPassword()
{
    char inputChar;
    string inputString = "";
    int i;
    while(true)
    {
        inputChar = _getch();
        if (inputChar == 13)
            break;
        else if(inputChar == 8)
        {
            if(inputString.length() > 0)
            {
                cout << "\b \b";
                inputString.erase(std::prev(inputString.end()));
            }
        }
        else
        {
            inputString += inputChar;
            _putch('*');
        }

    };
    return inputString;
}

bool PasswordFileHelper::checkPasswordFileExists()
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

string PasswordFileHelper::readPasswordFile()
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

void PasswordFileHelper::writePasswordFile(string password)
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
