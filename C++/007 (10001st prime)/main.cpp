/*
Alex Slater Project Euler 007
Find the 10001st prime
*/
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

bool isPrime(int n)//Taken from 003 solution
{
    if(n == 0 || n == 1)//Special case, 0 and 1 are not prime
    {
        return false;
    }
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> primes;
    int counter = 0;
    while(primes.size() < 10001)
    {
        counter++;
        if(isPrime(counter))
        {
            primes.push_back(counter);
        }
    }
        cout << primes.at(10000);//Not 10001 as 0 is a valid place
    return 0;
}
