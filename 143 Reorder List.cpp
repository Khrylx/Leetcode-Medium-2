#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head) 
{
	if (!head || !head->next)
		return;

	vector<ListNode*> nodeVec;

	ListNode* cur = head;
	while (cur)
	{
		nodeVec.push_back(cur);
		cur = cur->next;
	}

	int N = nodeVec.size();
	for (int i = 0; i < N/2; i++)
	{
		nodeVec[i]->next = nodeVec[N-1-i];
		nodeVec[N-1-i]->next = nodeVec[i+1];
	}

	nodeVec[N/2]->next = NULL;
}

int main()
{
	
	return 1;
}