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

vector<string> findRepeatedDnaSequences(string s)
{
    vector<string> solutions;
    if (s.length() <= 10) {
        return solutions;
    }
    
    const int mask = 0x000FFFFF;
    unordered_set<int> S;
    unordered_set<int> dS;
    int mark = 0;
    for (int i = 0; i < s.length(); i++) {
        int p = 0;
        switch (s[i]) {
            case 'C':
                p = 1;
                break;
            case 'G':
                p = 2;
                break;
            case 'T':
                p = 3;
                break;
        }
        mark = (mark << 2 & mask ) | p;
        
        if (i >= 9) {
            if (S.count(mark)) {
                if (!dS.count(mark)) {
                    solutions.push_back(s.substr(i-9,10));
                    dS.insert(mark);
                }
            }
            else{
                S.insert(mark);
            }
        }
    }
    
    return solutions;
}

int main(){
    vector<string> solutions = findRepeatedDnaSequences("AAAAAAAAAAAA");
    return 1;
}
