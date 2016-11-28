//
//  main1.cpp
//  Backward Digit Sums
//
//  Created by Daniel Bessonov on 6/15/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int start[10], n, total;
bool randomidk;
int factorial(int c) {
    if(c == 0) return 1;
    int result = 1;
    for(int i = 1; i <= c; i++) {
        result *= i;
    }
    return result;
}
int choose(int a, int b) {
    int asdfghjkl = a-b;
    return factorial(a)/(factorial(asdfghjkl) * factorial(b));
}
void permute() {
    next_permutation(start, start+n);
}
bool attempt() {
    int replacetotal = 0;
    for(int i = 0; i < n; i++) {
        replacetotal += choose(n-1, i) * start[i];
    }
    return (replacetotal == total);
}
int main() {
    freopen("bds.in", "r", stdin);
    freopen("bds.out", "w", stdout);
    cin >> n >> total;
    for(int i = 0; i < n; i++) {
        start[i] = i+1;
    }
    int asdf = factorial(n);
    for(int
         i = 0; i < asdf; i++) {
        randomidk = attempt();
        if(randomidk == true) {
            break;
        }
        permute();
    }
    for(int i = 0; i < n; i++) {
        if(i != n-1) {
            cout << start[i] << " ";
        }
        else {
            cout << start[i] << endl;
        }
    }
    return 0;
}
