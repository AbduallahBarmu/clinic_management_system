#ifndef PHARMACYENTITY_H
#define PHARMACYENTITY_H
#include <string>

using namespace std;
class PharmacyEntity
{
    public:
        PharmacyEntity();
        virtual ~PharmacyEntity();
        string m_name,m_dose,m_category;
        string m_ID;
        float m_price;
        string getSpec();
        void addMed();
        int editMed(PharmacyEntity &medobj);
        int deleteMed();
        void dispDatabase();
        void numberofMeds();

    protected:

    private:
};

#endif // PHARMACYENTITY_H
