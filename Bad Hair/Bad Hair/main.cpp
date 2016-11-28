//
//  main.cpp
//  Bad Hair
//
//  Created by Daniel Bessonov on 6/16/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

long long int n,ct[88888];
struct node
{
    long long int h, id;
}H[88888];

stack<node> q;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> H[i].h;
        H[i].id=i;
    }
    long long int ans=0;
    q.push(H[n-1]);
    for(long long i=n-2;i>=0;i--)
    {
        while(!q.empty()&&q.top().h<H[i].h)
        {
            node D=q.top();
            q.pop();
            ct[i]+=(1+ct[D.id]);
        }
        q.push(H[i]);
    }
    for(int i=0;i<n;i++)
    {
        ans+=ct[i];
    }
    cout << ans;
    return 0;
}