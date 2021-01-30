#include "PharmacyEntity.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include "UiHelper.h"

PharmacyEntity::PharmacyEntity()
{
    //ctor
}

PharmacyEntity::~PharmacyEntity()
{
    //dtor
}
void PharmacyEntity::addMed()
{
    PharmacyEntity m;

    cout<<"Fill up the following details"<<endl;
    cout << "Pharmacy ID consists of 8 numbers"<<endl;
    cin>>m.m_ID;
    while (m.m_ID.length() != 8) {
        //cout << d.d_ID.length();
        cout <<endl<< "Enter ID consists of 8 digit ";
        cin>>m.m_ID;
    }
    cout<<"Medicine Name:"<<endl;
    cin>>m.m_name;
    cout<<"Dose:"<<endl;
    cin>>m.m_dose;
    cout<<"Category:"<<endl;
    cin>>m.m_category;
    cout<<"Price:"<<endl;
    cin>>m.m_price;



    if (!m.m_name.empty()) {

        fstream fileObj;
        fileObj.open("pharmacy.txt",ios::app );
        //firstname,lastname,age,qualification,specialization,experience,city
        //int i = 1;
        fileObj.seekp (0, ios::end);
        fileObj <<m.m_ID << " "<<m.m_name<< " "<<m.m_dose<<" "<<m.m_category<<" "<<m.m_price<<endl;
        //i++;
        fileObj.close();
        //cout << Doctors.size();
        //cout <<Doctors;
        //after completion
        cout<<"\n\t\tNew Pharmacy profile created successfully!"<<endl<<endl<<endl;
    }
    else {
        cout << "\n\t\t some inputs are missing or wrong, please try to refill it again. ";
        }

 //backtoDoctorMenu

}

ostream& operator<<(ostream& os, PharmacyEntity &m)
{
    os <<m.m_ID << ' ' <<m.m_name << ' ' << m.m_dose << ' ' << m.m_category << ' '<<m.m_price<<endl;
    return os;
}

void PharmacyEntity::dispDatabase(){
	fstream fileObj("pharmacy.txt");
	fileObj.seekg(0);
	//cout<<right<<setw(70)<<setfill(' ')<<"DOCTOR DATABASE"<<endl<<endl;
	//cout << "------------- Doctors Table ---------------" << endl;
	int count=0;
	float price;
	string ID,name,dose,category;

	cout<<endl<<endl<<"-----------------------------------------------------------------------------------------------------"<<endl;
	cout <<"  ID" <<setw(20)<<"Name"<<setw(20) <<"Dose" <<setw(18)<<"Category"<<setw(18) <<"Price"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------"<<endl;

	while(fileObj>>ID>>name>>dose>>category>>price)
	{	count++;

		//cout<<right<<setw(50)<<setfill(' ')<<"Doctor Profile:"<<count<<endl;
		cout<<ID <<setw(17)<<name<<setw(17) << dose<<setw(17)<<category<<setw(17)<<price<<endl;

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
                operation_result = deleteMed();
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
                PharmacyEntity m;
                operation_result = editMed(m);
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
int PharmacyEntity:: editMed(PharmacyEntity &medobj){
	string x;
	cout<<"\nEnter the ID of the Medicine whose profile you want to Edit:"<<endl;
	cin>>x;									 //ID,firstname,lastname,age,qualification,specialization,experience,city
	fstream fileObj("pharmacy.txt");
	fileObj.seekg(0);

	int count=0;
	string ID;
	string name,dose,category;
	float price;
	while(fileObj>>ID>>name>>dose>>category>>price)
	{
		if(ID==x){
		cout<<"\n\n1.ID:"<<ID<<endl<<"2.Name:"<<name<<endl<<"3.Dose:"<<dose<<endl<<"4.Category:"<<category<<endl<<"5.Price:"<<price<<endl<<endl;
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
        fstream file("pharmacy.txt");
        file.seekg (0, ios::beg);
        file.seekg(0);
        string line;
        ofstream tempObj;
        tempObj.open("copyph.txt");
        tempObj.seekp(0);
        int skip = 0;
        float price1;
        string name1,dose1,category1;
        file.seekg(0);file.seekg(0,ios::cur); //setting the pointer to beginning of file
    //
    //	 if (tempObj.is_open())
    // 		 cout << "File successfully open";
    //	else
    //    	cout << "Error opening file";

        while(file>>line>>name1>>dose1>>category1>>price1)
        {
            if(line!=x){
                tempObj<<line<<' '<<name1<<' '<<dose1<<' '<<category1<<' '<<price1<<endl;
            }
        }

      file.close();
      tempObj.close();
      remove("pharmacy.txt");
      int result;
      char oldname[] ="copyph.txt";
      char newname[] ="pharmacy.txt";
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
                cout<<"Medicine Name:"<<endl;
                cin>>name;

                break;
            }
            case 3:{
                cout<<"Dose:"<<endl;
                cin>>dose;

                break;
            }
            case 4:{cout<<"Category:"<<endl;
                cin>>category;

                break;

                }
                case 5:{cout<<"Price:"<<endl;
                cin>>price;
                break;
            }
            default:{
            cout<<"Invalid Input!"<<endl;
            exit(0);
            }
            }



        system("cls");
        cout<<right<<setw(50)<<setfill(' ')<<"--Updated Profile--"<<endl<<endl;
        cout<<"\n\n1.ID:"<<ID<<endl<<"2.Medicine Name:"<<name<<endl<<"3.Dose:"<<dose<<endl<<"4.Category:"<<category<<endl<<"5.Price:"<<price<<endl;

        //updated datatransfer
        fstream newObj;
        newObj.open("pharmacy.txt", ios::app);
        newObj.seekp (0, ios::end);
        newObj<<ID<<' '<<name<<' '<<dose<<' '<<category<<' '<<price<<endl;
        newObj.close();

        cout<<"\nEnter anything to return to Pharmacy Menu: ";
        string c;
        cin>>c;
	}
	return 0;
}

int PharmacyEntity::deleteMed(){
    string x;
	cout<<"\nEnter the ID of the Pharmacy whose profile you want to Delete:"<<endl;
	cin>>x;
	//stringstream s(x);
	//int y = 0;
	//s >>y;				 //ID,firstname,lastname,age,qualification,specialization,experience,city
	fstream fileObj("pharmacy.txt");
	fileObj.seekg(0);

	int count=0;
	string ID;
	string name,dose,category;
	float price;
	while(fileObj>>ID>>name>>dose>>category>>price)
	{
		if(ID==x){
            cout<<"\n\n1.ID:"<<ID<<endl<<"2.Medicine Name:"<<name<<endl<<"3.Dose:"<<dose<<endl<<"4.Category:"<<category<<endl<<"5.Price:"<<price<<endl<<endl;
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
            fstream file("pharmacy.txt");
            file.seekg (0, ios::beg);
            file.seekg(0);
            string line;
            ofstream tempObj;
            tempObj.open("copyph.txt");
            tempObj.seekp(0);
            int skip = 0;
            string name1,dose1,category1;
            float price1;
            file.seekg(0);file.seekg(0,ios::cur); //setting the pointer to beginning of file

        //	 if (tempObj.is_open())
        // 		 cout << "File successfully open";
        //	else
        //    	cout << "Error opening file";
            while(file>>line>>name1>>dose1>>category1>>price1)
            {
                if(line!=x){
                    tempObj<<line<<" "<<name1<<" "<<dose1<<" "<<category1<<" "<<price1<<endl;
                }
            }

            file.close();
            tempObj.close();
          //char fileDoctor[] = "doctor.txt";
            if (std::remove("pharmacy.txt") != 0)
                perror("File deletion failed");
            else
                cout << "File deleted successfully";
          //remove("doctor.txt");
          //int result;
            char oldname[] ="copyph.txt";
            char newname[] ="pharmacy.txt";
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

        cout<<"Enter anything to go back to pharmacy Menu: ";
        string c;
        cin>>c;
    }

    return 0;

}
