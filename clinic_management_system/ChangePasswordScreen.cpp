#include "ChangePasswordScreen.h"
#include "WelcomeScreen.h"
#include "Login.h"
#include "UiHelper.h"
#include <iostream>
#include <string>
#include <fstream>
#include "passwordFileHelper.h"
#include <conio.h>

using namespace std;

void showNewPasswordScreen()
{
    hash<string> str_hash;
    int passwordLenth = 0;
    string feedback = "", input;
    while(true)
    {
        system("cls");
        UiHelper::printTitle("CHANGE PASSWORD");
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

void showChangePasswordSuccess()
{
    system("cls");
    UiHelper::printTitle("CHANGE PASSWORD");
    UiHelper::printHorizontalLine();
    UiHelper::printFeedback("Your password has been changed successfully");
    cout<<"\nEnter anything to go back to main menu: ";
}

ChangePasswordScreen::ChangePasswordScreen()
{
    hash<string> str_hash;
    string feedback = "";

    if(PasswordFileHelper::checkPasswordFileExists())
    {
        string password, input;
        password = PasswordFileHelper::readPasswordFile();

        while(true)
        {
            system("cls");
            UiHelper::printTitle("CHANGE PASSWORD");
            UiHelper::printHorizontalLine();
            UiHelper::printFeedback(feedback);
            cout<<"\nEnter your old password: ";
            feedback = "";

            // cin>>input;
            input = PasswordFileHelper::getPassword();

            if(password == to_string(str_hash(input)))
            {
                showNewPasswordScreen();
                showChangePasswordSuccess();

                cin >> input;

                break;
            }
            else
                feedback = "Wrong password, try again";
        }
    }
    else
    {
        cout << "\nSomething went wrong" << endl;
        exit(1);
    }
}

ChangePasswordScreen::~ChangePasswordScreen()
{
    //dtor
}
