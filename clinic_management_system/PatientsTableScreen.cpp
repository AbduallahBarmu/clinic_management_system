#include "PatientsTableScreen.h"
#include "patientProfile.h"
#include "PatientEntity.h"
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

    PatientEntity show_DB;
    show_DB.dispPatDatabase();
}


PatientsTableScreen::~PatientsTableScreen()
{
    //dtor
}



