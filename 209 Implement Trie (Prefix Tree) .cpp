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

using namespace std;

class TrieNode {
public:
    char val;
    bool isWord;
    TrieNode* childs[26];
    
    // Initialize your data structure here.
    TrieNode() {
        isWord = false;
        memset(childs, 0, sizeof(childs));
    }
    
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        int index = 0;
        while (index < word.length()) {
            TrieNode* newNode = node->childs[word[index]-'a'];
            if (newNode) {
                node = newNode;
                index++;
            }
            else
                break;
        }
        
        while (index < word.length()) {
            TrieNode* newNode = new TrieNode();
            node->childs[word[index++]-'a'] = newNode;
            node = newNode;
        }
        
        node->isWord = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        int index = 0;
        while (index < word.length()) {
            TrieNode* newNode = node->childs[word[index]-'a'];
            if (newNode) {
                node = newNode;
                index++;
            }
            else
                break;
        }
        
        if (index == word.length() && node->isWord) {
            return true;
        }
        
        return false;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        int index = 0;
        while (index < prefix.length()) {
            TrieNode* newNode = node->childs[prefix[index]-'a'];
            if (newNode) {
                node = newNode;
                index++;
            }
            else
                break;
        }
        
        if (index == prefix.length()) {
            return true;
        }
        
        return false;
    }
    
private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main()
{
    Trie trie;
    trie.insert("sometring");
    trie.insert("sometringqwe");
    bool res = trie.search("sometring");
    return 1;
}
