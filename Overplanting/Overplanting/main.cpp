//
//  main.cpp
//  Overplanting
//
//  Created by Daniel Bessonov on 6/26/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int N, rectangles[1001];
vector<pair <int, int > > v;
struct point
{
    int x, y;
};
struct line
{
    point p1, p2;
};

int ccw(point p0, point p1, point p2);

int intersect(line l1, line l2)
{
    return ((ccw(l1.p1, l1.p2, l2.p1)*ccw(l1.p1, l1.p2, l2.p2)) <= 0)
    && ((ccw(l2.p1, l2.p2, l1.p1)*ccw(l2.p1, l2.p2, l1.p2)) <= 0);
    
}

int main()
{
    
    //freopen("planting.in", "r", stdin);
    //freopen("planting.out", "w", stdout);
    cin >> N;
    int a, b, c, d;
    for(int i = 0; i < N; i++)
    {
        cin >> a >> b >> c >> d;
        pair<int, int> c_ = make_pair(a, b);
        pair<int, int> d_ = make_pair(c, d);
        v.push_back(c_);
        v.push_back(d_);
    }
    point pt1 = {0, 5};
    point pt2 = {4, 1};
    point pt_1 = {2, 4};
    point pt_2 = {6, 2};
    line ln1 = {pt1, pt2};
    line ln2 = {pt_1, pt_2};
    intersect(ln1, ln2);
    return 0;
}