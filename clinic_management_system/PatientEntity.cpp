#include "PatientEntity.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "UiHelper.h"

PatientEntity::PatientEntity()
{
    //ctor
}

PatientEntity::~PatientEntity()
{
    //dtor
}

string PatientEntity::getDept()
{
    string sp;
    cout<<"1.GENERAL_MEDICINE"<<endl;
    cout<<"2.NEUROLOGY"<<endl;
    cout<<"3.ONCOLOGY"<<endl;
    cout<<"4.HAEMATOLOGY"<<endl;
    cout<<"5.GASTROENTEROLOGY"<<endl;
    cout<<"6.GYNAECOLOGY "<<endl<<endl;
    int s;
    cin>>s;
    switch(s)
    {

    case 1:
    {
        sp= "GENERAL_MEDICINE";
        break;
    }
    case 2:
    {
        sp="NEUROLOGY";
        break;
    }
    case 3:
    {
        sp="ONCOLOGY";
        break;
    }
    case 4:
    {
        sp= "HAEMATOLOGY";
        break;
    }
    case 5:
    {
        sp= "GASTROENTEROLOGY";
        break;
    }
    case 6:
    {
        sp= "GYNAECOLOGY ";
        break;
    }
    default:
    {
        cout<<"\nCome on!Enter a valid option."<<endl;

    }

    }
    return sp;
}



///Add patient function
void PatientEntity::addPat()
{
    PatientEntity p;
    cout<<"Fill Up The Following Details please "<<endl<<endl;
    cout<<"Enter  National TC Kimlik  "<< endl;
    cin>>p.p_ID ;
    while (p.p_ID.length() != 8) {
        cout <<endl<< "Enter ID consists of 8 digit ";
        cin>>p.p_ID;
    }
    cout<<"Enter  First Name:"<<endl;
    cin>>p.fname;
    cout<<"Enter  Last Name:"<<endl;
    cin>>p.lname;
    cout<<"Enter Age:"<<endl;
    cin>>p.p_age;
    cout<<"Enter Phone Number:"<<endl;
    cin>>p.P_Phone;
    cout<<"Enter  job:"<<endl;
    cin>>p.job;
    cout<<"Enter  City:"<<endl;
    cin>>p.p_city;
    cout<<"what is  Disease/Symptoms:"<<endl;
    cin>>p.Disease;
    cout<<"Enter the Admission date  (DD/MM/YYYY):"<<endl;
    cin>>p.addDate;
    cout<<"Enter the Last Check on your health   (DD/MM/YYYY):"<<endl;
    cin>>p.Last_Check;
    cout<<"Select the Kind of Specialization required:"<<endl;
    string dept = p.getDept();
    system("cls");


    fstream patObj;
    patObj.open("patient.txt",ios::app );

    patObj.seekp (0, ios::end);
    patObj<<p.p_ID<<" "<<p.fname<<" "<<p.lname<<" "<<p.p_age<<" "<<p.P_Phone<<" "<<p.job<<" "<<p.p_city<<" "<<p.Disease<<" "<<p.addDate<<" "<<p.Last_Check<<" "<<dept<<endl;
    patObj.close();

    cout<<"\nNew Patient profile created successfully!"<<endl;
    cout<<"Enter anything to return back to Patient Menu"<<endl;
    string c;
    cin>>c;
}





void PatientEntity::dispPatDatabase()
{
    fstream Obj("patient.txt");
    Obj.seekg(0);

    string fname,lname,job,p_city,Disease,addDate,Last_Check,P_Phone, dept , p_ID;
    int p_age,count=0 ;

    cout<<endl<<endl<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(12)<<"National ID"<<setw(12) <<"Name"<< setw(12)<<"Age"<<setw(15) <<"Phone-No"<<setw(15) <<"job"<< setw(12)<<"City"<<setw(12)<<setw(15) <<"Disease"<<setw(22)<< "Admission-date"<<setw(20)<<"Last-Check "<< setw(20)<<"Specialization" <<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;

    while(Obj>>p_ID>>fname>>lname>>p_age>>P_Phone>>job>>p_city>>Disease>>addDate>>Last_Check>>dept)
    {
        count++;
        cout<<p_ID<<setw(10)<<fname<<" "<<lname<<setw(7)<<p_age<<setw(16)<<P_Phone<<setw(17)<<job<<setw(15)<<p_city<<setw(12)<<Disease<<setw(21)<<addDate<<setw(20)<<Last_Check<<setw(20)<<dept <<endl ;
    }
    cout << endl << endl;

    Obj.close();

    if(count==0)
    {
        cout<<"\nNo matching records found!"<<endl;
        cout<<"Enter anything to go back to Patient Menu: ";
        string choice;
        cin>>choice;
    }
    else
    {
        int choice = -1;
        string feedback = "";
        while(choice != 0)
        {
            UiHelper::printHorizontalLine();
            UiHelper::printChoice("1.Delete an Entity");
            UiHelper::printChoice("2.Edit an entity");
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
                operation_result = deletePat();
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
                PatientEntity d;
                operation_result = editPat(d);
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

///display patient profile
void PatientEntity::displayPat()
{
    int p;
    //cout<<"\nEnter the ID of the Patient whose profile you want to Display:"<<endl;
    cin>>p;
    fstream patOb("patient.txt");
    patOb.seekg(0);

    string fname,lname,career,p_city,Disease,addDate,Last_Check,dept;
    int p_age,p_ID,count=0;
    long double P_Phone,bill;


    while(patOb>>p_ID>>fname>>lname>>p_age>>P_Phone>>career>>p_city>>Disease>>addDate>>Last_Check>>bill>>dept)
    {
        if(p_ID== p)
        {
            cout<<"1.ID:"<<p_ID <<endl<<"2.First Name:"<<fname<<endl<<"3.Last Name:"<<lname<<endl<<"4.Age"<<p_age<<endl<<"5.Phone No.:"<<P_Phone<<endl<<"6.career:"<<career<<endl<<"7.City:"<<p_city<<endl<<"8.Disease/Symptoms:"<<Disease<<endl<<"9.Admission  date(DD/MM/YYYY):"<<addDate<<endl<<"10.Last Check date(DD/MM/YYYY):"<<Last_Check<<endl<<"11.Total Bill generated:"<<bill<<endl<<"12.Kind of Specialization required:"<<dept<<endl;
            count++;
            break;
        }
    }

    patOb.close();
    if(count==0)
    {
        cout<<"\nNo matching records found!"<<endl;
        exit(0);
    }

    cout<<"\n\nEnter 1 to delete an Entity \nEnter 2 to edit an entity \nEnter 3 to Exit."<<endl;
    int c;
    cin>>c;
    if(c==1)
    {
        system("cls");
        //getDoctorDatabase();
        deletePat();

    }
    if(c==2)
    {
        //PatientEntity d;
        //editDoc(pat);
    }
    else
        exit(0);

}
*/


int PatientEntity:: editPat(PatientEntity &pat)
{
    string x;
    cout<<"\nEnter the ID for Patient whose profile you want to Edit: ";
    cin>>x;
    fstream patObj("patient.txt");
    patObj.seekg(0);

    string fname,lname,job,p_city,Disease,addDate,Last_Check,dept,P_Phone, p_ID;
    int p_age,count=0;



    while(patObj>>p_ID>>fname>>lname>>p_age>>P_Phone>>job>>p_city>>Disease>>addDate>>Last_Check>>dept)
    {
        if(p_ID==x)
        {
            cout<<"1.ID:"<<p_ID <<endl<<"2.First Name:"<<fname<<endl<<"3.Last Name:"<<lname<<endl<<"4.Age"<<p_age<<endl<<"5.Phone No.:"<<P_Phone<<endl<<"6.job:"<<job<<endl<<"7.City:"<<p_city<<endl<<"8.Disease/Symptoms:"<<Disease<<endl<<"9.Admission  date(DD/MM/YYYY):"<<addDate<<endl<<"10.Last Check date(DD/MM/YYYY):"<<Last_Check<<endl<<"11.Kind of Specialization required:"<<dept<<endl;
            count++;
            break;
        }
    }

    patObj.close();
    if(count==0)
    {
        return -1;
    }
    else
    {
        //data transfer begins
        fstream file("patient.txt");
        file.seekg (0, ios::beg);
        file.seekg(0);
        string line;
        ofstream tempObj;
        tempObj.open("copy2.txt");
        tempObj.seekp(0);
        int skip = 0;
        string fname1,lname1,job1,p_city1,dis1,addDate1,relDate1,dept1,pNumber1;
        int p_age1;

        file.seekg(0);
        file.seekg(0,ios::cur); //setting the pointer to beginning of file

        while(file>>line>>fname1>>lname1>>p_age1>>pNumber1>>job1>>p_city1>>dis1>>addDate1>>relDate1>>dept1)
        {
            if(line!=x)
            {
                tempObj<<line<<" "<<fname1<<" "<<lname1<<" "<<p_age1<<" "<<pNumber1<<" "<<job1<<" "<<p_city1<<" "<<dis1<<" "<<addDate1<<" "<<relDate1<<" "<<dept1<<endl;
            }
        }

        file.close();
        tempObj.close();
        remove("patient.txt");
        int result;
        char oldname[] ="copy2.txt";
        char newname[] ="patient.txt";
        result= rename( oldname, newname );
        //data transfer ends
        int edit;
        cout<<"\nEnter number corresponding to the Field you want to Edit: ";
        cin>>edit;
        switch(edit)
        {
        case 1:
        {
            cout<<"ID"<<endl;
            cin>>p_ID;
            break;
        }
        case 2:
        {
            cout<<"First Name:"<<endl;
            cin>>fname;

            break;
        }
        case 3:
        {
            cout<<"Last Name:"<<endl;
            cin>>lname;

            break;
        }
        case 4:
        {
            cout<<"Age:"<<endl;
            cin>>p_age;
            break;
        }
        case 5:
        {
            cout<<"Phone No.:"<<endl;
            cin>>P_Phone;
            break;
        }
        case 6:
        {
            cout<<"job:"<<endl;
            cin>>job;
            break;
        }
        case 7:
        {
            cout<<"City:"<<endl;
            cin>>p_city;
            break;
        }

        case 8:
        {
            cout<<"Disease/Symptoms:"<<endl;
            cin>>Disease;
            break;
        }
        case 9:
        {
            cout<<"Admission date  (DD/MM/YYYY):"<<endl;
            cin>>addDate;
            break;
        }
        case 10:
        {
            cout<<"Release date  (DD/MM/YYYY):"<<endl;
            cin>>Last_Check;
        }
        case 11:
        {
            cout<<"Kind of Specialization required:"<<endl;
            dept = pat.getDept();
            break;
        }
        default:
        {
            cout<<"\nCome on!Enter a valid option."<<endl;
            break;
        }
        }

        system("cls");
        cout<<right<<setw(50)<<setfill(' ')<<"--Updated Profile--"<<endl<<endl;
        cout<<"1.ID:"<<p_ID<<endl<<"2.First Name:"<<fname<<endl<<"3.Last Name:"<<lname<<endl<<"4.Age"<<p_age<<endl<<"5.Phone No.:"<<P_Phone<<endl<<"6.Occupation:"<<job<<endl<<"7.City:"<<p_city<<endl<<"8.Disease/Symptoms:"<<Disease<<endl<<"9.Admission date(DD/MM/YYYY):"<<addDate<<endl<<"10.Release date(DD/MM/YYYY):"<<Last_Check<<endl<<"11.Kind of Specialization required:"<<dept<<endl;

        //updated data transfer
        fstream newObj;
        newObj.open("patient.txt", ios::app);
        newObj.seekp (0, ios::end);
        newObj<<p_ID<<" "<<fname<<" "<<lname<<" "<<p_age<<" "<<P_Phone<<" "<<job<<" "<<p_city<<" "<<Disease<<" "<<addDate<<" "<<Last_Check<<" "<<dept<<endl;
        newObj.close();

        cout<<"\nEnter anything to return to Patient Menu: ";
        string c;
        cin>>c;
    }
    return 0;


}







/// Delete patient function
int PatientEntity::deletePat()
{

    string x;
    cout<<"\nEnter the ID for Patient whose profile you want to Delete: ";

    cin>>x;
    fstream patObj("patient.txt");
    patObj.seekg(0);

    string fname,lname,job,p_city,Disease,addDate,Last_Check,dept,P_Phone,p_ID;
    int p_age,count=0;



    while(patObj>>p_ID>>fname>>lname>>p_age>>P_Phone>>job>>p_city>>Disease>>addDate>>Last_Check>>dept)
    {
        if(p_ID==x)
        {
            cout<<"1.ID:"<<p_ID <<endl<<"2.First Name:"<<fname<<endl<<"3.Last Name:"<<lname<<endl<<"4.Age"<<p_age<<endl<<"5.Phone No.:"<<P_Phone<<endl<<"6.job:"<<job<<endl<<"7.City:"<<p_city<<endl<<"8.Disease/Symptoms:"<<Disease<<endl<<"9.Admission  date(DD/MM/YYYY):"<<addDate<<endl<<"10.Last Check date(DD/MM/YYYY):"<<Last_Check<<endl<<"11.Kind of Specialization required:"<<dept<<endl;
            count++;
            break;
        }
    }

    patObj.close();
    if(count==0)
    {
        return -1;
    }
    else
    {
        cout<<"Are you sure you want to DELETE this profile!? \n1.YES\n2.NO"<<endl;
        int n;
        cin>>n;
        if(n==1)
        {
            fstream file("patient.txt");
            file.seekg (0, ios::beg);
            file.seekg(0);
            string line;
            ofstream tempObj;
            tempObj.open("copy2.txt");
            tempObj.seekp(0);
            int skip = 0;
            string fname1,lname1,job1,p_city1,dis1,addDate1,relDate1,dept1,pNumber1;
            int p_age1;

            file.seekg(0);
            file.seekg(0,ios::cur); //setting the pointer to beginning of file


            while(file>>line>>fname1>>lname1>>p_age1>>pNumber1>>job1>>p_city1>>dis1>>addDate1>>relDate1>>dept1)
            {
                if(line!=x)
                {
                    tempObj<<line<<" "<<fname1<<" "<<lname1<<" "<<p_age1<<" "<<pNumber1<<" "<<job1<<" "<<p_city1<<" "<<dis1<<" "<<addDate1<<" "<<relDate1<<" "<<dept1<<endl;
                }
            }

            file.close();
            tempObj.close();
            remove("patient.txt");
            int result;
            char oldname[] ="copy2.txt";
            char newname[] ="patient.txt";
            result= rename( oldname, newname );
            system("cls");
            cout<<"\n\t\tFile successfully deleted"<<endl;
        }
        cout<<"Enter anything to go back to Patient Menu: ";
        string c;
        cin>>c;
    }

    return 0;

}



