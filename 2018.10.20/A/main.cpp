#include <bits/stdc++.h>
using namespace std;
set<int> si;
int main()  {
    int n,m,a,b;
    cin>>n>>m;
    for (int i=0;i<m;i++)   {
        cin>>a>>b;
        si.insert(a);
        si.insert(b);
    }
    set<int>::iterator it1=si.begin();
    cout<<(*it1);it1++;
    for (;it1!=si.end();it1++)
        cout<<' '<<(*it1);
    cout<<endl;
    return 0;
}
