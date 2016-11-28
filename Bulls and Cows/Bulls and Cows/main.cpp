//
//  main.cpp
//  Bulls and Cows
//
//  Created by Daniel Bessonov on 6/22/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;


int N, K;
int combinations[100000];
int visited[100000];

//use DP and reccurence relationship

void compute()
{
    memset(combinations, -1, sizeof(combinations));
    
    for(int i = 0; i <= N; i++)
    {
        if(i <= K)
        {
            if(!visited[i])
            {
                combinations[i] = i + 1;
                visited[i] = true;
            }
        }
        else
        {
            if(!visited[i])
            {
                combinations[i] = (combinations[i - 1] + combinations[i - K - 1]) % 5000011;
                visited[i] = true;
            }
        }
    }
    
}



int main()
{
    
    freopen("bullcow.in", "r", stdin);
    freopen("bullcow.out", "w", stdout);
    
    cin >> N >> K;

    compute();
    
    cout << combinations[N] << endl;
    
    return 0;

}
