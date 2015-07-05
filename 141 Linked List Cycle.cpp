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

bool hasCycle(ListNode *head) 
{
	if (!head || !head->next)
	{
		return false;
	}
	ListNode* p1 = head;
	ListNode* p2 = head->next;

	while (p2)
	{
		if (p1 == p2)
		{
			return true;
		}
		p1 = p1->next;
		p2 = p2->next;
		if (!p2)
			return false;
		p2 = p2->next;
	}

	return false;
}

int main()
{
	
	return 1;
}