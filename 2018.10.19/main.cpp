#include <bits/stdc++.h>
#define N 1000005
using namespace std;
typedef long long ll;
ll ans;
int a[N];
int main()  {
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)   cin>>a[i];
    for (int i=n;i>=1;i--)  {
        if (a[i]<=0)    ans+=a[i]*i;
        else    ans+=a[i];
    }
    cout<<ans<<endl;
    return 0;
}
