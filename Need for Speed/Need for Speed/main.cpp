#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct part {
    int f, m, i;
}parts[10000];

bool comp(part a, part b) {
    return a.f*b.m > b.f*a.m;
}
vector<int> possible;
int F, M, N;

int main() {
    freopen("sboost.in", "r", stdin);
    freopen("sboost.out", "w", stdout);
    
    cin >> F >> M >> N;
    double curacc = F/M;
    for(int i = 0; i < N; i++) {
        cin >> parts[i].f >> parts[i].m;
        parts[i].i = i;
    }
    sort(parts, parts+N, comp);
    
    for(int i = 0; i < N; i++) {
        double acc = parts[i].f/parts[i].m;
        if(curacc <= acc) {
            F += parts[i].f;
            M += parts[i].m;
            curacc = F/M;
            possible.push_back(parts[i].i);
        }
        else {
            break;
        }
    }
    if(possible.size() == 0) {
        cout << "NONE" << endl;
    }
    else {
        sort(possible.begin(), possible.end());
        for(int i = 0; i < possible.size(); i++) {
            cout << possible[i]+1 << endl;
        }
    }
    return 0;
}

