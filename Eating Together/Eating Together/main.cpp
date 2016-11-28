//
//  main.cpp
//  Eating Together
//
//  Created by Daniel Bessonov on 6/23/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, states[30000], goingup[30000] = {1}, goingdown[30000] = {1};

int main() {
    freopen("egroup.in", "r", stdin);
    freopen("egroup.out", "w", stdout);
    cin >> N;
    for(int i = 0; i < N; i++)  cin >> states[i];
    int up = 0, down = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < i; ++j) {
            if(states[i] >= states[j] && goingup[j] > up) up = goingup[j];
            if(states[j] >= states[i] && goingdown[j] > down) down = goingdown[j];
            goingup[i] = up + 1;
            goingdown[i] = down + 1;
        }
    }
    int maxsum = max(goingup[N-1], goingdown[N-1]);
    cout << N - maxsum << endl;
    return 0;
}