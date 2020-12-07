#include "WelcomeScreen.h"
#include "UiHelper.h"
#include "ChangePasswordScreen.h"
#include "MainMenuScreen.h"
#include <iostream>
#include <string>
using namespace std;

WelcomeScreen::WelcomeScreen()
{
    int choice = -1;
    string feedback = "";
    while(choice != 0)
    {
        system("cls");
        UiHelper::printTitle("WELCOME TO MEDIPOL CLINIC MANAGEMENT SYSTEM");
        UiHelper::printHorizontalLine();
        UiHelper::printChoice("1.Main Menu");
        UiHelper::printChoice("2.Change Password");
        UiHelper::printChoice("0.Exit");
        UiHelper::printHorizontalLine();
        UiHelper::printFeedback(feedback);
        feedback = "";
        cout<<"\nEnter the number corresponding to your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            MainMenuScreen();
            break;
        }
        case 2:
        {
            ChangePasswordScreen();
            break;
        }
        case 0:
        {
            break;
        }
        default:
            feedback = "Please, Enter a valid option.";
        }
    }
}

WelcomeScreen::~WelcomeScreen()
{
    //dtor
}
