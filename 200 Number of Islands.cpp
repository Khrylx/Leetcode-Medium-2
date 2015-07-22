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


int numIslands(vector<vector<char>>& grid)
{
    int N = (int)grid.size();
    if (N == 0)
        return 0;
    int M = (int)grid[0].size();
    if (M == 0)
        return 0;
    
    int id = '1';
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] != '1') {
                continue;
            }
            
            id++;
            stack<pair<int, int>> S;
            S.push(pair<int, int>(i,j));
            
            while (!S.empty()) {
                pair<int, int> p = S.top();
                S.pop();
                
                int x = p.first;
                int y = p.second;
                int lx = x-1;
                int ux = x+1;
                grid[x][y] = id;
                
                while (lx >= 0 && grid[lx][y] == '1') {
                    grid[lx--][y] = id;
                }
                while (ux < N && grid[ux][y] == '1') {
                    grid[ux++][y] = id;
                }
                lx++;
                ux--;
                
                if (y-1 >= 0) {
                    int ny = y-1;
                    bool find = false;
                    for (int nx = lx; nx <= ux; nx++) {
                        if (grid[nx][ny] == '1') {
                            if (!find)
                                S.push(pair<int, int>(nx,ny));
                            find = true;
                        }
                        else
                            find = false;
                    }
                }
                
                if (y+1 < M) {
                    int ny = y+1;
                    bool find = false;
                    for (int nx = lx; nx <= ux; nx++) {
                        if (grid[nx][ny] == '1') {
                            if (!find)
                                S.push(pair<int, int>(nx,ny));
                            find = true;
                        }
                        else
                            find = false;
                    }
                }
            }
        }
    }
    
    return id-'1';
}


int main()
{
    int N,M;
    cin >> N >> M;
    vector<vector<char>> grid(N,vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    int res = numIslands(grid);
    
    return 1;
}
