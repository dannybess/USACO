//
//  main.cpp
//  Pachinko1
//
//  Created by Daniel Bessonov on 6/22/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int R, graph[100][100], ans;

int main() {
    freopen("pachinko2.in", "r", stdin);
    freopen("pachinko2.out", "w", stdout);
    
    cin >> R;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < i+1; j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = R - 2; i >= 0; i--) {
        for (int j = 0; j < i+1; j++) {
            graph[i][j] += max(graph[i+1][j], graph[i+1][j+1]);
        }
    }
    cout << graph[0][0] << endl;
    return 0;
}