#include "PharmacyTableScreen.h"
#include "UiHelper.h"
#include <iostream>
#include <string>

PharmacyTableScreen::PharmacyTableScreen()
{
    system("cls");
    UiHelper::printTitle("PHARMACY TABLE");
    UiHelper::printHorizontalLine();
    int choice = -1;
    string feedback = "";
    cout<<"\nFiles are empty at the moment, enter any number to continue: ";
    cin>>choice;
}

PharmacyTableScreen::~PharmacyTableScreen()
{
    //dtor
}
