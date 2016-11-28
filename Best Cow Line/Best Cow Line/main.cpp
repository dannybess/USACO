//
//  main.cpp
//  Best Cow Line
//
//  Created by Daniel Bessonov on 6/26/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
int N, sum;
char p[2001], original[2001], counter;

bool checkForEqual()
{
    int placeholder = 0;
    placeholder = original[0];
    for(int i = 0; i < N; i++)
    {
        if(original[i] != placeholder)
        {
            return false;
        }
    }
    return true;
}

void findSolution()
{
    int a = 0, b = N - 1, c = 1, d = b;
    for(int i = 0; i < N; i++)
    {
        if(original[a] > original[b])
        {
            //least lexographic string
            p[i] = original[b--];
        }
        else if(original[a] < original[b])
        {
            //least lexographic string
            p[i] =  original[a++];
        }
        else if(checkForEqual())
        {
            for(int j = 0; j < N; j++)
            {
                cout << original[i];
            }
            break;
        }
        else
        {
            if(original[c++] < original[d--])
                {
                    p[i] = original[a++];
                }
            else
                {
                    //if equal, set to b--
                    p[i] = original[b--];
                }
            
        }
    }
    for(int i = 0; i < N; i++)
    {
        cout << p[i];
        counter++;
        if(i + 1 == N || counter % 80 == 0)
        {
            cout << '\n';
        }
    }
}

int main()
{
    freopen("bcl.in", "r", stdin);
    freopen("bcl.out", "w", stdout);
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> original[i];
    }
    
    findSolution();
    
    return 0;
}