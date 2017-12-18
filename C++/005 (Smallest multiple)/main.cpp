/*
Alex Slater Project Euler 005
Find the smallest number that is divisible by all numbers between 1 and 20
*/
#include <iostream>
#include <vector>

using namespace std;

int i=1;
int counter=0;
int main()
{
    while(true)
    {
        counter++;
        for(i=1; i<=20; i++)
        {
            if(counter%i!=0)
            {
                break;
            }
            if(i==20)
            {
                cout << counter;
                return 0;
            }
        }
    }
    return 1;
}
