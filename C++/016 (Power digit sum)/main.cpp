/*
Alex Slater Project Euler 016
Get the sum of all the digits in 2^1000
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> arrayDouble(vector<int> n)
{
    vector<int> total;
    int carry = 0;
    for(int i=0; i<=n.size(); i++)
    {

        if(i<n.size())
        {
            total.push_back((n.at(i)*2) + carry);//Set the total to the addition
            carry = total.at(i)/10;//Find the carry (makes use of integer division)
            total.at(i) -= carry*10;//Subtract what needs to be carried
        }
        else if(carry != 0 && i==n.size())
        {
            total.push_back(carry);
        }
    }
    return total;
}

void printVector(vector<int> n)//Was used in debugging, currently not used
{
    for(int x=n.size()-1; x>=0; x--)
    {
        cout << n.at(x);
    }
}
int main()
{
    vector<int> n;
    n.push_back(2);
    for(int i=1; i<1000; i++)
    {
        /*cout << "2^" << i << " = ";
        printVector(n);
        cout << endl;*/
        n = arrayDouble(n);
    }
    //printVector(n);
    int currentTotal = 0;
    for(int i=0; i<n.size(); i++)
    {
        currentTotal += n.at(i);
    }
    cout << currentTotal;
    return 0;
}
