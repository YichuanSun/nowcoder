#include <bits/stdc++.h>
#define MAX 10000000
using namespace std;
vector<int> v;
void vdel(int x)    {
    for (int i=0;i<(int)v.size();i++)
        if (v[i]==x)    {v[i]=MAX;return;}
}
void otrank(int x)  {
    for (int i=0;i<(int)v.size();i++)
        w.push_back(v[i]);
    sort(w.begin(),w.end());
    for (int i=0;i<(int)w.size();i++)   {
        if (w[i]==x)    {
            cout<<i+1<<endl;
            return;
        }
    }
}
void xrank(int x)  {
    for (int i=0;i<(int)w.size();i++)   {
        if (v[i]==x)    {
            cout<<i+1<<endl;
            return;
        }
    }
}
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,op,x;
    for (int i=0;i<n;i++)   {
        cin>>op>>x;
        switch(x)   {
            case 1: v.push_back(x);
            case 2: vdel(x);
            case 3: otrank(x);
            case 4: xrank(x);
            case 5: xpre(x);
            case 6: xnext(x);
        }
    }
    return 0;
}
