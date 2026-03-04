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

void problem_a(int n) {
    int nr=3;
    for (int i=1; i<=n; i++) {
        cout<<nr<<": ";
        for (int j=2; j<nr; j++)
            if (relativ_prim(nr,j))
                cout<<j<<" ";
        cout<<endl;
        nr++;
    }
}

bool gleiche_ziffer(int a, int b) {
    bool check=false;
    while (a!=0) {
        int aux=b;
        while (aux!=0) {
            if (a%10==aux%10) {
                check=true;
                break;
            }
            aux/=10;
        }
        if (!check)
            return false;
        check=false;
        a/=10;
    }
    return true;
}

vector<int> problem_b(vector<int> v) {
    int m=0, n=0, start=0,end=0,len=1,len_max=1;
    for (int i=0; i<v.size()-1; i++) {
        if (gleiche_ziffer(v[i],v[i+1]) && gleiche_ziffer(v[i+1],v[i])) {
            len++;
            n=i+1;
        }
        else {
            if (len>len_max) {
                len_max=len;
                start=m;
                end=n;
            }
            len=1;
            m=i+1;
        }
    }
    if (len>len_max) {
        start=m;
        end=n;
    }

    return {v.begin()+start,v.begin()+end+1};
}


int main() {
    int n;
    cout<<"n = ";
    cin >> n;
    problem_a(n);
    vector<int> v;
    cout<<"Enter numbers(0 means stop): ";
    int nr;
    cin>>nr;
    while (nr!=0) {
        v.push_back(nr);
        cin>>nr;
    }
    v = problem_b(v);
    for (int i:v) {
        cout<<i<<" ";
    }

    return 0;
}