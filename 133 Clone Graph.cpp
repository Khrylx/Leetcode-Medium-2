#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;



struct UndirectedGraphNode 
{
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

typedef unordered_map<int,UndirectedGraphNode*> NodeMap;
NodeMap nodeMap;

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
{
	if (!node)
		return NULL;

	NodeMap::iterator itr = nodeMap.find(node->label);
	if (itr != nodeMap.end())
	{
		return itr->second;
	}

	UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
	nodeMap[node->label] = newNode;

	for (int i = 0; i < node->neighbors.size(); i++)
	{
		newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
	}

	return newNode;
}

int main()
{
	return 1;
}