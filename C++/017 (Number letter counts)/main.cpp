/*
Alex Slater Project Euler 017
Add all the letters in the numbers 1-1000 excluding spaces/hyphens and using "and" - eg: four hundred and thirty six
*/
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    int currentTotal = 0;
    long int total = 0;
    for(int i=1; i<=1000; i++)
    {
        currentTotal=0;
	if(i>=1000) {
	    currentTotal += 8; //Thousand
	    switch(i/1000) {
		case 1: currentTotal += 3; break;
		case 2: currentTotal += 3; break;
		case 3: currentTotal += 5; break;
		case 4: currentTotal += 4; break;
		case 5: currentTotal += 4; break;
		case 6: currentTotal += 3; break;
		case 7: currentTotal += 5; break;
		case 8: currentTotal += 5; break;
		case 9: currentTotal += 4; break;
	    }
	}
	if((i/100)%10!=0){ //We have some hundreds
	    currentTotal += 7; //Hundred
	    switch(i/100) {
		case 1: currentTotal += 3; break;
		case 2: currentTotal += 3; break;
		case 3: currentTotal += 5; break;
		case 4: currentTotal += 4; break;
		case 5: currentTotal += 4; break;
		case 6: currentTotal += 3; break;
		case 7: currentTotal += 5; break;
		case 8: currentTotal += 5; break;
		case 9: currentTotal += 4; break;
	    }
	}
	if(i%100>=20) { //Get all that doesnt end with 0x or 1x
	    switch((i%100)/10) { //Gives us single digit nunbers for each
		case 2: currentTotal += 6; break; //Twenty
		case 3: currentTotal += 6; break; //Thirty
		case 4: currentTotal += 5; break; //Forty
		case 5: currentTotal += 5; break; //Fifty
		case 6: currentTotal += 5; break; //Sixty
		case 7: currentTotal += 7; break; //Seventy
		case 8: currentTotal += 6; break; //Eighty
		case 9: currentTotal += 6; break; //Ninety
	    }
	}
	if(i%100>=10 && i%100<20) { //Ends with 1x
	    switch(i%100) {
		case 10: currentTotal += 3; break; //Ten
		case 11: currentTotal += 6; break; //Eleven
		case 12: currentTotal += 6; break; //Twelve
		case 13: currentTotal += 8; break; //Thirteen
		case 14: currentTotal += 8; break; //Fourteen
		case 15: currentTotal += 7; break; //Fifteen
		case 16: currentTotal += 7; break; //Sixteen
		case 17: currentTotal += 9; break; //Seventeen
		case 18: currentTotal += 8; break; //Eighteen
		case 19: currentTotal += 8; break; //Nineteen
	    }
	}
	if((i/10)%10!=1) { //Not teen
	    switch(i%10) {
		case 1: currentTotal += 3; break; //One
		case 2: currentTotal += 3; break; //Two
		case 3: currentTotal += 5; break; //Three
		case 4: currentTotal += 4; break; //Four
		case 5: currentTotal += 4; break; //Five
		case 6: currentTotal += 3; break; //Six
		case 7: currentTotal += 5; break; //Seven
		case 8: currentTotal += 5; break; //Eight
		case 9: currentTotal += 4; break; //Nine
	    }
	}
	if(i/100!=0 && i%100!=0) { //If over 100 and has value in tens or ones, we need to add an "and" (three hundred and five)
	    currentTotal += 3; //And
	}
	//cout << i << " = " << currentTotal << endl;
	total += currentTotal;
    }
    cout << total;
    return 0;
}
