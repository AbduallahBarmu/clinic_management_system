#include "DoctorsTableScreen.h"
#include "UiHelper.h"
#include <iostream>
#include <string>

DoctorsTableScreen::DoctorsTableScreen()
{
    system("cls");
    UiHelper::printTitle("DOCTORS TABLE");
    UiHelper::printHorizontalLine();
    int choice = -1;
    string feedback = "";
    cout<<"\nFiles are empty at the moment, enter any number to continue: ";
    cin>>choice;
}

DoctorsTableScreen::~DoctorsTableScreen()
{
    //dtor
}
