//
//  main.cpp
//  Sed
//
//  Created by Daniel Bessonov on 6/23/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string s1, s2;
int matrix[1001][1001];

int main() {
    freopen("sed.in", "r", stdin);
    freopen("sed.out", "w", stdout);
    
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    for(int i = 0; i <= n; i++) {
        matrix[i][0] = i;
    }
    for(int i = 0; i <= m; i++) {
        matrix[0][i] = i;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            }
            else {
                matrix[i][j] = min(matrix[i-1][j]+1, min(matrix[i][j-1]+1, matrix[i-1][j-1]+1));
            }
        }
    }
    cout << matrix[n][m] << endl;
    return 0;
}
