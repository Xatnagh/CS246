#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Node.h"
#include "Stack.h"
using namespace std;
void ReverseContent(std::ifstream& in,std::ofstream& out)
{
    return;
}

bool IsPattern(std::string str)
{   
    if(str[0]!='a')return false;
    if(str[1]!='^')return false;
    if(!(str[2]>='1'&&str[2]<='9'))return false;
    if(str[3]!='b')return false;
    if(str[4]!='^')return false;
    if(!(str[5]>='1'&&str[5]<='9'))return false;
    return true;
}

int main()
{
    string sample ="a^4b^4";
    cout<<IsPattern(sample)<<endl;
    return 0; 
}
