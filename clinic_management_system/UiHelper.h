#ifndef UIHELPER_H
#define UIHELPER_H

#include <string>
using namespace std;

class UiHelper
{
    public:
        static void printTitle(string title);
        static void printChoice(string title);
        static void printHorizontalLine();
        static void printFeedback(string title);
};

#endif // UIHELPER_H
