/*
Alex Slater Project Euler 023
Find the sum of all positive integers that cannot be written as the sum of two abundant numbers (numbers whose sum of factors is greater than itself)
*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> getProperFactors(int n) //Taken from 021
{
    vector<int> factors;
    for(int x=2; x<=sqrt(n); x++)
    {
        if(n%x==0)
        {
            factors.push_back(x);
            if(x != sqrt(n))
            {
                factors.push_back(n/x);//If x= sqrt(n), n/x = x, this would give a repeated number
            }
        }
    }
    if(n > 2) {
        factors.push_back(1);//We got rid of 1 to stop n being put as a factor as it is not proper
    }
    return factors;
}

bool isAbundant(int n) {
    vector<int> factors = getProperFactors(n);
    int sumFactors = 0;
    for (int i=0; i<factors.size(); i++) {
        sumFactors += factors.at(i);
    }
    if(sumFactors > n){
        return true;
    }
    else {
        return false;
    }
}
int main()
{
    vector<int> abundantNumbers;
    for(int i=0; i<=28123; i++) { //All numbers above 28123 can be written as the sum of two abundant numbers, we only need to check numbers up to 28123 to get sums
        if(isAbundant(i) == true) {
            abundantNumbers.push_back(i);
        }
    }
    vector<int> notSumAbundantNumbers;
    bool abundant;
    for(int i=0; i<=28123; i++) {
        abundant = false;
        for(int j=0; j<abundantNumbers.size(); j++)
        {
            //cout << i-abundantNumbers.at(j) << endl;
            //cout << "i= " << i << "Abundant= " << abundantNumbers.at(j) << endl;
            if(i < abundantNumbers.at(j)) { //If we have gone through all abundant numbers below i (that can sum to i), i is not abundant
                break;
            }
            if(isAbundant(i - abundantNumbers.at(j))) { //i - an abundant number = another abundant number, i is the sum of 2 abundant numbers
                abundant = true;
                break;
            }
        }
        if(!abundant) {
            notSumAbundantNumbers.push_back(i);
        }
    }
    int sum = 0;
    for (int i=0; i<notSumAbundantNumbers.size(); i++) {
        //cout << notSumAbundantNumbers.at(i) << " , ";
        sum += notSumAbundantNumbers.at(i);
    }
    cout << sum << endl;
    return 0;
}
