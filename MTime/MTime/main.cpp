//
//  main.cpp
//  MTime
//
//  Created by Daniel Bessonov on 6/25/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, wakeup = 1000000;

struct job {
    int t, l;
}jobs[1000];

bool comp(job a, job b) {
    return a.t > b.t;
}

int main() {
    freopen("mtime.in", "r", stdin);
    freopen("mtime.out", "w", stdout);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> jobs[i].l >> jobs[i].t;
    }
    
    sort(jobs, jobs+N, comp);
    wakeup = 1000000;
    for(int i = 0; i < N; i++) {
        wakeup = min(jobs[i].t, wakeup) - jobs[i].l;
    }
    
    if(wakeup < 0) {
        cout << "-1" << endl;
    }
    else {
        cout << wakeup << endl;
    }
    
    return 0;
}