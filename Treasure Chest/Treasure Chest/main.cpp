//
//  main2.cpp
//  Treasure Chest
//
//  Created by Daniel Bessonov on 6/24/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int N, cost[5001], temp;

bool check()
{
    int x = cost[0];
    for(int i = 1; i < N; i++)
    {
        if(cost[i] != x)
        {
            return false;
        }
    }
    return true;
}

int helperMax(int a, int b)
{
    return max(a, b);
}

int f()
{
    int dp[N+1][N+1];
    for(int i = N - 1; i >= 0; i--)
    {
        for(int j = i; j < N; j++)
        {
            if (i == j)
            {
                dp[i][j] = cost[i];
            }
            else if(check())
            {
                int z = (N+1) / 2;
                return (cost[0] * z);
            }
            else if(i + 1 == j)
            {
                dp[i][j] = max(cost[i], cost[j]);
                //cout << "BRU";
            }
            else
            {
                temp = dp[i+1][j-1];
                int x = cost[i] + min(dp[i+2][j], temp);
                int y = cost[j] + min(dp[i][j-2], temp);
                dp[i][j] = helperMax(x, y);
            }
        }
    }
    return dp[0][N-1];
    
}
int main()
{
    freopen("treasure.in", "r", stdin);
    freopen("treasure.out", "w", stdout);
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> cost[i];
    }
    cout << f() << endl;
    return 0;
}