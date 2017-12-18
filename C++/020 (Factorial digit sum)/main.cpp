/*
Alex Slater Project Euler 020
Get the sum of all the digits in 100!
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

vector<int> multiplyVector(vector<int> a, vector<int> b)
{
    vector<int> total(a.size() + b.size());
    for(int x=0; x<a.size(); x++)
    {
        for(int y=0; y<b.size(); y++)
        {
            //cout << a.at(x) << "(" << x << ")" << " " << b.at(y) << "(" << y << ")" << endl;
            total.at(x+y) += a.at(x) * b.at(y);
        }
    }

    for(int x=0; x<total.size(); x++)
    {
        if(total.at(x) > 10)
        {
            total.at(x+1) += total.at(x)/10;
            total.at(x) = total.at(x)%10;
        }
    }
    return total;
}

vector<int> toVector(int n)
{
    ostringstream ss;
    ss << n;
    string str = ss.str();
    vector<int> vec;
    for(int z=str.size()-1; z>=0; z--)
    {
        vec.push_back(atoi(str.substr(z, 1).c_str()));
    }
    return vec;
}

void printVector(vector<int> n)
{
    for(int c=n.size()-1; c>=0; c--)
    {
        cout << n.at(c);
    }
}

int countVector(vector<int> vec)
{;
    int counter = 0;
    for(int d=0; d<vec.size(); d++)
    {
        counter += vec.at(d);
    }
    return counter;
}

int main()
{
    vector<int> currentTotal = toVector(1);
    //printVector(multiplyVector(toVector(20), toVector(12)));
    for(int i=2; i<=100; i++)
    {
        currentTotal = multiplyVector(currentTotal, toVector(i));
    }
    int digitSum = countVector(currentTotal);
    cout << digitSum;
    return 0;
}
