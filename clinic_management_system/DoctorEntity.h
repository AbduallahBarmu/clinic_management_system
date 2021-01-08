#ifndef DOCTORENTITY_H
#define DOCTORENTITY_H
#include <string>
//#include "DoctorsMainScreen.h"

using namespace std;
class DoctorEntity
{
    public:
        DoctorEntity();
        virtual ~DoctorEntity();
        string d_fname,d_lname;
        int d_ID;
        int d_age,experience,d_totalno;
        string qual,d_city;
        string getSpec();
        void addDoc();
        int editDoc(DoctorEntity &docobj);
        int deleteDoc();
        void dispDatabase();
        void numberofDocs();
        //void getDoctorDatabase();

    protected:

    private:

};

#endif // DOCTORENTITY_H

