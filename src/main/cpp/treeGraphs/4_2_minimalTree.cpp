/*
	Given a sorted array with unique integer elements, write an algorithm to create a binary tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include<bits/stdc++.h>
#include<iostream>

using namespace std;

struct TreeNode {
 	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createBST(vector<int>& arr, int start, int end){
    if (end < start) return NULL;
    
    int mid = start + (end-start)/2;
    
    TreeNode* n = new TreeNode(arr[mid]);
    n->left = createBST(arr, start, mid-1);
    n->right = createBST(arr, mid+1, end);
    return n;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (!nums.size()) return NULL;
    return createBST(nums, 0, nums.size()-1);   
}

int main(){
	return 0;
}