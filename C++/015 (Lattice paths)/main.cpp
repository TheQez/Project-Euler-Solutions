/*
Alex Slater Project Euler 015
Find how many possible paths there are for a 20x20 lattice from top left to bottom right when you can only move down or right

To make the programming easier, I will have the end point at the top left corner, this will make it more understandable and easier to get the answer for different shaped lattices
*/
#include <iostream>

using namespace std;

int main()
{
    const int latticeWidth = 20;
    const int latticeHeight = 20;
    unsigned long long int lattice[latticeWidth+1][latticeHeight+1] = {0};//20x20 as we only need that, could be made bigger but will use more resources to generate, +1 as a 20x20 lattice will have 21x21 lines


    for(int i=0; i<=latticeWidth; i++)//to set sides as 1, used to calculate other number further up
    {
        lattice[i][0] = 1;
    }
    for(int i=0; i<=latticeHeight; i++)
    {
        lattice[0][i] = 1;
    }

    for(int i=1; i<=latticeWidth; i++)
    {
        for(int j=1; j<=latticeHeight; j++)
        {
            lattice[i][j] = lattice[i-1][j] + lattice[i][j-1];
        }
    }
    cout << lattice[20][20];
    return 0;
}
