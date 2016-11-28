//
//  main.cpp
//  Hay for Sale
//
//  Created by Daniel Bessonov on 6/23/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

bool possible[50001];
int C, H, bales[5001];
int main() {
    freopen("hay4sale.in", "r", stdin);
    freopen("hay4sale.out", "w", stdout);
    
    cin >> C >> H;
    possible[0] = true;
    for(int i = 0; i < H; i++) {
        cin >> bales[i];
        possible[bales[i]] = true;
    }
    for(int i = 0; i < C; i++) {
        if(possible[i]) {
            for(int j = 0; j < H; j++) {
                if(i+bales[j] <= C) {
                    possible[i+bales[j]] = true;
                }
            }
        }
    }
    for(int i = C; i > 0; i--) {
        if(possible[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}