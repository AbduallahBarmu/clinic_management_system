#ifndef PASSWORDFILEHELPER_H
#define PASSWORDFILEHELPER_H

#include <string>
using namespace std;


class PasswordFileHelper
{
    public:
        static bool checkPasswordFileExists();
        static string readPasswordFile();
        static string getPassword();
        static void writePasswordFile(string password);
};

#endif // PASSWORDFILEHELPER_H
