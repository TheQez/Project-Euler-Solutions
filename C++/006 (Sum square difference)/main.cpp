/*
Alex Slater Project Euler 006
Find the difference between the square of the sum and the sum of the squares of the first 100 natural numbers (1-100)
*/
#include <iostream>

using namespace std;

int main()
{
    int sumSquares = 0;
    int squareSum;

    for(int i=1; i<=100; i++)
    {
        sumSquares += i*i;
    }

    for(int i=1; i<=100; i++)
    {
        squareSum += i;
    }
    squareSum = squareSum*squareSum;

    cout << squareSum-sumSquares;
    return 0;
}
