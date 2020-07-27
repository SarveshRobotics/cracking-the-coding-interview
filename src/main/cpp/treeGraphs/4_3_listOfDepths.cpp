/*
	List of Depths: Given a binary tree, design an algorithm which creates a linked list
	of all nodes at each depth.
	for D depth, there will be D linked lists
*/

#include<bits/stdc++.h>
#include<iostream>
// #include<queue>
// #include<stack>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr){}
	TreeNode(int x): val(x), left(nullptr), right(nullptr){}
	TreeNode(int x, TreeNode *leftptr, TreeNode *rightptr): val(x), left(leftptr), right(rightptr){}
};

struct LinkedList{
	int val;
	LinkedList* next;
	LinkedList(): val(0), next(nullptr){}
	LinkedList(int x): val(x), next(nullptr){}
	LinkedList(int x, LinkedList* nextptr): val(0), next(nextptr){}
};

// Given a vector, create a Tree
TreeNode* createBST(std::vector<int>& arr, int start, int end){
    if (end < start) return NULL;
    
    int mid = start + (end-start)/2;
    
    TreeNode* n = new TreeNode(arr[mid]);
    n->left = createBST(arr, start, mid-1);
    n->right = createBST(arr, mid+1, end);
    return n;
}

// Given a vector, create a linked list and return its head;
LinkedList* createLinkedList(std::vector<int> array){

	LinkedList* head = new LinkedList(array[0]);
	LinkedList* dummy = head;

	for (int i=0; i < array.size()-1; i++){
		dummy->next = new LinkedList(-1);
		dummy = dummy->next;
		dummy->val = array[i+1];
	}

	return head;
}

// Create a vector of linkedlists from 2d arrays
std::vector<LinkedList*> createMultipleLL(std::vector<std::vector<int>> result){
	std::vector<LinkedList*> resultLL;

	for (auto vec:result){
		LinkedList* head = createLinkedList(vec);
		resultLL.push_back(head);
	}
	return resultLL;
}

// Display multiple linked lists, input a vector of linked lists
void displayMultipleLL(std::vector<LinkedList*> vectorLL){

	for (auto ll:vectorLL){
		auto head = ll;
		while (head){
			std::cout << head->val << " " << std::endl;
			head = head->next;
		}
		std::cout << std::endl;
	}
}



// Perform Level Order Traversal
std::vector<std::vector<int>> LevelOrderTraversal(TreeNode* root){
	// Return a 2d vector with level order traversal array

	std::vector<std::vector<int>> allLevels;

	std::queue<TreeNode*> toBeVisited;
	toBeVisited.push(root);


	while (!toBeVisited.empty()){
		int levelSize = toBeVisited.size();

		std::vector<int> eachLevel;

		while (levelSize--){
			TreeNode* currentNode = toBeVisited.front(); toBeVisited.pop();

			eachLevel.push_back(currentNode->val);
			if (currentNode->left) toBeVisited.push(currentNode->left);
			if (currentNode->right) toBeVisited.push(currentNode->right);
		}
		allLevels.push_back(eachLevel);
	}

	return allLevels;
}

// Helper Functions
void display2D(std::vector<std::vector<int>> input){

	for (auto vec:input){
		for (auto num:vec){
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}
}

int main(){

	// Generate Input
	std::vector<int> inputArray{1,2,3,4,5,6};
	TreeNode* root = createBST(inputArray, 0, inputArray.size()-1); // Create a Tree


	std::vector<std::vector<int>> result = LevelOrderTraversal(root); // Perform Level Order Traversal

	// Create a linked list from 2d vector
	// display2D(result);
	std::vector<LinkedList*> resultLL = createMultipleLL(result);
	

	// Display the Linked List
	displayMultipleLL(resultLL);



	// Store each level into a queue. Convert each level to a linked list. Use BFS


	return 0;
}