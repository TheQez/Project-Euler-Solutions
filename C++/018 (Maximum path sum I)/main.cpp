/*
Alex Slater Project Euler 018
Find the route down a triangle that gives the highest sum and display that sum
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector< vector<int> > getTriangle()//Returns a bi-dimentional vector of fixed size (15, 15) containing the triangle
{
    vector< vector<int> > triangle(15, vector<int>(15));

    ifstream file;
    file.open("triangle.txt", ifstream::in);
    for(int x=0; x<15; x++)
    {
        for(int y=0; y<=x; y++)
        {
            file >> triangle[x][y];
        }
    }
    return triangle;
}

int main()
{
    vector< vector<int> > triangle = getTriangle();
    vector< vector<int> > highestTotal(15, vector<int>(15));
    for(int i=14; i>=0; i--)
    {
        for(int j=i; j>=0; j--)
        {
            if(i==14)
            {
                highestTotal[i][j] = triangle[i][j];//If at the bottom so we dont try and get values from outside the array
            }
            else
            {
                highestTotal[i][j] = max(highestTotal[i+1][j], highestTotal[i+1][j+1]) + triangle[i][j];//Gets best of each previous total and adds its own value
            }
        }
    }
    cout << highestTotal[0][0];
    return 0;
}
