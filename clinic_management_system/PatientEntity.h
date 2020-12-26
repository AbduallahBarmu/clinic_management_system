#ifndef PATIENTSENTITY _H
#define PATIENTSENTITY _H
#include <string>

using namespace std ;
class PatientEntity
{
    public:
        PatientEntity ();
        virtual ~PatientEntity ();


        string fname,lname,career,p_city,Disease,addDate,Last_Check;
        int p_age ;
        string P_Phone;
        long double bill ;

        string getDept();
        void getDoctor();
        void addPat();
        //void editPat(patient &pat);
        void deletePat();
        void displayPat() ;

        void dispPatDatabase();
        void numberofPats();
        //void getPatientDatabase();


    protected:


    private:



};



#endif // PATIENTENTITY_H
