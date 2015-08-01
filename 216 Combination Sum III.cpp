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

void helper(int k, int n, int cur, vector<int>& tmpSol, vector<vector<int>>& solutions)
{
    if (k == 0 && n == 0) {
        solutions.push_back(tmpSol);
        return;
    }
    
    if (k > 10-cur || n < (cur+(k-1)/2)*k || n > (9-(k-1)/2)*k) {
        return;
    }
    
    
    for (int i = cur; i < 10; i++) {
        tmpSol.push_back(i);
        helper(k-1, n-i, i+1, tmpSol,solutions);
        tmpSol.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> solutions;
    vector<int> tmpSol;
    
    helper(k, n, 1, tmpSol, solutions);
    
    return solutions;
}

int main()
{
//    int N;
//    cin >> N;
//    vector<int> nums(N);
//    
//    for (int i = 0; i < N; i++) {
//        cin >> nums[i];
//    }
    
    vector<vector<int>> solutions = combinationSum3(3, 9);
    
    return 1;
}
