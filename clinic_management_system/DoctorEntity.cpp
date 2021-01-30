#include "DoctorEntity.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include "UiHelper.h"

DoctorEntity::DoctorEntity()
{
    //ctor
}

DoctorEntity::~DoctorEntity()
{
    //dtor
}

string DoctorEntity::getSpec(){
 	string sp;
	cout<<"1.GENERAL_MEDICINE"<<endl;
	cout<<"2.NEUROLOGY"<<endl;
	cout<<"3.ONCOLOGY"<<endl;
	cout<<"4.HAEMATOLOGY"<<endl;
	cout<<"5.GASTROENTEROLOGY"<<endl;
	cout<<"6.GYNAECOLOGY "<<endl;
	int s;

	while (sp.empty()) {
	    cin>>s;
	    switch(s){

		case 1:{
			sp= "GENERAL_MEDICINE";
			break;
		}
		case 2:{
			sp="NEUROLOGY";
			break;
		}
		case 3:{
		    sp="ONCOLOGY";
			break;
		}
		case 4:{
			sp= "HAEMATOLOGY";
			break;
		}
		case 5:{
			sp= "GASTROENTEROLOGY";
			break;
		}
		case 6:{
			sp= "GYNAECOLOGY ";
			break;
		}
		default:{
			cout<<"\nCome on!Enter a valid option."<<endl;

		}

	}
	}

		return sp;

}

void DoctorEntity::addDoc()
{
    DoctorEntity d;

    cout<<"Fill up the following details"<<endl;
    cout << "Doctor ID consists of 8 numbers"<<endl;
    cin>>d.d_ID;
    while (d.d_ID.length() != 8) {
        //cout << d.d_ID.length();
        cout <<endl<< "Enter ID consists of 8 digit ";
        cin>>d.d_ID;
    }
    cout<<"First Name:"<<endl;
    cin>>d.d_fname;
    //cin.getline(input,(d.d_fname));
    cout<<"Last Name:"<<endl;
    cin>>d.d_lname;
    //cin.getline(input,(d.d_lname));
    cout<<"Age:"<<endl;
    cin>>d.d_age;
    while (d.d_age < 25 || d.d_age > 85) {
        cout << "come on! , Enter a valid age!";
        cin>>d.d_age;
    }


    cout<<"Choose Qualification among the following:\n1.MBBS\n2.MD"<<endl;
    int q;
    cin>>q;
    if(q==1) {
            d.qual="MBBS";
    }
    else if (q == 2) {
            d.qual="MD";
            }

    while (q>2 || q <=0) {
        cout << "come on!, enter a valid option!"<<endl;
        cin>>q;
        if(q==1) {
            d.qual="MBBS";
            break;
        }else if (q == 2) {
            d.qual="MD";
            break;
        }
    }


    cout<<"Choose Specialization among the following:"<<endl;
    string spec=d.getSpec();
    cout<<"Experience (in Years):"<<endl;
    cin>>d.experience;
    cout<<"City:"<<endl;
    cin>>d.d_city;
    system("cls");



    if (!d.d_city.empty()) {

        fstream fileObj;
        fileObj.open("doctor.txt",ios::app );
        //firstname,lastname,age,qualification,specialization,experience,city
        //int i = 1;
        fileObj.seekp (0, ios::end);
        fileObj <<d.d_ID << " "<<d.d_fname<< " "<<d.d_lname<<" "<<d.d_age<<" "<<d.qual<<" "<<spec<<" "<<d.experience<<" "<<d.d_city<<endl;
        //i++;
        fileObj.close();
        //cout << Doctors.size();
        //cout <<Doctors;
        //after completion
        cout<<"\n\t\tNew Doctor profile created successfully!"<<endl<<endl<<endl;
    }
    else {
        cout << "\n\t\t some inputs are missing or wrong, please try to refill it again. ";
        }

 //backtoDoctorMenu

}

ostream& operator<<(ostream& os, DoctorEntity &d)
{
    os <<d.d_ID << ' ' <<d.d_fname << ' ' << d.d_lname << ' ' << d.d_age << ' '<<d.qual<<' '<<d.getSpec()<<' '<<d.experience<<' '<<d.d_city<<endl;
    return os;
}


void DoctorEntity::dispDatabase(){
	fstream fileObj("doctor.txt");
	fileObj.seekg(0);
	//cout<<right<<setw(70)<<setfill(' ')<<"DOCTOR DATABASE"<<endl<<endl;
	//cout << "------------- Doctors Table ---------------" << endl;
	int age,exp,count=0;
	string ID,fname,lname,ci,qua,spe;

	cout<<endl<<endl<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
	cout <<"  ID" <<setw(15)<<"Name"<<setw(15) <<"Age" <<setw(20)<<"Qualification"<<setw(20) <<"Specialization"<<setw(15) <<"Experience"<<setw(12) <<"City" <<endl;
	cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl;

	while(fileObj>>ID>>fname>>lname>>age>>qua>>spe>>exp>>ci)
	{	count++;

		//cout<<right<<setw(50)<<setfill(' ')<<"Doctor Profile:"<<count<<endl;
		cout<<ID <<setw(15)<<fname + " " +  lname<<setw(10)<<age<<setw(12)<<qua<<setw(25)<<spe<<setw(15)<<exp<<setw(15)<<ci<<endl;

	}

	fileObj.close();

	if(count==0) {
        cout<<"\nNo matching records found!"<<endl;
        cout<<"Enter anything to go back to Patient Menu: ";
        string choice;
        cin>>choice;
	}
	else {
        int choice = -1;
        string feedback = "";
        while(choice != 0)
        {
            UiHelper::printHorizontalLine();
            UiHelper::printChoice("1.Delete an Entity");
            UiHelper::printChoice("2.Edit an Entity");
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
                int operation_result = -1;
                operation_result = deleteDoc();
                if(operation_result == 0)
                {
                    choice=0;
                }
                else
                {
                    feedback = "No matching records found!";
                }
                break;
            }
            case 2:
            {
                int operation_result = -1;
                DoctorEntity d;
                operation_result = editDoc(d);
                if(operation_result == 0)
                {
                    choice=0;
                }
                else
                {
                    feedback = "No matching records found!";
                }
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
}
	/*

	cout<<"\n\nEnter 1 to delete an Entity \nEnter 2 to edit an entity \nEnter 3 to Exit."<<endl;
	int c;
	cin>>c;
	if(c==1)
	{
	  //system("cls");
	  //getDoctorDatabase();
	  deleteDoc();

	}
	if(c==2) {
        DoctorEntity d;
        editDoc(d);
	}
	else
	  exit(0);
}

*/
int DoctorEntity:: editDoc(DoctorEntity &docobj){
	string x;
	cout<<"\nEnter the ID of the Doctor whose profile you want to Edit:"<<endl;
	cin>>x;									 //ID,firstname,lastname,age,qualification,specialization,experience,city
	fstream fileObj("doctor.txt");
	fileObj.seekg(0);

	int age,exp,count=0;
	string ID;
	string fname,lname,ci,qua,spe;
	while(fileObj>>ID>>fname>>lname>>age>>qua>>spe>>exp>>ci)
	{
		if(ID==x){
		cout<<"\n\n1.ID:"<<ID<<endl<<"2.First Name:"<<fname<<endl<<"3.Last Name:"<<lname<<endl<<"4.Age:"<<age<<endl<<"5.Qualification:"<<qua<<endl<<"6.Specialization:"<<spe<<endl<<"7.Experience:"<<exp<<endl<<"8.City:"<<ci<<endl<<endl;
		count++;
		break;
		}
	}

	fileObj.close();
	if(count==0){
		//cout<<"\nNo matching records found!"<<endl;
		//exit(0);
		return -1;
	}
	else {
        fstream file("doctor.txt");
        file.seekg (0, ios::beg);
        file.seekg(0);
        string line;
        ofstream tempObj;
        tempObj.open("copy.txt");
        tempObj.seekp(0);
        int skip = 0;
        int age1,exp1;
        string fname1,lname1,ci1,qua1,spe1;
        file.seekg(0);file.seekg(0,ios::cur); //setting the pointer to beginning of file
    //
    //	 if (tempObj.is_open())
    // 		 cout << "File successfully open";
    //	else
    //    	cout << "Error opening file";

        while(file>>line>>fname1>>lname1>>age1>>qua1>>spe1>>exp1>>ci1)
        {
            if(line!=x){
                tempObj<<line<<' '<<fname1<<' '<<lname1<<' '<<age1<<' '<<qua1<<' '<<spe1<<' '<<exp1<<' '<<ci1<<endl;
            }
        }

      file.close();
      tempObj.close();
      remove("doctor.txt");
      int result;
      char oldname[] ="copy.txt";
      char newname[] ="doctor.txt";
      result= rename( oldname , newname );
                                    //datatransfer endss
        int edit;
        cout<<"Enter number corresponding to the Field you want to Edit:"<<endl;
        cin>>edit;
        cout<<endl;
        switch(edit)							//ID,firstname,lastname,age,qualification,specialization,experience,city
        {
            case 1:{
                cout<<"ID"<<endl;
                cin>>ID;
                while (ID.length() != 8) {
                        cout <<endl<< "Enter ID consists of 8 digit  ";
                        cin>>ID;
                }

                break;
            }
            case 2:{
                cout<<"First Name:"<<endl;
                cin>>fname;

                break;
            }
            case 3:{
                cout<<"Last Name:"<<endl;
                cin>>lname;

                break;
            }
            case 4:{cout<<"Age:"<<endl;
                cin>>age;
                while (age < 25 || age > 85) {
                        cout << "come on! , Enter a valid age! ";
                cin>>age;
                }

                break;
            }
            case 5:{
                cout<<"Choose Qualification among the following:\n1.MBBS\n2.MD"<<endl;
                int q;
                cin>>q;
                if(q==1){
                    qua="MBBS";
                   }

                else if (q==2){
                    qua="MD";
                }
                while (q>2 || q <=0) {
                        cout << "come on!, enter a valid option!"<<endl;
                        cin>>q;
                        if(q==1) {
                            qua="MBBS";
                       }else if (q == 2) {
                           qua="MD";
                           }
                }

                break;
            }
            case 6:{
                system("cls");
                cout << "choose a number to update your specialization "<<endl;
                spe=docobj.getSpec();

                break;
            }
            case 7:{cout<<"Experience:"<<endl;
                cin>>exp;
                break;
            }
            case 8:{cout<<"City:"<<endl;
                cin>>ci;
                break;
            }
            default:{
            cout<<"Invalid Input!"<<endl;
            exit(0);
            }
        }
        system("cls");
        cout<<right<<setw(50)<<setfill(' ')<<"--Updated Profile--"<<endl<<endl;
        cout<<"\n\n1.ID:"<<ID<<endl<<"2.First Name:"<<fname<<endl<<"3.Last Name:"<<lname<<endl<<"4.Age:"<<age<<endl<<"5.Qualification:"<<qua<<endl<<"6.Specialization:"<<spe<<endl<<"7.Experience:"<<exp<<endl<<"8.City:"<<ci<<endl<<endl;

        //updated datatransfer
        fstream newObj;
        newObj.open("doctor.txt", ios::app);
        newObj.seekp (0, ios::end);
        newObj<<ID<<' '<<fname<<' '<<lname<<' '<<age<<' '<<qua<<' '<<spe<<' '<<exp<<' '<<ci<<endl;
        newObj.close();

        cout<<"\nEnter anything to return to Doctors Menu: ";
        string c;
        cin>>c;
	}
	return 0;

/*
	 //after completion
	cout<<"\n\nEnter 1 to return to Doctor Database\nEnter 2 to Exit."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
//	  getDoctorDatabase();
      dispDatabase();
	}

	else
	  exit(0);
*/

}

int DoctorEntity::deleteDoc(){
    string x;
	cout<<"\nEnter the ID of the Doctor whose profile you want to Delete:"<<endl;
	cin>>x;
	//stringstream s(x);
	//int y = 0;
	//s >>y;				 //ID,firstname,lastname,age,qualification,specialization,experience,city
	fstream fileObj("doctor.txt");
	fileObj.seekg(0);

	int age,exp,count=0;
	string ID;
	string fname,lname,ci,qua,spe;
	while(fileObj>>ID>>fname>>lname>>age>>qua>>spe>>exp>>ci)
	{
		if(ID==x){
            cout<<"\n\n1.ID:"<<ID<<endl<<"2.First Name:"<<fname<<endl<<"3.Last Name:"<<lname<<endl<<"4.Age:"<<age<<endl<<"5.Qualification:"<<qua<<endl<<"6.Specialization:"<<spe<<endl<<"7.Experience:"<<exp<<endl<<"8.City:"<<ci<<endl<<endl;
            count++;
            break;
        }
    }


	fileObj.close();
	if(count==0){
		//cout<<"\nNo matching records found!"<<endl;
		//exit(0);
		return -1;
	}
	else {
	    cout<<"Are you sure you want to delete this profile?\n1.YES\n2.NO"<<endl;
        int n;
        cin>>n;
        if(n==1){
            fstream file("doctor.txt");
            file.seekg (0, ios::beg);
            file.seekg(0);
            string line;
            ofstream tempObj;
            tempObj.open("copy.txt");
            tempObj.seekp(0);
            int skip = 0;
            int age1,exp1;
            string fname1,lname1,ci1,qua1,spe1;
            file.seekg(0);file.seekg(0,ios::cur); //setting the pointer to beginning of file

        //	 if (tempObj.is_open())
        // 		 cout << "File successfully open";
        //	else
        //    	cout << "Error opening file";
            while(file>>line>>fname1>>lname1>>age1>>qua1>>spe1>>exp1>>ci1)
            {
                if(line!=x){
                    tempObj<<line<<" "<<fname1<<" "<<lname1<<" "<<age1<<" "<<qua1<<" "<<spe1<<" "<<exp1<<" "<<ci1<<endl;
                }
            }

            file.close();
            tempObj.close();
          //char fileDoctor[] = "doctor.txt";
            if (std::remove("doctor.txt") != 0)
                perror("File deletion failed");
            else
                cout << "File deleted successfully";
          //remove("doctor.txt");
          //int result;
            char oldname[] ="copy.txt";
            char newname[] ="doctor.txt";
          //rename( oldname , newname );
            if (rename(oldname, newname) != 0)
                perror("Error renaming file");
            else
                cout <<endl<< "";
          //cout <<result <<"----------------";
          //system("cls");
            //cout<<"\n\t\tFile successfully deleted"<<endl;
          //dispDatabase();
        }

        cout<<"Enter anything to go back to Doctors Menu: ";
        string c;
        cin>>c;
    }

    return 0;

}


