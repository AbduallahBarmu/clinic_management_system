#include "NewPatientScreen.h"
#include "UiHelper.h"
#include <iostream>
#include <string>

NewPatientScreen::NewPatientScreen()
{
    system("cls");
    UiHelper::printTitle("NEW PATIENT");
    UiHelper::printHorizontalLine();
    int choice = -1;
    string feedback = "";
    cout<<"\nNot implemented yet, Enter any number to continue: ";
    cin>>choice;
}

NewPatientScreen::~NewPatientScreen()
{
    //dtor
}
