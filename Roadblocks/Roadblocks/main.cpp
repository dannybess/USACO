//
//  main.cpp
//  Roadblocks
//
//  Created by Daniel Bessonov on 6/26/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int N, R, nodes[5001];

using namespace std;
struct edge {
    int v, w;
    bool operator<(edge const& o) const {
        return w > o.w;
    }
};

bool vis[50000];
vector<edge> graph[50000];
int dist[50000];
priority_queue<edge> q;

int bfs() {
    for(int i = 0; i < N; i++) {
        dist[i] = 12000000;
    }
    dist[0] = 0;
    edge e = {0, 0};
    q.push(e);
    while(!q.empty()) {
        int x = q.top().v;
        q.pop();
        if(vis[x]) continue;
        vis[x] = true;
        for(int j = 0; j < graph[x].size(); j++) {
            int a = graph[x][j].v;
            int b = graph[x][j].w;
            if(dist[a] > dist[x] + b) {
                dist[a] = dist[x] + b;
                edge c = {a, dist[x]+b};
                q.push(c);
            }
        }
    }
    return (dist[2] + dist[1]);
}

int main() {
    //freopen("block.in", "r", stdin);
    //freopen("block.out", "w", stdout);
    cin >> N >> R;
    for(int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge e = {b-1, c};
        graph[a-1].push_back(e);
        e.v = a-1;
        graph[b-1].push_back(e);
    }
    int a = bfs();
    cout << a << endl;
    return 0;
}