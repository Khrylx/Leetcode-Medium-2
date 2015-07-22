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

int rob(vector<int>& nums)
{
    int N = (int)nums.size();
    if (N == 0) {
        return 0;
    }
    if (N == 1) {
        return nums[0];
    }
    
    nums[1] = max(nums[0],nums[1]);
    
    for (int i = 2; i < N; i++) {
        nums[i] = max(nums[i]+nums[i-2],nums[i-1]);
    }
    
    return nums.back();
}

int main(){

    
    return 1;
}
