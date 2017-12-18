/*
Alex Slater Project Euler 024
Find the millionth lexicographic permutation of the numbers 0-9
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> number = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int switchPosition;
    int highNumber;
    int highNumberPosition;
    int i;
    for(i=1; i<1000000; i++) {
	/*cout << i << "= ";
	for (int j=0; j<number.size(); j++) {
	    cout << number.at(j);
	}
	cout << endl;*/
	for(int j=8; j>=0; j--) {
	    if(number.at(j+1) > number.at(j)) { //If the higher order digit is lower we can switch them to get a higher overall number
		switchPosition = j;
		break;
	    }
	}
	
	highNumber = 10;
	for(int j=switchPosition; j<number.size(); j++) { //For finding next highest number of lower order than our switch position
	    if(number.at(j) > number.at(switchPosition) && number.at(j) < highNumber) { //If higher than our switch position and lower than the high number we found
		highNumber = number.at(j);
		highNumberPosition = j; 
	    }
	}
	
	number.at(highNumberPosition) = number.at(switchPosition); //Put our switch position into the before numbers to allow the new high number to switch with it
	number.at(switchPosition) = highNumber;
	sort(number.begin() + switchPosition + 1, number.end()); //Sorts all numbers after the switch position into numerical order
    }
    cout << i << "= ";
    for (int j=0; j<number.size(); j++) {
	cout << number.at(j);
    }
    cout << endl;
}

















