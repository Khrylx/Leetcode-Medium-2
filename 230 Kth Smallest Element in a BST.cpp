//
//  main.cpp
//  Leetcode
//
//  Created by Eric on 15/5/14.
//  Copyright (c) 2015年 Eric. All rights reserved.
//

#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <list>

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
    
    cout << root->val << " ";
    
    if (root->right) {
        inorderPrint(root->right);
    }
    
    
    
}

int kthSmallest(TreeNode* root, int k)
{
    if (!root) {
        return -1;
    }
    
    stack<TreeNode*> S;
    TreeNode* node = root;
    S.push(node);
    while (node->left) {
        node = node->left;
        S.push(node);
    }
    
    
    while (!S.empty()) {
        node = S.top();
        S.pop();
        
        if (--k == 0) {
            return node->val;
        }
        if (node->right) {
            node = node->right;
            S.push(node);
            while (node->left) {
                node = node->left;
                S.push(node);
            }
        }
    }
    
    return -1;
}


int main(){
    
    TreeNode* root = initTreeRoot(1);
    TreeNode* n1 = addLeftChild(root, 2);
    TreeNode* n2 = addRightChild(root, 3);
    TreeNode* n3 = addLeftChild(n1, 4);
    TreeNode* n4 = addRightChild(n1, 5);
    TreeNode* n5 = addLeftChild(n2, 8);
    TreeNode* n6 = addRightChild(n4, 7);
    
    inorderPrint(root);
    cout << endl;
    
    destroyTree(root);
    return 1;
}
