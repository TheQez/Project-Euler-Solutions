/*
Alex Slater Project Euler 012
Find the first triangular number to have over 500 divisors (factors)
*/
#include <iostream>
#include <math.h>

/*int triangle(int n)
{
    int total;
    for(int x=1; x<=n; x++)
    {
        total += x;
    }
    return total;
}*/
using namespace std;

int main()
{
    long long int counter = 0;
    long long int currentNumber = 0;
    int factorAmount = 0;
    while(true)
    {
        counter++;
        currentNumber += counter; //Get next triangle number
        factorAmount = 0;
        for(long int i=1; i<=sqrt(currentNumber); i++)
        {
            if(currentNumber%i == 0)//We have factor
            {
                if(i == sqrt(currentNumber)) //There must be a second factor above the root unless it is the root
                {
                    factorAmount += 1;
                }
                else
                {
                    factorAmount += 2;
                }
            }
        }
        //cout << factorAmount << endl;
        if(factorAmount > 500)
        {
            cout << currentNumber;
            return 0;
        }
    }
    return 1;
}
