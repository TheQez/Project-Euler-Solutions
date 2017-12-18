/*
Alex Slater Project Euler 003
Find the largest prime factor of 600851475143
*/
#include <iostream>
#include <math.h> //for sqrt function
#include <vector>

using namespace std;

bool isPrime(long long int n)
{
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }
    return true;
}

int getPrimeFactor(long long int n)
{
    for(int i=2; i<=sqrt(n); i++)
    {
        if(isPrime(i) && n%i==0)
        {
            return i;
        }
    }
    return n;
}

int main()
{
    vector<int> primeFactors;
    long long int number = 600851475143;
    long long int newFactor;
    while(newFactor != number)
    {
        newFactor = getPrimeFactor(number);
        primeFactors.push_back(newFactor);
        number /= newFactor;
    }
    int currentHighest;
    for(int i=0; i!=primeFactors.size(); i++)
    {
        if(primeFactors.at(i) > currentHighest)
        {
            currentHighest = primeFactors.at(i);
        }
    }
    cout << currentHighest;
    return 0;
}
