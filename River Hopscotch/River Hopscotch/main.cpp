//
//  main.cpp
//  River Hopscotch
//
//  Created by Daniel Bessonov on 6/25/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//
/*
//greedy algorithm
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int L, N, M, rocks[1000001], x = 0;

int intcmp(const void *p1, const void *p2)
{
    return(*(int*)p1 - *(int*)p2);
}

void getAnswer()
{
    //qsort(rocks, N, sizeof(int), intcmp);
    int len_placeholder = L;
    if (x < len_placeholder)
    {
        int y = 0;
        int z = 0;
        for(int i= 0; i < N; i++)
        {
            if(rocks[i] - y < (x + len_placeholder + 1) / 2)
            {
                z++;
            }
            else
            {
                y = rocks[i];
            }
        }
        if(z > M)
        {
            len_placeholder = ((x + len_placeholder + 1) / 2) - 1;
        }
        else
        {
            y = (x + len_placeholder + 1) / 2;
        }
    }
    cout << x << endl;
}


int main()
{
    //freopen("river.in", "r", stdin);
    //freopen("river.out", "w", stdout);
    cin >> L >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> rocks[i];
    }
    while(x < L)
    {
        getAnswer();
    }
    
    return 0;
}
*/