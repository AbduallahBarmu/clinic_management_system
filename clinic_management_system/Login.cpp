#include "Login.h"
#include "WelcomeScreen.h"
#include "UiHelper.h"
#include "passwordFileHelper.h"
#include <iostream>
#include <string>

using namespace std;

Login::Login()
{
    hash<string> str_hash;
    string feedback = "", input;

    if(PasswordFileHelper::checkPasswordFileExists())
    {
        string password;
        password = PasswordFileHelper::readPasswordFile();

        while(true)
        {
            system("cls");
            UiHelper::printTitle("LOGIN TO MEDIPOL CLINIC MANAGEMENT SYSTEM");
            UiHelper::printHorizontalLine();
            UiHelper::printFeedback(feedback);
            cout<<"\nPlease enter your password: ";
            feedback = "";

            // cin>>input;
            input = PasswordFileHelper::getPassword();

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

            // cin>>input;
            input = PasswordFileHelper::getPassword();

            for (char const &c: input)
            {
                passwordLenth++;
            }
            if(passwordLenth >= 8)
            {
                PasswordFileHelper::writePasswordFile(to_string(str_hash(input)));
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
