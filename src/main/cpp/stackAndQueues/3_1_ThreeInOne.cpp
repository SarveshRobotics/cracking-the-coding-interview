/*
	Describe how you could use a single array to implement three stacks.
*/

#include "Stack.h"

template <class T>

// Constructor Definition
Stack<T>::Stack(){
	capacity = 10;
}

template <class T>
Stack<T>::Stack(int x){
	capacity = x; // Manually set capacity
}

template <class T>
bool Stack<T>::isEmpty(){
	return data.empty();
}

template <class T>
void Stack<T>::Push(T x){
	if (data.size() >= capacity){
		std::cout << "Reached Capacity!!! Remove Elements first!" << std::endl;
	}
	else{
		data.push_back(x);
		if (!minData.size()) minData.push_back(x);
		else if (x <= minData.back()){
			minData.push_back(x);
		}
	}
}

template <class T>
void Stack<T>::Pop(){
	T last = data.back();
	data.pop_back();
	if (last == minData.back()){
		minData.pop_back();
	}

}

template <class T>
T Stack<T>::Top(){
	return data.back();
}

template <class T>
T Stack<T>::Min(){
	return minData.back();	
}


int main(){

	Stack<int> stack(10);
	stack.Push(5);
	stack.Push(51);
	stack.Push(50);
	stack.Push(1);
	std::cout << stack.Top() << std::endl;
	std::cout << stack.Min() << std::endl;
	stack.Pop();
	std::cout << stack.Top() << std::endl;
	std::cout << stack.Min() << std::endl;
	

	return 0;
}

