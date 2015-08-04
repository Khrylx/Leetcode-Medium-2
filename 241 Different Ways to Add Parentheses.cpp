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

void computeWithDP(string& input, unordered_map<string, vector<int>>& dpMap)
{
    vector<int> res;
    
    for (int i = 0; i < input.length(); i++) {
        char cur = input[i];
        
        if (cur == '+' || cur == '-' || cur == '*') {
            string A = input.substr(0,i);
            string B = input.substr(i+1);
            unordered_map<string, vector<int>>::iterator itr = dpMap.find(A);
            if (itr == dpMap.end()) {
                computeWithDP(A, dpMap);
            }
            itr = dpMap.find(B);
            if (itr == dpMap.end()) {
                computeWithDP(B, dpMap);
            }
            
            vector<int>& vecA = dpMap[A];
            vector<int>& vecB = dpMap[B];
            for (int i = 0; i < vecA.size(); i++) {
                for (int j = 0; j < vecB.size(); j++) {
                    switch (cur) {
                        case '+':
                            res.push_back(vecA[i] + vecB[j]);
                            break;
                        case '-':
                            res.push_back(vecA[i] - vecB[j]);
                            break;
                        case '*':
                            res.push_back(vecA[i] * vecB[j]);
                            break;
                    }
                }
            }
        }
    }
    
    if (res.empty()) {
        res.push_back(atoi(input.c_str()));
    }
    dpMap[input] = res;
}

vector<int> diffWaysToCompute(string input)
{
    unordered_map<string, vector<int>> dpMap;
    
    computeWithDP(input, dpMap);
    
    return dpMap[input];
}

int main(){
    
    vector<int> solutions = diffWaysToCompute("2*3-4*5");
    return 1;
}
