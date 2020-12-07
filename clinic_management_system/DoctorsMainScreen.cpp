#include "DoctorsMainScreen.h"
#include "DoctorsTableScreen.h"
#include "NewDoctorScreen.h"
#include "UiHelper.h"
#include <iostream>
#include <string>


DoctorsMainScreen::DoctorsMainScreen()
{
    int choice = -1;
    string feedback = "";
    while(choice != 0)
    {
        system("cls");
        UiHelper::printTitle("DOCTORS MAIN MENU");
        UiHelper::printHorizontalLine();
        UiHelper::printChoice("1.Add New Doctor");
        UiHelper::printChoice("2.Show Doctors Table");
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
            NewDoctorScreen();
            break;
        }
        case 2:
        {
            DoctorsTableScreen();
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

DoctorsMainScreen::~DoctorsMainScreen()
{
    //dtor
}
