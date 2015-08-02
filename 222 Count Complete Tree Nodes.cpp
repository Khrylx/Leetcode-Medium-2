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
    
    cout << root->val <<" ";
    
    if (root->right) {
        inorderPrint(root->right);
    }
}

int countNodes(TreeNode* root)
{
    if (!root) {
        return 0;
    }
    if (!root->left) {
        return 1;
    }
    
    int maxDepth = 1;
    TreeNode* node = root;
    while (node->left) {
        maxDepth++;
        node = node->left;
    }
    int depth = 1;
    node = root;
    while (node->right) {
        depth++;
        node = node->right;
    }
    if (depth == maxDepth) {
        return (1 << depth)-1;
    }
    
    node = root;
    int curDepth = 1;
    int index = 1;
    while (node) {
        TreeNode* tmp = node->left;
        int tmpDepth = curDepth;
        while (tmp) {
            tmpDepth++;
            tmp = tmp->right;
        }
        if (tmpDepth == maxDepth) {
            node = node->right;
            index = index*2;
        }
        else{
            node = node->left;
            index = index*2-1;
        }
        curDepth++;
    }
    index--;
    
    return (1 << (maxDepth-1))+index-1;
}

int main()
{
    TreeNode* root = initTreeRoot(1);
    TreeNode* n1 = addLeftChild(root, 2);
    TreeNode* n2 = addRightChild(root, 3);
    TreeNode* n3 = addLeftChild(n1, 4);
    TreeNode* n4 = addRightChild(n1, 5);
    TreeNode* n5 = addLeftChild(n2, 6);
    TreeNode* n6 = addRightChild(n2, 7);
    addLeftChild(n3, 8);
    addRightChild(n3, 9);
    int res = countNodes(root);
    
    destroyTree(root);
    
    return 1;
}