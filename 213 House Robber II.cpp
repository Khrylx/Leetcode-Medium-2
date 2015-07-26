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

int rob(vector<int>& nums)
{
    int N = (int)nums.size();
    vector<int> nums2(N);
    if (N == 0) {
        return 0;
    }
    if (N == 1) {
        return nums[0];
    }
    if (N == 2) {
        return max(nums[0],nums[1]);
    }
    
    nums2[1] = nums[1];
    nums2[2] = max(nums[1],nums[2]);
    nums[1] = max(nums[0],nums[1]);
    
    for (int i = 2; i < N; i++) {
        if (i > 2) {
            nums2[i] = max(nums2[i-2]+nums[i],nums2[i-1]);
        }
        if (i < N-1) {
            nums[i] = max(nums[i-2]+nums[i],nums[i-1]);
        }
    }
    
    return max(nums[N-2],nums2[N-1]);
}

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N);
    
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    int res = rob(nums);
    
    return 1;
}
