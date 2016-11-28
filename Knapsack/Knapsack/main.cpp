//
//  main.cpp
//  Knapsack
//
//  Created by Daniel Bessonov on 6/23/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int N, C;
int value[1001];
int weight[1001];
int K[1001][5001];

int knapSack(int C, int N)
{
    int x, y;
    //dynamic programming solution instead of recursive
    for (x = 0; x <= N; x++)
    {
        for (y = 0; y <= C; y++)
        {
            if (x == 0 || y == 0)
            {
                K[x][y] = 0;
            }
            else if (weight[x-1] <= y)
            {
                K[x][y] = max(value[x-1] + K[x-1][y-weight[x-1]],  K[x-1][y]);
            }
            else
            {
                K[x][y] = K[x-1][y];
            }
        }
    }
    
    return K[N][C];
}


int main() {
    //freopen("knapsack.in", "r", stdin);
    //freopen("knapsack.out", "w", stdout);
    
    cin >> N >> C;
    
    for(int i = 0; i < N; i++)
    {
        cin >> weight[i] >> value[i];
    }
    
    cout<< knapSack(C, N)<< endl;
    
    return 0;
}