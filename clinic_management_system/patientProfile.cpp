#include "patientProfile.h"
#include "PatientsTableScreen.h"
#include "PatientEntity.h"
#include "UiHelper.h"
#include <iostream>
#include <string>

patientProfile::patientProfile()
{
    system("cls");
    UiHelper::printTitle("Show Patient profile");
    UiHelper::printHorizontalLine();
    int choice = -1;
    string feedback = "";

    patientProfile pat;
    //pat.displayPat() ; // display patient profile function ;



    cin>>choice;
    while(choice != 0)
    {
         system("cls");
         UiHelper::printChoice("1.Edit Patient profile ");
         UiHelper::printChoice("2.Delete Patients profile");
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
             cout<<"Edit function call" << endl;
             // Edit function
              break;
         }
         case 2:
         {
             cout<<"delete function call" << endl;
             //deletePat();  // delete function call
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

patientProfile::~patientProfile()
{
    //dtor
}
