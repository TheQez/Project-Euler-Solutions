/*
Alex Slater Project Euler 022
Get the total name score from a list of names
*/
#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    map <char, int> letterScore;
    letterScore['A'] = 1;
    letterScore['B'] = 2;
    letterScore['C'] = 3;
    letterScore['D'] = 4;
    letterScore['E'] = 5;
    letterScore['F'] = 6;
    letterScore['G'] = 7;
    letterScore['H'] = 8;
    letterScore['I'] = 9;
    letterScore['J'] = 10;
    letterScore['K'] = 11;
    letterScore['L'] = 12;
    letterScore['M'] = 13;
    letterScore['N'] = 14;
    letterScore['O'] = 15;
    letterScore['P'] = 16;
    letterScore['Q'] = 17;
    letterScore['R'] = 18;
    letterScore['S'] = 19;
    letterScore['T'] = 20;
    letterScore['U'] = 21;
    letterScore['V'] = 22;
    letterScore['W'] = 23;
    letterScore['X'] = 24;
    letterScore['Y'] = 25;
    letterScore['Z'] = 26;

    ifstream nameFile;
    nameFile.open ("names.txt", ios::in);
    vector<string> names;
    string name;
    while(!nameFile.eof()) { //Stop once we hit end of file
        name = "";
        getline(nameFile, name, ',');
        name = name.substr(1, name.length()-2); //Trim off the speech marks
        names.push_back(name);
    }
    sort(names.begin(), names.end());
    int nameScore = 0;
    long int totalScore = 0;
    for(int i=0; i<names.size(); i++) {
        nameScore = 0;
        for(int j=0; j<names.at(i).length(); j++) {
            nameScore += letterScore[names.at(i) [j]]; //Add each letter's score to the names value
        }
        totalScore += nameScore * (i+1); //i+1 is the names position as we start at 0
    }
    cout << totalScore;
    return 0;
}
