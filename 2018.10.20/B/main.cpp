#include <bits/stdc++.h>
#define N 100005
using namespace std;
int qt[N],ql[N];
int main()  {
    int n,t,a,b,ans1=0,ans2=0,t1,t2,f1=0,f2=0;
    cin>>n>>t>>a>>b;
    t1=t2=t;
    for (int i=0;i<n;i++)   cin>>qt[i];
    for (int i=0;i<n;i++)   cin>>ql[i];
    for (int i=0;i<n;i++)   {
        if (t1<=0)  f1=1;
        if (ql[i]<a&&!f1)    {
            ans1++;
            t1-=qt[i];
        }
        if (t2<=0)  f2=1;
        if (f2) continue;
        if (ql[i]>=b)   {
            if (t2<2*qt[i]) t2=0;
            else    ans2++,t2-=2*qt[i];
        }
        else ans2++,t2-=qt[i];
    }
    cout<<ans1<<' '<<ans2<<endl;
    return 0;
}
