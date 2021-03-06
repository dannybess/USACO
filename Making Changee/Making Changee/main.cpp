//
//  main.cpp
//  Making Changee
//
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int C, N, coin[1001], dp[1001], x = 1000000000;

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
                dp[j] = dp[j-coin[i]] + 1;
            }
        }
    }
    return dp[C];
}


int main()
{
    freopen("change.in", "r", stdin);
    freopen("change.out", "w", stdout);
    cin >> C >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> coin[i];
    }
    cout << count()<< endl;
}

