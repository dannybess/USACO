//
//  main.cpp
//  Subsets
//
//  Created by Daniel Bessonov on 6/19/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

ostream & print(const vector<int> & v)
{
    int size=v.size();
    for (int i=0; i<size; i++)
        cout << v[i] << ' ';
    return cout;
}

int main()
{
    int digit_count;
    int digit_values;
    
    cout << "enter number of digits (>0): ";
    cin >> digit_count;
    
    cout << "enter number of digit values (>0): ";
    cin >> digit_values;
    
    vector<int> vint;
    vint.resize(digit_count);
    
    for (int i=0; i<digit_count; i++)
        vint[i]=0;
    
    print(vint) << endl; //lol
    
    int carry;
    
    while (true)
    {
        carry=1;
        
        for (int i=0; i<digit_count; i++)
        {
            int & cur=vint[i];
            
            cur+=carry;
            if (cur==digit_values)
            {
                cur=0;
                carry=1;
            }
            else
            {
                carry=0;
                break;
            }
        }
        
        if (carry==1) break;
        
        print(vint) << endl;
    }
    
    return 0;
}