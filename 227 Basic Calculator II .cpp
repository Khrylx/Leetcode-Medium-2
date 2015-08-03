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

int calculate(string s) {
    stack<int> S1;  // store operands;
    stack<char> S2;  // store operators;
    s += "!";
    
    int num = 0;
    bool digit = false;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == ' ') {
            continue;
        }
        
        if (c >= '0' && c <= '9') {
            num = num*10 + c-'0';
            digit = true;
            continue;
        }
        else if(digit){
            S1.push(num);
            num = 0;
            digit = false;
        }
        
        if (c == '+' || c == '-' || c == '!') {
            while (!S2.empty()) {
                char op = S2.top();
                
                S2.pop();
                int A = S1.top();
                S1.pop();
                int B = S1.top();
                S1.pop();
                if (op == '+') {
                    S1.push(A+B);
                }
                else if (op == '-'){
                    S1.push(B-A);
                }
                else if (op == '*'){
                    S1.push(A*B);
                }
                else {
                    S1.push(B/A);
                }

            }
            S2.push(c);
        }
        else {
            while (!S2.empty()) {
                char op = S2.top();
                if (op == '+' || op == '-') {
                    break;
                }

                S2.pop();
                int A = S1.top();
                S1.pop();
                int B = S1.top();
                S1.pop();
                if (op == '*') {
                    S1.push(A*B);
                }
                else{
                    S1.push(B/A);
                }
            }
            S2.push(c);
        }
    }
    
    return S1.top();
}

int main()
{
    int res = calculate("3+2*2");
    return 1;
}