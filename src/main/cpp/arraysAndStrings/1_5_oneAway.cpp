#include<bits/stdc++.h>
#include<iostream>

using namespace std;

bool remove(string shortStr, string longStr){
	// remove the different element from the longStr; Expects difference only by 1 char
	int i = 0;
	for (i; i<shortStr.size(); i++){
		if (shortStr[i] != longStr[i]) break;
	}

	longStr.erase(longStr.begin() + i);

	return shortStr==longStr;
}

bool replace(string s1, string s2){
	// replace the first character that's different

	for (int i = 0; i < s1.size(); i++){
		if (s1[i] != s2[i]){
			s2[i] = s1[i];
			break;
		}
	}
	return s1 == s2;
}

bool oneAway(string& s1, string& s2){

	if (s1 == s2) return false;
	if (abs(int(s1.size() - s2.size())) > 1) return false;
	
	// If remove works out return true
	bool removeFlag = false;
	if (s1.size() > s2.size())
		removeFlag = remove(s2,s1);
	else if (s1.size() < s2.size())
		removeFlag = remove(s1, s2);

	if (removeFlag)
		return true;
	else if (s1.size() == s2.size())
		return replace(s1, s2);
}



int main(){

	string s1 = "psales";
	string s2 = "pales";
	
	bool result = oneAway(s1, s2);
	if (result) std::cout << "Yes\n";
	else std::cout << "No\n";

	return 0;
}