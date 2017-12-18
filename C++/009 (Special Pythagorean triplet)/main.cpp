/*
Alex Slater Project Euler 009
Find the only Pythagorean triplet where a + b + c = 1000 and a, b, c are integers to get product abc
*/
#include <iostream>
#include <math.h>

using namespace std;

bool isSquare(int n)
{
    if(floor(sqrt(n)) == sqrt(n))//check if sqrt(n) is whole
    {
        return true;
    }
    return false;
}
int main()
{
    cout << fixed;//no exponential form
    for(int i=1000; i>0; i--)
    {
        for(int j=i-1; j>0; j--)//j=i works, but it returns all values where j=i as valid which doesn't technically make a triangle, would produce a=0, b=500, c=500 as a wrong answer
        {
            //cout << i << " " << j << endl;
            if(isSquare((i*i)-(j*j)))//if a^2 + b^2 = c^2 would work with c = i and b = j
            {
                //cout << i << " " << j << endl;
                if(i+j+sqrt((i*i)-(j*j)) == 1000)//get 2 answers but both are just swapped versions
                {
                    cout << "a= " << int(sqrt((i*i)-(j*j))) << " b= " << j << " c= " << i << " abc= " << int(i*j*sqrt((i*i)-(j*j))) << endl;//int is to stop trailing 0 on a and abc
                }
            }
        }
    }
    return 0;
}
