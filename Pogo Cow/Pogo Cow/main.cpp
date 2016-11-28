//

//  main.cpp

//  Pogo Cow

//

//  Created by Daniel Bessonov on 6/22/15.

//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.



#include <iostream>

#include <cstdio>

#include <algorithm>

#include <vector>



using namespace std;



int N;

int d[1005][1005];

int suchirTheGreat = 0, sum = 0;



void generatePosition(vector<pair<int, int> > thePair)

{
    
    int mult = 0;
    
    for(int i = 0; i < N; i++)
        
    {
        
        d[i][i] = thePair[i].second;
        
        for(int j = i - 1; j > 0; j--)
            
        {
            
            suchirTheGreat = lower_bound(thePair.begin(), thePair.begin() + j, make_pair((thePair[j].first * 2) - thePair[i].first, 0)) - thePair.begin();
            
            d[i][j] = max(d[i][j+2], thePair[i].second + d[j][suchirTheGreat]);
            
        }
        
    }
    
}







int main()

{
    
    freopen("pogocow.in", "r", stdin);
    
    freopen("pogocow.out", "w", stdout);
    
    
    
    cin >> N;
    
    
    
    vector<pair<int, int> > two_pair(N);
    
    
    
    //use pair to avoid two for loops
    
    for(int i = 0; i < N; i++)
        
    {
        
        cin >> two_pair[i].first >> two_pair[i].second;
        
    }
    
    
    
    //sort our pair
    
    sort(two_pair.begin(), two_pair.end());
    
    generatePosition(two_pair);
    
    for(int i = 0; i < N; i++)
        
    {
        
        sum = max(sum, d[i][1]);
        
    }
    
    //cout << sum << endl;
    
    return 0;
    
}

