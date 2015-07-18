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
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode*> S;

public:
    BSTIterator(TreeNode *root) {
        if (!root)
            return;
        
        S.push(root);
        while (root->left) {
            root = root->left;
            S.push(root);
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !S.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* node = S.top();
        int res = node->val;
        S.pop();
        
        if (node->right) {
            node = node->right;
            S.push(node);
            while (node->left) {
                node = node->left;
                S.push(node);
            }
        }
        
        return res;
    }
};


int main(){
    
    return 1;
}
