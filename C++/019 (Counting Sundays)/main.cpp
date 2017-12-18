/*
Alex Slater Project Euler 019
Calculate the amount of Sundays between 1st January 1901 to 31st December 2000
*/
#include <iostream>

using namespace std;

int main()
{
    int normalYear [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leapYear [12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int currentDay = 2;//0 being Sunday, 6 being Saturday (this is 1st Jan 1901)
    int sundayCount = 0;

    for(int i=1901; i<=2000; i++)
    {
        if(i%4 == 0)//Leap year
        {
            for(int j=0; j<12; j++)
            {
                if(currentDay % 7 == 0)//Sunday
                {
                    sundayCount++;
                }
                currentDay = (currentDay % 7);
                currentDay += leapYear [j];
            }
        }
        else//Normal year
        {
            for(int j=0; j<12; j++)
            {
                if(currentDay % 7 == 0)//Sunday
                {
                    sundayCount++;
                }
                currentDay = (currentDay % 7);//Same day but stops the number from increasing too high
                currentDay += normalYear [j];
            }
        }
    }
    if(currentDay % 7 == 0)//Sunday
    {
        sundayCount++;
    }
    cout << sundayCount;
    return 0;
}
