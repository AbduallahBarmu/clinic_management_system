#include "PharmacyTableScreen.h"
#include "UiHelper.h"
#include <iostream>
#include <string>
#include "PharmacyEntity.h"

PharmacyTableScreen::PharmacyTableScreen()
{
    system("cls");
    UiHelper::printTitle("PHARMACY TABLE");
    UiHelper::printHorizontalLine();
    int choice = -1;
    string feedback = "";
    PharmacyEntity m;
    m.dispDatabase();
}

PharmacyTableScreen::~PharmacyTableScreen()
{
    //dtor
}
