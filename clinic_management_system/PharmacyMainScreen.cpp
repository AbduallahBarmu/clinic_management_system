#include "PharmacyMainScreen.h"
#include "PharmacyTableScreen.h"
#include "NewMedicineScreen.h"
#include "UiHelper.h"
#include <iostream>
#include <string>

PharmacyMainScreen::PharmacyMainScreen()
{
    int choice = -1;
    string feedback = "";
    while(choice != 0)
    {
        system("cls");
        UiHelper::printTitle("PHARMACY MAIN MENU");
        UiHelper::printHorizontalLine();
        UiHelper::printChoice("1.Add New Medicine");
        UiHelper::printChoice("2.Show Pharmacy Table");
        UiHelper::printChoice("0.Back");
        UiHelper::printHorizontalLine();
        UiHelper::printFeedback(feedback);
        feedback = "";
        cout<<"\nEnter the number corresponding to your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            NewMedicineScreen();
            break;
        }
        case 2:
        {
            PharmacyTableScreen();
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

PharmacyMainScreen::~PharmacyMainScreen()
{
    //dtor
}
