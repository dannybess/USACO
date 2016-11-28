//
//  main.cpp
//  Knapsack
//
//  Created by Daniel Bessonov on 6/23/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//
using namespace std;

#include <iostream>
#include <cmath>

int N, C, s[5001], v[5001];

int knapsack(int T, int N)
{
    if(N == 0)
    {
        return 0;
    }
    if(s[N] > T){
        return knapsack(T, N-1);
    }
    else{
        return max(knapsack(T, N-1), knapsack(T-s[N], N-1) + v[N]);
    }
}



int main() {
    //freopen("knapsack.in", "r", stdin);
    //freopen("knapsack.out", "w", stdout);
    
    cin >> N >> C;
    for(int i = 0; i < N; i++)
    {
        cin >> s[i] >> v[i];
    }
    
    cout << knapsack(N, C) << endl;
    
    return 0;
}