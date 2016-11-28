//
//  main.cpp
//  Cow Checkers
//
//  Created by Daniel Bessonov on 6/23/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>


using namespace std;

int main() {
    freopen("cowcheck.in", "r", stdin);
    freopen("cowcheck.out", "w", stdout);
    
    int M, N, T;
    cin >> M >> N >> T;
    int pos[max(M, N)];
    memset(pos, -1, sizeof(pos));
    int curx = 0;
    int cury = 0;
    pos[cury] = curx;
    while (true) {
        curx++;
        cury+=2;
        while(cury < max(M, N) && pos[curx] != -1) {
            curx++;
            cury++;
        }
        if(cury >= max(M, N)) {
            break;
        }
        pos[cury] = curx;
    }
    for(int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;
        if(a > b) {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        if(pos[b] == a) {
            cout << "Farmer John" << endl;
        }
        else cout << "Bessie" << endl;
    }
    return 0;
}
