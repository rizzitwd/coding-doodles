#include <iostream>
#include <string>

using namespace std;

/*
 * This code is NOT intended to be readable.
 * It was made with the goal of taking up very little space,
 * as opposed to drawing it out a bit more for the sake of readability.
 * 
 * Read in an 11-digit UPC code and generate the check digit for this code. 
 * 
 * - Input
 * 	Create a string, then read into it from cin.
 * 	Read into the string again for as long as its above l characters, where l is the upc code length predetermined at compile time.
 * 	Fill in '0's from the start to make sure it is exactly l characters.
 * - Calculations
 * 	Create integer i for the loop that follows; Create integer o as a variable for the sum of the calculations.
 * 	Iterate over each index of the string.
 * 	If the digit is at an odd numbered index, add the number multiplied by 3 to o.
 * 	If at an even numbered index, just add the number to o.
 * 	I use " x.at(i)-'0' " to convert the character index returned by x.at(i) to an integer so I can add it to o.
 * - Output
 * 	Read the UPC code given at the start of the program to cout,
 * 	followed by '+', then the check digit.
 * 	If o % 10 is 0, the check digit is 0. Otherwise, it is 10 - ( o % 10 )
*/

int main(){
	const int l = 12; // Standard 12 digit UPC code, including check digit.
	string x="";
	do {cin>>x;} while(x.size()>l-1);
	while(x.size()<l-1)
		x.insert(0,"0");
	int i=0,o=0;
	for(;i<l-1;++i)
		o += (i % 2 == 0 ? (x.at(i)-'0')*3 : x.at(i)-'0');
	cout << x << '+' << (o % 10 == 0 ? 0 : 10-o%10) << endl;
	return 0;
}
