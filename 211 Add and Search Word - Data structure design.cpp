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

class WordDictionary {
private:
    TrieNode* root;
    
public:
    
    WordDictionary(){
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* node = root;
        int index = 0;
        while (index < word.length()) {
            char c = word[index];
            TrieNode** nodePtr = &(node->childs[c-'a']);
            
            if (!(*nodePtr)) {
                *nodePtr = new TrieNode();
            }
            node = *nodePtr;
            index++;
        }
        node->isWord = true;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchFromNode(word.c_str(), root);
    }
    
private:
    
    bool searchFromNode(const char* word, TrieNode* node){
        int index = 0;
        while (word[index]) {
            if (word[index] == '.') {
                for (int i = 0; i < 26; i++) {
                    TrieNode* newNode = node->childs[i];
                    if (newNode && searchFromNode(word+index+1, newNode)) {
                        return true;
                    }
                }
                return false;
            }
            else{
                node = node->childs[word[index]-'a'];
                if (!node) {
                    return false;
                }
                index++;
            }
        }
        
        if (node->isWord) {
            return true;
        }
        
        return false;
    }
    
};

int main()
{
    WordDictionary dic;
    dic.addWord("abc");
    bool res = dic.search("a.c");
    return 1;
}
