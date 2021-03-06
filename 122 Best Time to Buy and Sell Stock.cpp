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

int maxProfit(vector<int>& prices)
{
    if (prices.size() <= 1) {
        return 0;
    }
    
    int low = prices[0];
    
    int maxP = 0;
    
    for (int i = 1; i < (int)prices.size(); i++) {
        if (prices[i] < prices[i-1]) {
            if (prices[i-1] > low) {
                maxP += prices[i-1]-low;
            }
            low = prices[i];
        }
    }
    
    if (prices.back() > low) {
        maxP += prices.back()-low;
    }
    
    return maxP;
}

int main(){
    
    int N;
    cin >> N;
    
    vector<int> prices(N);
    
    for (int i = 0; i < N; i++) {
        cin >> prices[i];
    }
    
    cout << maxProfit(prices) <<endl;
    
    return 1;
}
