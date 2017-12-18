/*
Alex Slater Project Euler 025
Find the first Fibonacci number with 1000 digits
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> addVector(vector<int> a, vector<int> b) {
    vector<int> t;
    for(int i=0; i<max(a.size(), b.size()); i++) {
	t.push_back(a.at(i) + b.at(i));
    }
    for(int j=0; j<t.size(); j++) {
	if(t.at(j)/10 != 0) {
	    if (j == t.size()-1) {
		t.push_back(0); //To prevent problems if at the end
	    }
	    t.at(j+1) += t.at(j)/10;
	    t.at(j) += t.at(j)%10;
	}
    }
}

void printVector(vector<int> n) {
    for(int j=n.size()-1; j<=0; j--) {
	cout << n.at(j);
    }
    cout << endl;
}

int main() {
    vector< vector<int> > fibSequence; //Numbers are represented backwards in this
    fibSequence.push_back({0});
    fibSequence.push_back({1});
    for(int i=2; i<=10; i++) {
	fibSequence.push_back(addVector(fibSequence.at(i-1), fibSequence.at(i-2))); //Get next fib number
    }
    printVector(fibSequence.at(10));
}
