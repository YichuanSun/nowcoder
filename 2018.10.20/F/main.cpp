#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,op,x;
    for (int i=0;i<n;i++)   {
        cin>>op>>x;
        switch(x)   {
            case 1: v.push_back(x);
            case 2: v.erase(v.find(x));
        }
    }
    return 0;
}
