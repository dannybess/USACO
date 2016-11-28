//
//  main.cpp
//  Making Change
//
//  Created by Daniel Bessonov on 6/23/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int C, N, coin[1001], x = 1000000000, dp[1001];

int count()
{
    dp[0] = 0;
    for(int j = 1; j <= C; j++)
    {
        dp[j] = x;
        for(int i = 0; i < N; i++)
        {
            if((j >= coin[i]) && (1 + dp[j-coin[i]]) < dp[j])
            {
                dp[j] = 1 + dp[j-coin[i]];
            }
        }
    }     
    return dp[C];
}

int main()
{
    cin >> C >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> coin[i];
    }
    cout << count()<< endl;
    
}

