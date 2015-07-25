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

int minSubArrayLen(int s, vector<int>& nums)
{
    int N = (int)nums.size();
    int minLen = INT_MAX;
    int bIndex = 0;
    int eIndex = 0;
    int sum = 0;
    while (1) {
        
        if (sum <= s) {
            if (eIndex == N) {
                break;
            }
            sum += nums[eIndex++];
        }
        else{
            sum -= nums[bIndex++];
        }
        
        if (sum >= s) {
            minLen = min(minLen,eIndex-bIndex);
        }
    }
    
    if (minLen == INT_MAX) {
        return 0;
    }
    
    return minLen;
}

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    int res = minSubArrayLen(11, nums);
    return 1;
}
