//
//  backup.cpp
//  Bad Hair
//
//  Created by Daniel Bessonov on 6/19/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//
/*
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;


int N, a, total;
int cows[80000];
vector<int> compare_dat_cow[80000];

int main() {
    //freopen("badhair.in", "r", stdin);
    //freopen("badhair.out", "w", stdout);
    
    cin >> N;
    for(int i = 0; i < N; i ++)
    {
        cin >> cows[i];
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            a = cows[i];
            if(cows[j] < cows[i]) {
                total++;
            }
            else {
                break;
            }
        }
        
    }
    cout << total << endl;
    return 0;
    
}
*/