#include "NewPatientScreen.h"
#include "UiHelper.h"
#include <iostream>
#include <string>
#include "PatientEntity.h"

// table 3

NewPatientScreen::NewPatientScreen()
{
    system("cls");
    UiHelper::printTitle("NEW PATIENT");
    UiHelper::printHorizontalLine();
    int choice = -1;
    string feedback = "";

    PatientEntity p;
    p.addPat();




}


NewPatientScreen::~NewPatientScreen()
{
    //dtor
}
