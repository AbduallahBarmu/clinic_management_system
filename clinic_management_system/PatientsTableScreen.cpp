#include "PatientsTableScreen.h"

#include "UiHelper.h"
#include <iostream>
#include <string>

PatientsTableScreen::PatientsTableScreen()
{
    system("cls");
    UiHelper::printTitle("PATIENT TABLE");
    UiHelper::printHorizontalLine();
    int choice = -1;
    string feedback = "";
    cout<<"\nFiles are empty at the moment, enter any number to continue: ";
    cin>>choice;
}

PatientsTableScreen::~PatientsTableScreen()
{
    //dtor
}
