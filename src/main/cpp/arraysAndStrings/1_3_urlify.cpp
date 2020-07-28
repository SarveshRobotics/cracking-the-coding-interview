#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void urlify_string(string& str, int TrueLength){

	// Count the number of spaces
	int spaceCount = 0;
	
	for (int i=0; i<TrueLength; i++){
		if (str[i] == ' ') spaceCount++;
	}


	int finalIndex = spaceCount*2 + TrueLength;

	for(int i = TrueLength-1; i >= 0; i--){
		if (str[i] == ' '){
			str[finalIndex - 1] = '0';
			str[finalIndex - 2] = '2';
			str[finalIndex - 3] = '%';
			finalIndex -= 3;
		}
		else{
			str[finalIndex - 1] = str[i];
			finalIndex--;
		}
	}
}


int main(){

	string input = "Mr John Smith    ";
	
	int trueLength = 13;

	urlify_string(input, trueLength);

	std::cout << input << std::endl;

	return 0;
}