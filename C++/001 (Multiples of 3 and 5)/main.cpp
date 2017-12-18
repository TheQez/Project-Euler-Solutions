/*
Alex Slater Project Euler 001
Add up all multiples of 3 or 5 between 1 and 1000 and display them
*/
#include <iostream>

using namespace std;

int main()
{
    int counter = 0;
    for(int i=1; i!=1000; i++)
    {
        if(i%3 == 0 || i%5 == 0)
        {
            counter += i;
        }
    }
    cout << counter;
    return 0;
}
