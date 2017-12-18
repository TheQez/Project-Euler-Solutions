/*
Alex Slater Project Euler 010
Find the sum of all primes under 2 million
*/
#include <iostream>
#include <vector>
#include <math.h>

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
    for(int i=0; i<2000000; i++)
    {
        if(isPrime(i))
        {
            primes.push_back(i);
        }
    }
    long long int total=0;
    for(int i=0; i<primes.size(); i++)
    {
        total += primes.at(i);
    }
    cout << total;
    return 0;
}
