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

void reverseVec(vector<int>& nums, int start, int end)
{
    while (start < end) {
        swap(nums[start++],nums[end--]);
    }
}

void rotate(vector<int>& nums, int k)
{
    int N = (int)nums.size();
    
    k %= N;
    
    reverseVec(nums, 0, N-k-1);
    reverseVec(nums, N-k, N-1);
    reverseVec(nums, 0, N-1);
}

int main(){
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    rotate(nums, 3);
    
    return 1;
}
