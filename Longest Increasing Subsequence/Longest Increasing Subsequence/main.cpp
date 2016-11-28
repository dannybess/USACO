#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, num[20000];
vector<int> l;
vector<int>::iterator it;
int main() {
    //freopen("lis.in", "r", stdin);
    //freopen("lis.out", "w", stdout);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num[i];
    }
    for(int i = 0; i < N; i++) {
        it = lower_bound(l.begin(), l.end(), num[i]);
        if(it==l.end()) {
            l.push_back(num[i]);
        }
        else {
            *it = num[i];
        }
    }
    cout << l.size() << endl;
    return 0;
}