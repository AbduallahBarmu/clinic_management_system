#include "NewMedicineScreen.h"
#include "PharmacyEntity.h"
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
    PharmacyEntity m;
    m.addMed();
    cout<<"\n\n\n\nEnter 1 to return to Pharmacy Database\nEnter 2 to Exit."<<endl;
	cin>>choice;
	if(choice==1){
	  system("cls");
	  //getDoctorDatabase();
      //DoctorsMainScreen();
	}else
	  exit(0);

}

NewMedicineScreen::~NewMedicineScreen()
{
    //dtor
}
