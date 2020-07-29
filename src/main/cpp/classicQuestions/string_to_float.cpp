#include<bits/stdc++.h>
#include<iostream>

using namespace std;

long double convertToFloat(string s){
	
	// Expecting a string with digits
	long double x = 0.0;
	bool negativeFlag = false;
	long double decimalPart = 0.0;

	string intString = "";
	string decimalString = "";


	if (s.find('.') != std::string::npos){
		intString = s.substr(0, s.find('.'));
		decimalString = s.substr(s.find('.')+1, s.size());
	}


	// Processing Integer Part
	for (int i = 0; i < intString.size(); i++){
		if (x!=0 && abs(INT_MAX/x) < 10){
			std::cout << "Overflow" << std::endl;
			return x;
		}
		else if (intString[i] != '-'){
			x = x*10 + intString[i]-'0';
		}
		else{
			negativeFlag = true;
		}
	}

	// Processing Decimal Part
	for (int i = 0; i < decimalString.size(); i++){
		decimalPart = decimalPart*10 + decimalString[i]-'0';
	}
	decimalPart = decimalPart/(pow(10,decimalString.size()));

	// std::cout << decimalPart << "\n";

	x+= decimalPart;

	std::cout << std::setprecision(15) << std::to_string(x) << std::endl;
	return negativeFlag?-x:x;
}

int main(){

	string s1 = "12.554656346";
	long double result = convertToFloat(s1);
	return 0;
}