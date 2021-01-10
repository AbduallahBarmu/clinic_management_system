#ifndef PATIENTSENTITY _H
#define PATIENTSENTITY _H
#include <string>

using namespace std ;
class PatientEntity
{
    public:
        PatientEntity ();
        virtual ~PatientEntity ();

        string fname,lname,job,p_city,Disease,addDate,Last_Check ,P_Phone,p_ID;
        int p_age ;


        string getDept();
        void getDoctor();
        void addPat();
        int editPat(PatientEntity &pat);
        int deletePat();
        void displayPat() ;

        void dispPatDatabase();
        //void numberofPats();
        //void getPatientDatabase();


    protected:


    private:



};



#endif // PATIENTENTITY_H
