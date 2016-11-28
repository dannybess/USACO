//
//  main.cpp
//  Allow
//
//  Created by Daniel Bessonov on 6/25/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int N, C, weeks, mem;
bool possible;
vector<pair <int, int> > coins;

int main() {
    freopen("allow.in", "r", stdin);
    freopen("allow.out", "w", stdout);
    
    cin >> N >> C;
    
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        pair<int, int> c = make_pair(a, b);
        coins.push_back(c);
    }
    sort(coins.begin(), coins.end());
    possible = true;
    mem = C;
    while(possible) {
        possible = false;
        C = mem;
        for (int i = coins.size()-1; i >= 0; i--) {
            for(int j = coins[i].second; j > 0; j--) {
                if(C - coins[i].first >= 0) {
                    C -= coins[i].first;
                    coins[i].second--;
                }
            }
        }
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i].second > 0 && C > 0) {
                coins[i].second--;
                C -= coins[i].first;
                break;
            }
        }
        if (C <= 0) {
            possible = true;
        }
        if (possible) {
            weeks++;
        }
    }
    
    cout << weeks << endl;
    return 0;
}