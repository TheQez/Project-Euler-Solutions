/*
Alex Slater Project Euler 004
Find the largest palindrome that is a product of two 3 digit numbers
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int i, j, x;

bool isPalindrome(int n)
{
    ostringstream oss;
    oss << n;
    string s = oss.str(); //Change number to string

    if(s.length()%2 == 0) //even
    {
        for(x=0; x<(s.length()/2); x++)
        {
            if(s.at(x) != s.at((s.length()-1)-x)) //If number at start doesn't equal number at end and close in to check all
            {
                return false;
            }
        }
    }
    else //odd
    {
        for(x=0; x<(s.length()-1)/2; x++)
        {
            if(s.at(x) != s.at((s.length()-1)-x)) //If number at start doesn't equal number at end and close in to check all
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    for(i=999999; i>0; i--)
    {
        if(isPalindrome(i))
        {
            for(j=100; j<1000; j++)
            {
                if((i/j)>=100 && (i/j)<=999 && i%j==0) //If i/j is between 100 and 1000 and is an integer, i is the answer
                {
                    cout << i << " = " << j << "*" << i/j;
                    return 0;
                }
            }
        }
    }
    return 1;
}
