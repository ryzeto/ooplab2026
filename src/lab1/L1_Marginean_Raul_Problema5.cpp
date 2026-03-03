//
// Created by Raul Marginean on 28.02.2026.
//

#include <iostream>
#include <vector>
using namespace std;

double problem_a(double x, int n) {
    double nr=1, aux=x;
    while (n>0) {
        if (n%2==1)
            nr*=aux;
        aux*=aux;
        n=n/2;
    }
    return nr;
}

vector<int> problem_b(vector<int> v) {
    int m=0, n=0, start=0,end=0,len=1,len_max=1;
    for (int i=0; i<v.size()-1; i++) {
        if ((v[i]>0 && v[i+1]<0)|| (v[i]<0 && v[i+1]>0)) {
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
    double x;
    cout<<"x = ";
    cin>>x;
    cout<<"n = ";
    cin>>n;
    cout<<problem_a(x,n)<<endl;
    vector<int> v={1,4,-2,-2,10,-3,4,-2,1};
    cout<<"Enter numbers(0 means stop): ";
    int nr;
    cin>>nr;
    while (nr!=0) {
        v.push_back(nr);
        cin>>nr;
    }
    v = problem_b(v);
    for (int i:v)
        cout<<i<<" ";

    return 0;
}