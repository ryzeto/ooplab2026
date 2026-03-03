//
// Created by Raul Marginean on 28.02.2026.
//

#include <iostream>
#include <vector>
using namespace std;

bool relativ_prim(int a, int b) {
    for (int i=2; i<=max(a,b)/2; i++)
        if (a%i==0 && b%i==0)
            return false;
    return true;
}

bool prim(int a) {
    for (int i=2; i<=a/2; i++)
        if (a%i==0)
            return false;
    return true;
}

vector<int> problem_a(int n) {
    int nr=3;
    vector<int> v;
    for (int i=1; i<=n; i++) {
        bool found=true;
        for (int j=2; j<nr; j++)
            if (relativ_prim(nr,j) && !prim(j))
                found=false;
        if (found)
            v.push_back(nr);
        else
            i--;
        if (i>=8)
            break;
        nr++;
    }
    return v;
}

int main() {
    int n;
    cout<<"n = ";
    cin >> n;
    vector<int> v=problem_a(n);
    for (int i:v) {
        cout<<i<<" ";
    }

    return 0;
}