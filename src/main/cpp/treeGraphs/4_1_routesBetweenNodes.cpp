
/*
	Given a directed graph, design an algorithm to find out whether there is a route between
	two nodes.
*/

#include<bits/stdc++.h>
#include<iostream>

std::vector<std::vector<int>> allRoutes;
std::vector<int> singleRoute;


void display2D(std::vector<std::vector<int>> input){
	if (input.size()) std::cout << "Yes, " << input.size() << " Path exists: " << std::endl;

	for (auto vec:input){
		for (auto num:vec){
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}
}

void dfs(std::vector<std::vector<int>>& graph, int sourceNode, int targetNode){
	// DFS with BackTracking
	singleRoute.push_back(sourceNode);

	if (sourceNode == targetNode) allRoutes.push_back(singleRoute);
	else for (auto child:graph[sourceNode]){
			dfs(graph, child, targetNode);
		}

	singleRoute.pop_back();
}

std::vector<std::vector<int>> isThereApath(std::vector<std::vector<int>>& graph, int sourceNode, int targetNode){
	// Returns all paths from source to target

	dfs(graph, sourceNode, targetNode);

	return allRoutes;
}

int main(){

	std::vector<std::vector<int>> graph{{1,2},{3},{3},{}};
	std::vector<std::vector<int>> result = isThereApath(graph, 0, 3);

	// Display a 2d vector
	display2D(result);

	return 0;
}