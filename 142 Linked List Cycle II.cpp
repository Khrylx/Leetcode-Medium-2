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

ListNode *detectCycle(ListNode *head) 
{
	if (!head || !head->next)
	{
		return false;
	}

	ListNode* p1 = head;
	ListNode* p2 = head->next;

	while (1)
	{
		if (p1 == p2)
			break;

		p1 = p1->next;
		p2 = p2->next;

		if (!p2)
			return NULL;
		p2 = p2->next;
		if (!p2)
			return NULL;
	}

	while (1)
	{
		ListNode* tmp = p2;
		p2 = p2->next;
		tmp->next = NULL;
		if (p2 == p1)
			break;
	}

	p1 = head;
	while (p1->next)
	{
		p1 = p1->next;
	}

	return p1;
}

int main()
{
	
	return 1;
}