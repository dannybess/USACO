//
//  main.cpp
//  LCS
//
//  Created by Daniel Bessonov on 6/23/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int len1, len2;
bool firstTime = false;
int dp[10001];
int dp1[10001];
string s1, s2;

int findTheAnswer(int i, int j)
{
    for(int z = i; z >= 0; z--)
    {
        for(int a = j; a >=0; a--)
        {
            //same as nil
            if(s1[z] == '\0' || s2[a] == '\0')
            {
                dp[a] = 0;
            }
            else if(s1[z] == s2[a])
            {
                dp[a] = dp1[a+1] + 1;
            }
            else
            {
                dp[a] = max(dp1[a], dp[a+1]);
            }
        }
        memcpy(dp1, dp, sizeof(dp1));
    }
    return dp[0];
}


int main()
{
    
    //freopen("lcs2.in", "r", stdin);
    //freopen("lcs2.out", "w", stdout);
    cin >> s1;
    cin >> s2;
    cout << findTheAnswer(len1, len2) << endl;
    return 0;
}



