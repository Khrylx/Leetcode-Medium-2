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

vector<int> productExceptSelf(vector<int>& nums)
{
    int N = (int)nums.size();
    vector<int> output(N);
    
    int res = 1;
    for (int i = 0; i < N; i++) {
        output[i] = res;
        res *= nums[i];
    }
    
    res = 1;
    for (int i = N-1; i >= 0; i--) {
        output[i] *= res;
        res *= nums[i];
    }
    
    return output;
}

int main(){
    int N;
    cin >> N;
    
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    vector<int> solutions = productExceptSelf(nums);
    
    return 1;
}
