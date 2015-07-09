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

ListNode* sortList(ListNode* head) 
{
	if (!head || !head->next)
	{
		return head;
	}

	if (!head->next->next)
	{
		if (head->val > head->next->val)
		{
			ListNode* newHead = head->next;
			newHead->next = head;
			head->next = NULL;
			return newHead;
		}

		return head;
	}

	bool flag = false;
	ListNode* cur = head->next;
	ListNode* mid = head;

	while (cur)
	{
		if (flag)
		{
			mid = mid->next;
		}
		flag = !flag;
		cur = cur->next;
	}

	ListNode* tmp = mid;
	mid = mid->next;
	tmp->next = NULL;

	ListNode* L1 = sortList(head);
	ListNode* L2 = sortList(mid);
	ListNode* tail = NULL;


	while (L1 && L2)
	{
		if (L1->val <= L2->val)
		{
			if (!tail)
				head = L1;
			else
				tail->next = L1;
			tail = L1;
			L1 = L1->next;
		}
		else
		{
			if (!tail)
				head = L2;
			else
				tail->next = L2;
			tail = L2;
			L2 = L2->next;
		}
	}

	tail->next = L1 ? L1:L2;

	return head;

}

int main()
{
	ListNode* L = createList();
	L = sortList(L);
	printList(L);
	destroyList(L);
	return 1;
}