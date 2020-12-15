#include "UiHelper.h"
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


void UiHelper::printTitle(string title)
{
    transform(title.begin(), title.end(),title.begin(), ::toupper);
    cout<<endl<<"               "<<title<<endl;
}

void UiHelper::printHorizontalLine()
{
    cout<<"            "<<"------------------------------------------------------------------"<<endl;
}

void UiHelper::printChoice(string choice)
{
    cout<<"                             "<<choice<<endl;
}

void UiHelper::printFeedback(string feedback)
{
    cout<<"                     "<<feedback<<endl;
}
