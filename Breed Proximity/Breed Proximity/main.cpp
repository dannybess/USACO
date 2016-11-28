//
//  main.cpp
//  Breed Proximity
//
//  Created by Daniel Bessonov on 6/24/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int window[1000000], num;
int N, K, cows[50000], ans;

int main() {
    freopen("proximity.in", "r", stdin);
    freopen("proximity.out", "w", stdout);
    
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    for(int i = 0; i < N; i++) {
        num++;
        window[cows[i]]++;
        if(window[cows[i]] > 1) {
            if(ans < cows[i]) {
                ans = cows[i];
            }
        }
        if(num>K) {
            window[cows[i-K]]--;
            num--;
        }
    }
    cout << ans << endl;
    return 0;
}
