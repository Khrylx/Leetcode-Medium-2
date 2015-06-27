#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* initTreeRoot(int val)
{
	return new TreeNode(val);
}

TreeNode* addLeftChild(TreeNode* node, int val)
{
	TreeNode* lChild = new TreeNode(val);
	node->left = lChild;
	return lChild;
}

TreeNode* addRightChild(TreeNode* node, int val)
{
	TreeNode* rChild = new TreeNode(val);
	node->right = rChild;
	return rChild;
}

void destroyTree(TreeNode* root)
{
	if (root->left) {
		destroyTree(root->left);
	}
	if (root->right) {
		destroyTree(root->right);
	}

	delete root;

}

void inorderPrint(TreeNode* root)
{
	if (root->left) {
		inorderPrint(root->left);
	}

	cout << root->val <<" ";

	if (root->right) {
		inorderPrint(root->right);
	}
}

void sumNumbersHelper(TreeNode* root, int& sum, int& curSum)
{
	curSum = curSum*10 + root->val;

	if (!root->left && !root->right)
	{
		sum += curSum;
	}
	
	if (root->left)
	{
		sumNumbersHelper(root->left,sum,curSum);
	}
	if (root->right)
	{
		sumNumbersHelper(root->right,sum,curSum);
	}
	
	curSum /= 10;
}

int sumNumbers(TreeNode* root) 
{
	if (!root)
	{
		return 0;
	}

	int curSum = 0;
	int sum = 0;

	sumNumbersHelper(root,sum,curSum);

	return sum;
}

int main()
{
	TreeNode* root = initTreeRoot(1);
	TreeNode* n1 = addLeftChild(root, 2);
	TreeNode* n2 = addRightChild(root, 3);
	/*TreeNode* n3 = addLeftChild(n1, 4);
	TreeNode* n4 = addRightChild(n1, 5);
	TreeNode* n5 = addLeftChild(n2, 8);
	TreeNode* n6 = addRightChild(n4, 7);*/

	cout << sumNumbers(root) <<endl;

	destroyTree(root);

	return 1;
}