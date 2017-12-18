/*
Alex Slater Project Euler 002
Find the sum of all even Fibonacci numbers whose values do not exceed 4 million
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int counter = 0;
    vector<int> sequence;
    sequence.push_back(0);
    sequence.push_back(1);
    while(sequence.at(sequence.size()-1) + sequence.at(sequence.size()-2) <= 4000000)
    {
        sequence.push_back(sequence.at(sequence.size()-1) + sequence.at(sequence.size()-2)); //Add the next fib number based on two previous ones
    }
    for(int i=0; i!=sequence.size(); i++)
    {
        if(sequence.at(i)%2 == 0)
        {
            counter+=sequence.at(i);
        }
    }
    cout << counter;
    return 0;
}
