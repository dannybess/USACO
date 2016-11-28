//
//  main.cpp
//  Haybale Stacking
//
//  Created by Daniel Bessonov on 6/25/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int k;
int a, b;

void doShit()
{
    int d[n+1];
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        for(int j = a-1; j < b; j++){
            d[j]++;
        }
    
    }
    sort(d, d+n);
    cout << d[n/2] << endl;
}

int main(){
    
    //freopen("stacking.in", "r", stdin);
    //freopen("stacking.out", "w", stdout);
    cin >> n >> k;

    doShit();
}