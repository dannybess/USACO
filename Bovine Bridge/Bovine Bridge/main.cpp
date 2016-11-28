//
//  main.cpp
//  Bovine Bridge
//
//  Created by Daniel Bessonov on 6/25/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct point {
    int x, y;
}points[1000], bigones[1000000];
bool comp(point a, point b) {
    if(a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}
int N;
long long ans;

int main() {
    freopen("rotsym.in", "r", stdin);
    freopen("rotsym.out", "w", stdout);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    int k = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            if(i!=j) {
                bigones[k].x = points[i].x+points[j].x;
                bigones[k].y = points[i].y+points[j].y;
                k++;
            }
        }
    }
    sort(bigones, bigones+k, comp);
    long long counter = 1;
    for(int i = 1; i < k; i++) {
        if(bigones[i].x == bigones[i - 1].x && bigones[i].y == bigones[i - 1].y)
            counter++;
        else        {
            ans += counter * (counter - 1) / 2;
            counter = 1;
        }
    }
    cout << ans << endl;
    return 0;
}
