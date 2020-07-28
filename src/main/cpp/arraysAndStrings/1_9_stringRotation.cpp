#include<bits/stdc++.h>
#include<iostream>

using namespace std;

string rotate_efficient(string s, int k){
	string result = "";

	k = k%s.size();

	result = s.substr(k,s.size())+ s.substr(0,k);
	std::cout <<  result << "\n";
	return result;
}

string rotate(string s, int k){
	string result(s);
	for (int i=0; i<s.size(); i++){
		if (i+k < s.size())
			result[i+k] = s[i];
		else
			result[i+k-s.size()] = s[i];
	}

	// std::cout << k << " : " << result<< std::endl;
	return result;
}

bool isRotation(string s1, string s2){
	if (s1.size() != s2.size()) return false;

	for (int i = 1; i < s1.size(); i++){
		if (s1 == rotate_efficient(s2, i))
			return true;
	}
	return false;
}

int main(){

	string s1 = "waterbottle";
	string s2 = "bottlewater";

	bool result = isRotation(s1, s2);
	std::cout << result << std::endl;

	return 0;
}