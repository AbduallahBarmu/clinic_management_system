#include "NewMedicineScreen.h"
#include "UiHelper.h"
#include <iostream>
#include <string>

NewMedicineScreen::NewMedicineScreen()
{
    system("cls");
    UiHelper::printTitle("NEW MEDICINE");
    UiHelper::printHorizontalLine();
    int choice = -1;
    string feedback = "";
    cout<<"\nNot implemented yet, Enter any number to continue: ";
    cin>>choice;
}

NewMedicineScreen::~NewMedicineScreen()
{
    //dtor
}
