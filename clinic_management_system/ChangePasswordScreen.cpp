#include "ChangePasswordScreen.h"

#include "UiHelper.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

ChangePasswordScreen::ChangePasswordScreen()
{
    system("cls");
    string password;
    UiHelper::printTitle("CHANGE PASSWORD");
    UiHelper::printHorizontalLine();
    cout<<"\nEnter your old password: ";
    cin>>password;
    cout<<"\nEnter your new password: ";
    cin>>password;
}

ChangePasswordScreen::~ChangePasswordScreen()
{
    //dtor
}
