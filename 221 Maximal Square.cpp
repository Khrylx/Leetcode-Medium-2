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

int maximalSquare(vector<vector<char>>& matrix)
{
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return 0;
    }
    
    int N = (int)matrix.size();
    int M = (int)matrix[0].size();
    int res = 0;
    
    vector<vector<int>> A(N,vector<int>(M,0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = matrix[i][j] - '0';
            if (i && j && A[i][j] ) {
                A[i][j] = min(A[i-1][j-1],min(A[i-1][j],A[i][j-1]))+1;
            }
            res = max(res, A[i][j]);
        }
    }
    
    return res*res;
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
    
    
    return 1;
}
