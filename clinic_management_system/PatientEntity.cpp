#include "PatientEntity.h"
#include "patientProfile.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

PatientEntity::PatientEntity()
{
    //ctor
}

PatientEntity::~PatientEntity()
{
    //dtor
}

string PatientEntity::getDept(){
	string sp;
	cout<<"1.GENERAL_MEDICINE"<<endl;
	cout<<"2.NEUROLOGY"<<endl;
	cout<<"3.ONCOLOGY"<<endl;
	cout<<"4.HAEMATOLOGY"<<endl;
	cout<<"5.GASTROENTEROLOGY"<<endl;
	cout<<"6.GYNAECOLOGY "<<endl<<endl;
	int s;
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
		return sp;
}



///Add patient function
void PatientEntity::addPat(){
        PatientEntity p;
	    cout<<"Fill Up The Following Details please "<<endl;
   		cout<<"Enter your First Name:"<<endl;
   		cin>>p.fname;
   		cout<<"Enter your Last Name:"<<endl;
   		cin>>p.lname;
   		cout<<"Enter your Age:"<<endl;
   		cin>>p.p_age;
		cout<<"Enter your Phone Number:"<<endl;
   		cin>>p.P_Phone;
   		cout<<"Enter your career:"<<endl;
		cin>>p.career;
		cout<<"Enter your City:"<<endl;
		cin>>p.p_city;
   		cout<<"what is your Disease/Symptoms:"<<endl;
   		cin>>p.Disease;
   		cout<<"Enter the Admission date  (DD/MM/YYYY):"<<endl;
   		cin>>p.addDate;
   		cout<<"Enter the Last Check on your health   (DD/MM/YYYY):"<<endl;
   		cin>>p.Last_Check;
   		cout<<"How much the total Bill generated:"<<endl;
   		cin>>p.bill;
		cout<<"Select the Kind of Specialization required:"<<endl;
		string dept = p.getDept();
		system("cls");


		fstream patObj;
		patObj.open("patient.txt",ios::app );

        patObj.seekp (0, ios::end);
		patObj<<p.fname<<" "<<p.lname<<" "<<p.p_age<<" "<<p.P_Phone<<" "<<p.career<<" "<<p.p_city<<" "<<p.Disease<<" "<<p.addDate<<" "<<p.Last_Check<<" "<<p.bill<<" "<<dept<<endl;
		patObj.close();

	cout<<"\n\t\tNew Patient profile created successfully!"<<endl<<endl<<endl;
	cout<<"\n\n\n\nEnter 1 to return back into Patient Database\nEnter 2 to Exit."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  //getPatientDatabase();	 //backtoPatientMenu
	}

	else
	  exit(0);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PatientEntity::dispPatDatabase(){
	fstream Obj("patient.txt");
	Obj.seekg(0);

	//cout << "-------------------------------- patient Table -----------------------" << endl;
	string fname,lname,career,p_city,Disease,addDate,Last_Check,dept;
	int p_age,count=0;
	long double bill;
    string P_Phone;

	cout<<endl<<endl<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"ID"<<setw(12) <<"Name"<< setw(12)<<"Age"<<setw(15) <<"Phone-No"<<setw(15) <<"career"<< setw(12)<<"City"<<setw(12)<<setw(15) <<"Disease"<<setw(22)<< "Admission-date"<<setw(20)<<"Last-Check "<< setw(20)<<"Total-Bill "<<setw(20) <<"Specialization" <<endl;
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;

	while(Obj>>fname>>lname>>p_age>>P_Phone>>career>>p_city>>Disease>>addDate>>Last_Check>>bill>>dept)
	{   count++;

		cout<< count <<setw(10)<<fname<<" "<<lname<<setw(7)<<p_age<<setw(16)<<P_Phone<<setw(17)<<career<<setw(15)<<p_city<<setw(12)<<Disease<<setw(21)<<addDate<<setw(20)<<Last_Check<<setw(15)<<bill<<setw(25)<<dept <<endl ;
	}



	if(count==0){
		cout<<"\nNo matching records found!"<<endl;
		exit(0);
	}

cout<<"\n\nEnter 1 to back into Patient Database\nEnter 2 to Exit.\nEnter Patient ID to make more operation"<<endl;
	int c;
	cin>>c;
    while(c != 0)
    {
         switch(c)
         {
         case 1:
         {
              system("cls");

             break;
         }
         case 0:
         {
             exit(0);
             break;
         }
         case 2:
         {
             if(c == count ){
                patientProfile();
             }else
                cout<< "please Enter the ID again !!"<< endl;
            break ;
         }


         }
     }




}








///the display patient profile
void PatientEntity::displayPat(){
	int p;
	//cout<<"\nEnter the ID of the Patient whose profile you want to Display:"<<endl;
	cin>>p;
	fstream patOb("patient.txt");
	patOb.seekg(0);

	string fname,lname,career,p_city,Disease,addDate,Last_Check,dept;
	int p_age,count=0;
	long double bill;
    string P_Phone;

	while(patOb>>fname>>lname>>p_age>>P_Phone>>career>>p_city>>Disease>>addDate>>Last_Check>>bill>>dept)
        {
            if(count== p){
            cout<<"1.ID:"<<count <<endl<<"2.First Name:"<<fname<<endl<<"3.Last Name:"<<lname<<endl<<"4.Age"<<p_age<<endl<<"5.Phone No.:"<<P_Phone<<endl<<"6.career:"<<career<<endl<<"7.City:"<<p_city<<endl<<"8.Disease/Symptoms:"<<Disease<<endl<<"9.Admission  date(DD/MM/YYYY):"<<addDate<<endl<<"10.Last Check date(DD/MM/YYYY):"<<Last_Check<<endl<<"11.Total Bill generated:"<<bill<<endl<<"12.Kind of Specialization required:"<<dept<<endl;
            count++;
            break;
            }
        }

	patOb.close();
	if(count==0){
		cout<<"\nNo matching records found!"<<endl;
		exit(0);
	}

//cout<<"\n\n Enter 1 to Edit Patient Profile \nEnter 2 to Delete Patient Profile \nEnter 1 to back into Patient dataBase \nEnter 4 exit from program  "<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  //getPatientDatabase();
	}

	else
	  exit(0);
}


/*

///the Delete patient function/////////////////////////////////////////////////////////////////////////
void PatientEntity::deletePat()
    {
    int x;
        cout<<"\nEnter the ID of the Patient whose profile you want to Delete:"<<endl;
        cin>>x;
        fstream patObj("patient.txt");
        patObj.seekg(0);

        string fname,lname,career,p_city,Disease,addDate,Last_Check,dept;
        int p_age,count=0;
        long double bill;
        string P_Phone;

        while(patObj>>fname>>lname>>p_age>>P_Phone>>career>>p_city>>Disease>>addDate>>Last_Check>>bill>>dept)
        {
            if(count==x){
            cout<<"1.ID:"<<count <<endl<<"2.First Name:"<<fname<<endl<<"3.Last Name:"<<lname<<endl<<"4.Age"<<p_age<<endl<<"5.Phone No.:"<<P_Phone<<endl<<"6.career:"<<career<<endl<<"7.City:"<<p_city<<endl<<"8.Disease/Symptoms:"<<Disease<<endl<<"9.Admission  date(DD/MM/YYYY):"<<addDate<<endl<<"10.Last Check date(DD/MM/YYYY):"<<Last_Check<<endl<<"11.Total Bill generated:"<<bill<<endl<<"12.Kind of Specialization required:"<<dept<<endl;
            count++;
            break;
            }
        }

        patObj.close();
        if(count==0){
            cout<<"\nNo matching records found!"<<endl;
            exit(0);
        }
        cout<<"Are you sure you want to DELETE this profile!? \n1.YES\n2.NO"<<endl;
        int n;cin>>n;
        if(n==1)
        {
        fstream file("patient.txt");
        file.seekg (0, ios::beg);
        file.seekg(0);
        int line;
        ofstream tempObj;
        tempObj.open("copy2.txt");
        tempObj.seekp(0);
        int skip = 0;
        string fname1,lname1,occupation1,p_city1,dis1,addDate1,relDate1,dept1;
        int p_age1;
        long double phnumber1,bill1;
        file.seekg(0);file.seekg(0,ios::cur); //setting the pointer to beginning of file

    //	 if (tempObj.is_open())
    // 		 cout << "File successfully open";
    //	else
    //    	cout << "Error opening file";
        while(file>>line>>fname1>>lname1>>p_age1>>phnumber1>>occupation1>>p_city1>>dis1>>addDate1>>relDate1>>bill1>>dept1)
        {
            if(line!=x){
                tempObj<<line<<endl<<fname1<<endl<<lname1<<endl<<p_age1<<endl<<phnumber1<<endl<<occupation1<<endl<<p_city1<<endl<<dis1<<endl<<addDate1<<endl<<relDate1<<endl<<bill1<<endl<<dept1<<endl;
            }
        }

      file.close();
      tempObj.close();
      remove("patient.txt");
      int result;
      char oldname[] ="copy2.txt";
      char newname[] ="patient.txt";
      result= rename( oldname , newname );
      system("cls");
      cout<<"\n\t\tFile successfully deleted"<<endl;
    }


    cout<<"\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit."<<endl;
        int c;
        cin>>c;
        if(c==1){
          system("cls");
          //getPatientDatabase();
        }

        else
          exit(0);
}

*/
