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

bool pFind;
bool qFind;
TreeNode* LCA;

void helper(TreeNode* root, TreeNode* p, TreeNode* q)
{
    
    if(root == p){
        pFind = true;
        if (!LCA) {
            LCA = root;
        }
    }
    if(root == q){
        qFind = true;
        if (!LCA) {
            LCA = root;
        }
    }

    
    if (root->left && !(pFind && qFind))
        helper(root->left, p, q);
    
    
    if (!LCA && !(pFind && qFind) && (pFind || qFind)) {
        LCA = root;
    }
    
    
    if (root->right && !(pFind && qFind))
        helper(root->right, p, q);
    
    if (LCA == root && !(pFind && qFind)) {
        LCA = NULL;
    }
    
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    pFind = false;
    qFind = false;
    LCA = NULL;
    
    helper(root, p, q);
    
    return LCA;
}

int main(){
    TreeNode* root = initTreeRoot(-1);
    TreeNode* n1 = addLeftChild(root, 0);
    TreeNode* n2 = addRightChild(root, 3);
    TreeNode* n3 = addLeftChild(n1, -2);
    TreeNode* n4 = addRightChild(n1, 4);
    TreeNode* n5 = addLeftChild(n3, 8);

    n1 = lowestCommonAncestor(root, n4, n5);
    
    destroyTree(root);
    return 1;
}
