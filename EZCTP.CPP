#include <iostream>
#include <string>
#include "EZCTP.H"

void EZCTPString(char* ctpString, std::string &str) //assume ctpString has allocated its memory
{
    int length = str.length() + 1;
    for (int i = 0; i < length; i++)
    {
        ctpString[i] = str[i];
    };
};
void countF()
{
    int counter = 0;
    while (counter < 500000) {
        counter++;
    }
}