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

ListNode* createList()
{
	ListNode* head=NULL;
	ListNode* curL;
	int n;

	cin>>n;

	for (int i=0;i<n;i++)
	{
		int input;
		cin>>input;
		if (head==NULL)
		{
			head=new ListNode(input);
			curL=head;
		}
		else
		{
			curL->next=new ListNode(input);
			curL=curL->next;
		}
	}

	return head;
}

void printList(ListNode* head)
{
	ListNode* curL=head;

	while (curL!=NULL)
	{
		cout<<curL->val<<" ";
		curL=curL->next;
	}
	cout<<endl;
}

void destroyList(ListNode* head)
{
	ListNode* curL=head;

	while (curL!=NULL)
	{
		ListNode* tmpL=curL;
		curL=curL->next;
		delete tmpL;
	}
}

ListNode* insertionSortList(ListNode* head) 
{
	if (!head || !head->next)
	{
		return head;
	}

	ListNode* cur = head->next;
	head->next = NULL;

	while (cur)
	{
		ListNode* nextCur = cur->next;
		if (cur->val < head->val)
		{
			cur->next = head;
			head = cur;
		}
		else
		{
			ListNode* prev = head;
			while (prev->next && prev->next->val < cur->val )
			{
				prev = prev->next;
			}
			cur->next = prev->next;
			prev->next = cur;
		}
		cur = nextCur;
	}

	return head;
}

int main()
{
	ListNode* L = createList();
	L = insertionSortList(L);
	printList(L);
	destroyList(L);
	return 1;
}