/*
Alex Slater Project Euler 014
Find the number under 1 million that produces the longest Collatz sequence
*/
#include <iostream>

using namespace std;

int main()
{
    unsigned int highestLength = 0;
    unsigned int highestNumber = 0;
    unsigned int currentLength = 0;
    unsigned long long int currentNumber = 0;

    for(int i=1; i<1000000; i++)
    {
        currentNumber = i;
        while(currentNumber != 1)
        {
            if(currentNumber%2 == 0)
            {
                currentNumber = currentNumber/2;
            }
            else
            {
                currentNumber = (currentNumber*3)+1;
            }

            currentLength++;
        }

        //cout << i << " is finished" << endl;
        if(currentLength > highestLength)
        {
            highestNumber = i;
            highestLength = currentLength;
        }

        currentLength = 0;
    }
    cout << highestNumber << " with a sequence length of " << highestLength;
    return 0;
}
