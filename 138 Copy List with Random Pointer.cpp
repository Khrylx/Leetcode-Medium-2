#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

typedef unordered_map<RandomListNode*,int> ListNodeMap;

RandomListNode *copyRandomList(RandomListNode *head) {
	if (head == NULL)
		return head;

	ListNodeMap listNodeMap;
	vector<int> nodeMap;

	int index = 0;
	RandomListNode* cur = head;
	while (cur)
	{
		listNodeMap.insert(pair<RandomListNode*,int>(cur,index));
		index++;
		cur = cur->next;
	}

	cur = head;
	while (cur)
	{
		if (!cur->random)
			nodeMap.push_back(-1);
		else
			nodeMap.push_back(listNodeMap[cur->random]);

		cur = cur->next;
	}

	RandomListNode* newHead = new RandomListNode(head->label);
	RandomListNode* tail = newHead;

	vector<RandomListNode*> nodeVec;
	nodeVec.push_back(newHead);
	cur = head->next;
	while (cur)
	{
		RandomListNode* node = new RandomListNode(cur->label);
		nodeVec.push_back(node);
		tail->next = node;
		tail = node;
		cur = cur->next;
	}

	index = 0;
	cur = newHead;
	while (cur)
	{
		int randIndex = nodeMap[index];
		if (randIndex != -1)
		{
			cur->random = nodeVec[randIndex];
		}
		index++;
		cur = cur->next;
	}

	return newHead;
}

int main()
{

	return 1;
}