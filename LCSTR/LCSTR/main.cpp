//
//  main.cpp
//  LCSTR
//
//  Created by Daniel Bessonov on 6/15/16.
//  Copyright (c) 2016 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string one, two;
int counter, best;

void f(int a, int b) {
    if(one[a] == two[b]) {
        counter++;
        f(a-1, b-1);
    }
    else {
        if(best < counter) {
            best = counter;
        }
        counter = 0;
        return;
    }
}

int main() {
    //freopen("lcstr.in", "r", stdin);
    //freopen("lcstr.out", "w", stdout);
    
    cout << "Please enter the first string." << endl;
    cin >> one;
    cout << "Please enter the second string." << endl;
    cin >> two;
    
    for(int i = 0; i < one.length(); i++) {
        for(int j = 0; j < two.length(); j++) {
            f(i, j);
        }
    }
    cout << best << endl;
    return 0;
}