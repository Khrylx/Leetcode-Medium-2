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

int countDigitOne(int n)
{
    int res = 0;
    int radius = 1;
    
    while (1) {
        int bigEnd = n / radius;
        int digit = bigEnd % 10;
        if (digit > 1) {
            res += (bigEnd / 10 + 1) * radius;
        }
        else if (digit == 1){
            res += bigEnd / 10 * radius + n % radius + 1;
        }
        else{
            res += bigEnd / 10 * radius;
        }
        if(radius > n / 10)
            break;
        radius *= 10;
    }
    return res;
}

int main(){
    
    int res = countDigitOne(1410065408);
    return 1;
}
