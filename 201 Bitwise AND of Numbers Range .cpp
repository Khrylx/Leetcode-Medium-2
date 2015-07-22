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


int rangeBitwiseAnd(int m, int n)
{
    int d = abs(m-n);
    int mask = 1;
    int bitMask = 0xFFFFFFFF;
    while (mask < d) {
        if (mask >= 0x40000000 )
            return 0;

        mask = mask << 1;
        bitMask = bitMask << 1;
    }
    
    return m & n & bitMask;
}

int main()
{
    int N,M;
   
    int res = rangeBitwiseAnd(2, 2);
    return 1;
}
