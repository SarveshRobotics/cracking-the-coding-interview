#pragma once

#include<bits/stdc++.h>

template <class T>

class Stack{

private:
	int capacity;
	std::vector<T> data;
	std::vector<T> minData;

public:
	Stack();
	Stack(int x);
	
	T Top();
	T Min();

	bool isEmpty();
	
	void Push(T item);
	void Pop();
};