//
//  main.cpp
//  Forgotten Password
//
//  Created by Daniel Bessonov on 6/22/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int len, n;
string dict[1000], password, possible[1000];
bool check(int x, int y) {
    for (int i=0; i < dict[y].length(); i++) {
        if (password[x+i]!='?' && password[x+i]!=dict[y][i]) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("forgot.in", "r", stdin);
    freopen("forgot.out", "w", stdout);
    
    cin >> len >> n >> password;
    for(int i = 0; i < n; i++) {
        cin >> dict[i];
    }
    for(int i = len-1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            if((dict[j].length()+i <= len && check(i, j)) && (dict[j].length()+i==len || possible[dict[j].length()+i]!="")) {
                if(possible[i] == "" || possible[i] > dict[j] + possible[dict[j].length()+i]) {
                    possible[i] = dict[j]+possible[dict[j].length()+i];
                }
            }
        }
    }
    cout << possible[0] << endl;
    return 0;
}


