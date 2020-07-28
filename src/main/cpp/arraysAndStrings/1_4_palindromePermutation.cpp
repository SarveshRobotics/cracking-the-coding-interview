#include<bits/stdc++.h>
#include<iostream>

using namespace std;

bool checkPermutation(string str){
	
	// Store all char's frequency first time and remove second time, do alternatively
	std::unordered_map<char, int> hashMap;

	for (auto c:str){
		if (c == ' ') continue;
		if (isupper(c)) c = tolower(c);
		
		hashMap[c]++;
	}

	int oddCount = 0;

	for (auto key:hashMap){
		if (key.second %2 != 0) oddCount++;
		if (oddCount>1)	return false;
	}

	std::cout << "Palindrome Permutation" << std::endl;
	return true;
}


int main(){

	string input = "Tactt Coa"; // Case-Insensitive
	
	checkPermutation(input);

	return 0;
}