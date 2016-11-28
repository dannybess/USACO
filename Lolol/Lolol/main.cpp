//
//  main.cpp
//  Lolol
//
//  Created by Daniel Bessonov on 6/27/15.
//  Copyright (c) 2015 Daniel Bessonov. All rights reserved.
//

#include <iostream>
#include <cstdio>

int N;

int main()
{
    std::cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int z = 0; z < N; z++)
            {
                for(int a = 0; z < N; a++)
                {
                    for(int o = 0; o < N; o++)
                    {
                        std::cout << (i * j + z + a + o) / 1000000 << std::endl;
                    }
                }
            }
        }
    }
}