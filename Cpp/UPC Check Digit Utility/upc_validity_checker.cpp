/*
 * This code is NOT intended to be readable.
 * It was made with the goal of being short,
 * as opposed to drawing it out a bit more for the sake of readability.
 *
 * Read in a 12 digit number and use the check digit to verify if it is a valid UPC code or not.
*/


#include <iostream>
#include <string>

using namespace std;

int main(){
	const int l = 12; // Standard 12 digit UPC code.
	string x="";
	cin>>x;
	int o=0;
	for(size_t i=0;i<x.size()-1;++i)
		o+=i%2==0?(x.at(i)-'0')*3:x.at(i)-'0';
	if((x.at(x.size()-1)-'0'!=(o%10==0?0:10-o%10))||x.size()!=l)
		cout<<"Invalid UPC."<<endl;
	else
		cout<<"Valid UPC."<<endl;
	return 0;
}
