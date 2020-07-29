#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int convertToInteger(string s){
	// Expecting a string with digits
	int x = 0;
	bool negativeFlag = false;

	for (int i = 0; i < s.size(); i++){
		// std::cout << s[i] << std::endl;
		if (x!=0 && abs(INT_MAX/x) < 10){
			std::cout << "Overflow" << std::endl;
			return x;
		}
		else if (s[i] != '-'){
			x = x*10 + s[i]-'0';
			// std::cout << x << std::endl;
		}
		else{
			negativeFlag = true;
		}
	}
	return negativeFlag?-x:x;
}

int main(){

	string s1 = "-1234464466455455678";

	int result = convertToInteger(s1);
	std::cout << result << std::endl;

	return 0;
}