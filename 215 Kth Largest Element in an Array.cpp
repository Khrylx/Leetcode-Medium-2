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

int findK(vector<int>& nums, int lb, int ub, int k)
{
    int pivot = nums[lb];
    int cur = lb+1;
    int tail = cur;
    
    while (cur <= ub) {
        if (nums[cur] < pivot) {
            swap(nums[cur], nums[tail++]);
        }
        cur++;
    }
    swap(nums[tail-1], nums[lb]);
    
    int len = tail-lb;
    if (len == k) {
        return pivot;
    }
    else if (len > k){
        return findK(nums, lb, tail-2, k);
    }
    else{
        return findK(nums, tail, ub, k-len);
    }
}

int findKthLargest(vector<int>& nums, int k)
{
    int n = (int)nums.size();
    return findK(nums, 0, n-1, n-k+1);
}


int main()
{
    int N;
    cin >> N;
    vector<int> nums(N);
    
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    int res = findKthLargest(nums, 7);
    
    return 1;
}
