/*
Alex Slater Project Euler 021
Get the sum of all amicable numbers under 10000
*/
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> getProperFactors(int n)
{
    vector<int> factors;
    for(int x=2; x<=sqrt(n); x++)
    {
        if(n%x==0)
        {
            factors.push_back(x);
            if(x != sqrt(n))
            {
                factors.push_back(n/x);//If x= sqrt(n), n/x = x, this would give a repeated number
            }
        }
    }
    factors.push_back(1);//We got rid of 1 to stop n being put as a factor as it is not proper
    return factors;
}

int countVector(vector<int> vec)//Taken from #20
{
    int counter = 0;
    for(int d=0; d<vec.size(); d++)
    {
        counter += vec.at(d);
    }
    return counter;
}

int main()
{
    vector<int> amicableNumbers;
    int total = 0;
    for(int i=1; i<=10000; i++)
    {
        if(i == countVector(getProperFactors(countVector(getProperFactors(i)))) && i != countVector(getProperFactors(i)))//a = i and b = d(a), does d(b) = a? Also be sure a != b
        {
            amicableNumbers.push_back(i);
        }
    }
    for(int i=0; i<amicableNumbers.size(); i++)
    {
        total += amicableNumbers.at(i);
    }
    cout << total;
    return 0;
}
