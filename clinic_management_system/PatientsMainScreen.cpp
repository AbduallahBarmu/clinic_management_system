#include "PatientsMainScreen.h"
#include "PatientsMainScreen.h"
#include "NewPatientScreen.h"
#include "PatientsTableScreen.h"
#include "patientProfile.h"
#include "UiHelper.h"
#include <iostream>
#include <string>

PatientsMainScreen::PatientsMainScreen()
{
    int choice = -1;
    string feedback = "";
    while(choice != 0)
    {
        system("cls");
        UiHelper::printTitle("PATIENT MAIN MENU");
        UiHelper::printHorizontalLine();
        UiHelper::printChoice("1.Add New Patient");
        UiHelper::printChoice("2.Show Patients Table");
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
            NewPatientScreen();
            break;
        }
        case 2:
        {
            PatientsTableScreen();
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

PatientsMainScreen::~PatientsMainScreen()
{
    //dtor
}
