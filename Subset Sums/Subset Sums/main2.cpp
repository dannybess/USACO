//
//  main2.cpp
//  Subset Sums
//
//  Created by Daniel Bessonov on 6/23/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//


#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

long long N, sum_, ans;
long long d[400];
bool doNotPrint = false;

void getAnswer()
{
    memset(d, 0, sizeof(d));
    sum_ = ((N + 1) * N) / 2;
    d[0] = 1;
    for(int i = 0; i < N; i++)
    {
        for(int j = sum_ / 2; j >= i; j--)
        {
            d[j] = d[j] + d[j-i];
        }
    }
    
    if(sum_ % 2 != 0)
    {
        doNotPrint = true;
        cout << 0 << endl;
    }

    
}


int main()
{
    
    //freopen("subset.in", "r", stdin);
    //freopen("subset.out", "w", stdout);
    cin >> N;
    
    getAnswer();
    ans = d[sum_/2] / 2;
    if(doNotPrint!=true)
    {
        cout << ans << endl;
    }
    return 0;
}
