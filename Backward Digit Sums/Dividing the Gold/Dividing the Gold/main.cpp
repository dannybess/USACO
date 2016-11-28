//
//  main.cpp
//  Dividing the Gold
//
//  Created by Daniel Bessonov on 6/23/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//
#include <iostream>
#include <cstdio>

using namespace std;

int N, coins[251], duplicate[251], totalsum;
int possible[250001];
bool dp[250001];

int main() {
    freopen("divgold.in", "r", stdin);
    freopen("divgold.out", "w", stdout);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> coins[i];
        totalsum += coins[i];
    }
    possible[0]++;
    dp[0] = true;
    for(int i = 0; i < N; i++) {
        for(int j = totalsum / 2; j >= coins[i]; j--) {
            possible[j] += possible[j-coins[i]];
            possible[j] %= 1000000;
            if(dp[j-coins[i]])  {
                dp[j] = true;
            }
        }
    }
    for(int i = totalsum/2; i > 0; i--) {
        if(possible[i] > 0) {
            cout << totalsum-2*i << endl << possible[i] << endl;
            break;
        }
    }
    return 0;
}
