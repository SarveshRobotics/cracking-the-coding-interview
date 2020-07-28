#include<bits/stdc++.h>
#include<iostream>
// #include<string>

using namespace std;

string compressString(string s){

	string result = "";
	char candidate = s[0];
	int count = 1;

	for (int i=1; i<s.size(); i++){
		if (s[i] == candidate){
			count++;
		}
		if (s[i] != candidate or i == s.size()-1){
			result += candidate + to_string(count);
			candidate = s[i];
			count = 1;
		}
	}

	return result;

}




int main(){
	string s1 = "aabccccaaa";
	string s2 = "pales";
	
	string result = compressString(s1);
	std::cout << result << std::endl;

	return 0;
}