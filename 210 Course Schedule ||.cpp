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

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
{
    vector<vector<int>> Pre(numCourses);
    vector<int> Nums(numCourses,0);
    vector<int> solutions;
    
    for (int i = 0; i < prerequisites.size(); i++) {
        Pre[prerequisites[i].second].push_back(prerequisites[i].first);
        Nums[prerequisites[i].first]++;
    }
    
    queue<int> Q;
    
    for (int i = 0; i < numCourses; i++) {
        if (Nums[i] == 0) {
            Q.push(i);
        }
    }
    
    while (!Q.empty()) {
        int cIndex = Q.front();
        Q.pop();
        solutions.push_back(cIndex);

        for (int i = 0; i < Pre[cIndex].size(); i++) {
            if (--Nums[Pre[cIndex][i]] == 0)
                Q.push(Pre[cIndex][i]);
        }
    }
    
    if (solutions.size() == numCourses) {
        return solutions;
    }
    
    return vector<int>();
}

int main()
{
    vector<pair<int, int>> prerequisites;
    prerequisites.push_back(pair<int,int>(1,0));
    //prerequisites.push_back(pair<int,int>(0,1));
    vector<int> res = findOrder(2, prerequisites);
    return 1;
}
