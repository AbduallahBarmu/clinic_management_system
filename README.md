##Clinic_management_system
Programming for engineers c++ project that manages doctors, patients, and pharmacy of a small clinic

## Abstract
The Clinic Management System is built to support and simplify the clinic everyday service. Clinic
Management System is a system that can allow the clinic to control their everyday operation. This
system covers all clinic activities which includes doctor records, patients records, and the clinic
pharmacy records.
This application enables clinic managers to handle patient reports, inventory of medication, and clinic
doctors information which are stored in text files. The application is user-friendly, quick and convenient
for the user to use. Overall, this system supports the regular operation of a clinic, such as viewing,
inserting, updating and deleting records.
To protect the privacy of the patients, doctors and the clinic information safe we secured the system
with an encrypted password that is stored in a separate file.

##Introduction
Clinics have a lot of doctors, daily patients and active pharmacies. Each of these entities must be
managed carefully and flawlessly. With a traditional file system these entities are hard to manage for
clinic employees. 



##Used Technologies 
language Core: C/C++ , Files for storing data  



##Project Design

##Interface
Since this program has been built using c++ programming, the interface is using console application and in the paragraph, we are going to demonstrate the function of the main pages that appears in the program, and the detailed process is to be demonstrated in the user manual part in upcoming sections.

First page to be shown is the login page, which allow you to create a password for the first use or use your old password for the next login attempts, 
and the screen is shown below:


After logging to the account, the comprehensive system management general categories appear, this page includes main menu, changing password and exiting the program, and the screen is shown below:

![1](https://user-images.githubusercontent.com/64614781/143484764-56db9205-5161-4a09-9da9-3280fd21d467.png)

The changing password feature, gives you the ability to change your old password with new one which can be saved in an external file in an encrypted version to preserve end-users security, and the screen is shown below:

![2](https://user-images.githubusercontent.com/64614781/143484822-d451e88a-7657-4c73-b692-c89023dbd389.png)

In case you write the old password correctly, you can access the next page, that allows you to type a new password, and the screen is shown below:

![3](https://user-images.githubusercontent.com/64614781/143484933-ac6c4655-5593-4932-b946-7cfe75a23d60.png)

The next page is the main menu page, which includes the three main categories included in the clinic system which are: doctors, patients, and pharmacy and each category has its CRUD operations that will be demonstrated in the upcoming section in details:

![4](https://user-images.githubusercontent.com/64614781/143484964-a345884d-5a8b-437d-b326-fe226e2e6d33.png)


The main operations for each category are:
●	Adding new Entity by filling in the required information
●	Display all the records included in the file database for each category
●	Updating records by choosing which cell to update using the TC Number or ID number for each Entity
●	Deleting records by choosing which record to delete  using the TC Number or ID number for each Entity
And the screen for all the operations is shown below (the mentioned screen belongs to the doctors database, and the same goes for all the other categories):


![5](https://user-images.githubusercontent.com/64614781/143485000-6a05f422-09ea-45d8-b2a5-2f20998e3e89.png)


Note that the process of deleting and updating are included in the displaying features, as it make it easier for the end-user to see the IDs for all the record and choose the record to be operated easily, and the screen of all the records with the updating, and deleting features is shown below:


![6](https://user-images.githubusercontent.com/64614781/143485120-a0c4f453-9310-42d3-981c-749df50726b4.png)

Same process is made for the pharmacy and patients records here:

![7](https://user-images.githubusercontent.com/64614781/143485162-398da539-ecad-443e-afe0-6fe616198acc.png)

![8](https://user-images.githubusercontent.com/64614781/143485271-5938f3ee-e67d-4d78-9714-7e5cdf233e17.png)

More on how to use the application in the user manual section where we describe in detail how to use each feature with steps and screenshots.

##Operations
The system operations and features are listed below:

1.	Login Function
Login to the program with a password that is encrypted and saved locally, the system matches the given password hash with the existing hash, if both are equal the system allows the user to login and access the data.

2.	Change Password
Changes the password of the program by confirming the old password first then accepting the new password for the application.
Passwords must be at least 8 characters long or else the system will reject it.

3.	Exit Program
Close the application 

![8](https://user-images.githubusercontent.com/64614781/143485335-31d076e5-f34c-49f5-b0da-db586da46ca1.png)


4.	View All Entities
Display all the entities in the files (Doctors, Patients, Pharmacy) in a neat looking table so that the user can see all saved entities in one organized screen.

5.	Edit Entity
By choosing an entity from the table of entities the user can display all information of the entity then choose the attribute that he wants to edit and enter the new value. The system updates the entity with the new value in the system files.


6.	View Entity
By entering an ID of an entity from the table of entities the system displays all of the entity information in an organized way.

7.	Delete Entity
After displaying the entity the user can choose to delete the entity from the system. The system will prompt the user for a confirmation, if the user confirms the entity will be permanently deleted from the system files.

8.	Navigate Application Screen
Navigate through the application using the navigation screens by choosing the operation you want to perform.

![9](https://user-images.githubusercontent.com/64614781/143485403-fea95421-c207-4859-a59f-e5a9ddf03c4c.png)




##Files
The files included in this projects are 4 files as follow:
1.	medipolclinicsys.txt
Includes the encrypted password of the system.

2.	doctor.txt
Includes all the information about every and each doctor in the clinic.

3.	patient.txt
Includes all the patients reports such as last check-in and the disease .. etc.

4.	pharmacy.txt
Includes all the available medications names, dose, description and price in the small pharmacy inside the clinic. 

