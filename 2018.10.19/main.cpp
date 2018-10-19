#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
#define LL unsigned long long
using namespace std;
const int maxn=101;
int cnt1[maxn],isp,sp[maxn];          //cnt1[i]--第i个字符串的项数，isp--待查询的字符串末尾是否为‘/’，sp[i]--第i个字符串末尾是否为‘/’
string str[maxn],str1[maxn],str2;     //str[i]--第i个字符串的配置信息，str1[i]--第i个映射规则，str2--当前需要被查询的字符串
string sp1[maxn][maxn],sp2[maxn];     //sp1[i]--保存第i个字符串的所有项，sp2--保存当前被查询字符串的所有项。
string is_num(string s){              //判断某一项是否为整数：是--去掉前导0并返回整数；不是--返回“-”
    LL res=0,ok=0;
    string ss="";
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]<'0'||s[i]>'9')return "-";
        if(ok||s[i]!='0')ss+=s[i],ok=1;
    }
    if(ss=="")ss="0";
    return ss;
}
void getinfo(string s,string s1[],int &f,int &t){       //分离并保存一个字符串的所有项，标记末尾是否为‘/’
    f=t=0;
    int len=s.length();
    if(s[len-1]=='/')f=1;
    for(int p=0;p<len;p++){
        if(s[p]=='/')s[p]=' ';
    }
    string ss;
    stringstream in(s);
    while(in>>ss)s1[t++]=ss;
}
bool match(int t,int j,string &s){                      //判断被查询字符串与第j个规则是否能匹配
    s="";
    int p1=0,p2=0;
    while(p1<t&&p2<cnt1[j]){
        if(sp2[p1]==sp1[j][p2]);
        else if(sp1[j][p2]=="<int>"){
            string f=is_num(sp2[p1]);
            if(f=="-"){return 0;}
            s+=" "+f;
        }
        else if(sp1[j][p2]=="<str>"){s+=" "+sp2[p1];}
        else if(sp1[j][p2]=="<path>"){                 //<path>直接全部加上
            s+=" "+sp2[p1++];
            while(p1<t)s+="/"+sp2[p1++];
            if(isp)s+='/';
            return 1;
        }
        else return 0;
        p1++;p2++;
    }
    if(isp^sp[j])return 0;                            //末尾判断--同时有‘/’或同时无‘/’才能匹配
    if(p1!=t||p2!=cnt1[j])return 0;                   //完全匹配
    return 1;
}
int main(){                                           //主函数
    //freopen("in.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>str1[i]>>str[i];
        getinfo(str1[i],sp1[i],sp[i],cnt1[i]);
    }
    for(int i=0;i<m;i++){
        string ans;
        int cnt=0;isp=0;
        cin>>str2;
        getinfo(str2,sp2,isp,cnt);
        bool ok=0;
        for(int j=0;j<n;j++){
            if(match(cnt,j,ans)){
                cout<<str[j]<<ans<<endl;;
                ok=1;break;
            }
        }
        if(!ok)cout<<404<<endl;
    }
    return 0;
}
