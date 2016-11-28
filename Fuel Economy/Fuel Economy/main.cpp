//
//  main.cpp
//  Fuel Economy
//
//  Created by Daniel Bessonov on 6/25/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, G, B, D, curx, curgas, next_[50000], s[50000];
long long cost;
struct station {
    int x, price;
}stations[50000];

bool comp(station a, station b) {
    return a.x < b.x;
}

int main() {
    freopen("fuel.in", "r", stdin);
    freopen("fuel.out", "w", stdout);
    
    cin >> N >> G >> B >> D;
    
    for(int i = 0; i < N; i++) {
        cin >> stations[i].x >> stations[i].price;
    }
    //which gas station is closest
    sort(stations, stations+N, comp);
    int len = 0;
    for (int i = N-1; i >= 0; i--) {
        //here, we are trying to see if it possible to reach a gas station
        while(len > 0 && stations[s[len-1]].price >= stations[i].price) {
            len--;
        }
        if(len == 0) {
            next_[i] = -1;
        }
        else {
            next_[i] = s[len-1];
        }
        s[len] = i;
        len++;
    }
    curgas = B;
    curgas -= stations[0].x;
    for(int i = 0; i < N; i++) {
        int q;
        if(curgas < 0) {
            cout << "-1" << endl;
            return 0;
        }
        if(next_[i] == -1) {
            q = D;
        }
        else {
            q = stations[next_[i]].x - stations[i].x;
        }
        int amt = min(G, q);
        if(amt > curgas) {
            cost += (amt - curgas) * stations[i].price;
            curgas = amt;
        }
        if(i == N-1) {
            curgas -= D - stations[i].x;
        }
        else {
            curgas += stations[i+1].x - stations[i].x;
        }
    }


    cout << cost << endl;

    return 0;
}


