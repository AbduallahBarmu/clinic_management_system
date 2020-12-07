#include "NewDoctorScreen.h"
#include "UiHelper.h"
#include <iostream>
#include <string>

NewDoctorScreen::NewDoctorScreen()
{
    system("cls");
    UiHelper::printTitle("NEW DOCTOR");
    UiHelper::printHorizontalLine();
    int choice = -1;
    string feedback = "";
    cout<<"\nNot implemented yet, Enter any number to continue: ";
    cin>>choice;
}

NewDoctorScreen::~NewDoctorScreen()
{
    //dtor
}
