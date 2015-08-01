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

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
    set<int> S;
    int N = (int)nums.size();
    
    for (int i = 0; i < N; i++) {
        if (i > k) {
            S.erase(nums[i-k-1]);
        }
        auto pos = S.lower_bound(nums[i]-t);
        if (pos != S.end() && *pos <= nums[i]+t) {
            return true;
        }

        S.insert(nums[i]);

        
    }
    
    return false;
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
