#include "NewDoctorScreen.h"
#include "DoctorEntity.h"
#include "UiHelper.h"
#include <iostream>
#include <string>

NewDoctorScreen::NewDoctorScreen()
{
    system("cls");
    UiHelper::printTitle("NEW DOCTOR");
    UiHelper::printHorizontalLine();
    int choice = -1;
    string feedback = "";
    DoctorEntity d;
    d.addDoc();
    cout<<"\n\n\n\nEnter 1 to return to Doctor Database\nEnter 2 to Exit."<<endl;
	cin>>choice;
	if(choice==1){
	  system("cls");
	  //getDoctorDatabase();
      //DoctorsMainScreen();
	}else
	  exit(0);

}

NewDoctorScreen::~NewDoctorScreen()
{
    //dtor
}
