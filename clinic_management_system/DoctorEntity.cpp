#include "DoctorEntity.h"
#include <iostream>
#include <fstream>

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
    cout<<"First Name:"<<endl;
    cin>>d.d_fname;
    cout<<"Last Name:"<<endl;
    cin>>d.d_lname;
    cout<<"Age:"<<endl;
    cin>>d.d_age;
    while (d.d_age < 25 || d.d_age > 85) {
        cout << "come on! , Enter a valid age!";
        cin>>d.d_age;
    }

    cout<<"Choose Qualification among the following:\n1.MBBS\n2.MD"<<endl;
    int q;
    cin>>q;

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
        fileObj <<d.d_fname<< " "<<d.d_lname<<" "<<d.d_age<<" "<<d.qual<<" "<<spec<<" "<<d.experience<<" "<<d.d_city<<endl;
        //i++;
        fileObj.close();

        //after completion
        cout<<"\n\t\tNew Doctor profile created successfully!"<<endl<<endl<<endl;
    }
    else {
        cout << "\n\t\t some inputs are missing or wrong, please try to refill it again. ";
        }

 //backtoDoctorMenu

}
