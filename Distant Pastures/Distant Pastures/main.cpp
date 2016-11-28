//
//  main.cpp
//  Distant Pastures
//
//  Created by Daniel Bessonov on 6/22/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N, A, B;
char graph[40][40];
bool vis[40][40];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool check(int a) {
    return (a >= 0 && a < N);
}

struct node {
    int x, y, w;
    bool operator<(node const& o) const {
        return w > o.w;
    }
};
node m;
priority_queue<node> pq;
int dij(int x, int y) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            vis[i][j] = false;
        }
    }
    m.x = x;
    m.y = y;
    m.w = 0;
    pq.push(m);
    int cost;
    while(!pq.empty()) {
        node v = pq.top();
        pq.pop();
        if(!vis[v.x][v.y]) {
            vis[v.x][v.y] = true;
            for(int i = 0; i < 4; i++) {
                int t = v.x+dx[i];
                int y = v.y+dy[i];
                if(check(t) && check(y)) {
                    int d;
                    if(graph[t][y] == graph[v.x][v.y]) {
                        d = v.w + A;
                    }
                    else {
                        d = v.w + B;
                    }
                    m.x = t;
                    m.y = y;
                    m.w = d;
                    pq.push(m);
                }
            }
            cost = max(cost, v.w);
        }
    }
    return cost;
}

int main() {
    freopen("distant.in", "r", stdin);
    freopen("distant.out", "w", stdout);
    
    cin >> N >> A >> B;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }
    int total = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int c = dij(i, j);
            total = max(c, total);
        }
    }
    cout << total << endl;
    return 0;
}