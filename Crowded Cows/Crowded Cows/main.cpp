//
//  main.cpp
//  Crowded Cows
//
//  Created by Daniel Bessonov on 6/25/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, D, sum = 0;
bool x, y; //x right y left

void doStuff(vector<pair<int, int> >v)
{
    //just check for right and left
    for(int i = 0; i < N; i++)
    {
        y = false;
        for(int j = i - 1; j >= 0; j--)
        {
            if (v[i].first - v[j].first > D)
            {
                break;
            }
            else if(v[j].second >= v[i].second * 2)
            {
                y = true;
                break;
            }
        }
        x = false;
        for(int a = i + 1; a < N; a++)
        {
            if(v[a].first - v[i].first > D)
            {
                break;
            }
            if(v[a].second >= v[i].second * 2)
            {
                x = true;
                break;
            }
        }
        if(x == true && y == true)
        {
            sum++;
        }
    }
}

int main()
{
    //freopen("crowded.in", "r", stdin);
    //freopen("crowded.out", "w", stdout);
    cin >> N >> D;
    vector<pair<int, int> > v(N);
    for(int i = 0; i < N; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    doStuff(v);
    cout << sum << endl;
    return 0;
}