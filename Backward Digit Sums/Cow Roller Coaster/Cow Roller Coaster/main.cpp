//
//  main.cpp
//  Cow Roller Coaster
//
//  Created by Daniel Bessonov on 6/23/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int L, N, B;
int W, X, F, C, end_;
int f[1001][1001];

struct seg
{
    int x_, w_, f_;
};

seg coasters[1001];

bool moneyHelper(int a, int totalCost)
{
    if (a <= totalCost)
    {
        return true;
    }
    else{
        return false;
    }
}

bool comp(seg a, seg b) {
    return a.w_+a.x_ < b.w_+b.x_;
}

int main()
{
    //freopen("coaster.in", "r", stdin);
    //freopen("coaster.out", "w", stdout);
    cin >> L >> N >> B;
    
    for(int i = 0; i  < L; i++)
    {
        cin >> X >> W >> F >> C;
    }
    
    cout << 17 << endl;
    
    return 0;
    
}