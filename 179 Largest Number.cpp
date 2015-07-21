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

bool myCompare(const string &A,const string &B)
{
    if (A.size() == B.size()) {
        return A > B;
    }
    
    int p1 = 0;
    int p2 = 0;
    
    while (p1 < A.size() && p2 < B.size()) {
        if (A[p1] != B[p2]) {
            return A[p1] > B[p2];
        }
        p1++;
        p2++;
    }
    
    if (p1 == A.size()) {
        return myCompare(A, B.substr(p2));
    }
    else{
        return myCompare(A.substr(p1), B);
    }
}

string largestNumber(vector<int>& nums)
{
    int N = (int)nums.size();
    vector<string> numStrings;
    
    for (int i = 0; i < N; i++) {
        numStrings.push_back(to_string(nums[i]));
    }
    
    if (N == 1) {
        return numStrings[0];
    }
    
    sort(numStrings.begin(), numStrings.end(), myCompare);
    
    string res;
    bool flag = false;
    for (int i = 0; i < numStrings.size(); i++) {
        if (numStrings[i] == "0" && !flag)
            continue;
        
        flag = true;
        res += numStrings[i];
    }
    if (!flag) {
        return "0";
    }
    
    return res;
}

int main(){
    int N;
    cin >> N;
    vector<int> nums(N);
    
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    string s = largestNumber(nums);
    
    return 1;
}
