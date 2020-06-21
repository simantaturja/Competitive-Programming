#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define sf(x) scanf("%f",&x)
#define slf(x) scanf("%lf",&x)

#define pds(x) printf("%d ",x)
#define pdn(x) printf("%d\n",x)
#define pllds(x) printf("%lld ",x)
#define plldn(x) printf("%lld\n",x)
#define pfs(x) printf("%f ",x)
#define pfn(x) printf("%f\n",x)
#define plfs(x) printf("%lf ",x)
#define plfn(x) printf("%lf\n",x)
#define pn printf("\n")

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pipii pair<int,pair<int,int> >

const double pi=2*acos(0.0);


int main()
{
    int n;
    sd(n);
    vector<int> a(n);
    vector<int> b(n);
    map<int,int> mpa;
    map<int,int> mpb;
    for(int i=0;i<n;i++)
    {
        sd(a[i]);
        mpa[a[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        sd(b[i]);
        mpb[b[i]]=i;
    }
    map<int,int> mp1;
    for(int i=0;i<n;i++)
    {
        int j=mpb[a[i]];
        if(j>i)
            mp1[i+n-j]++;
        else
            mp1[i-j]++;
    }
    map<int,int> mp2;
    for(int i=0;i<n;i++)
    {
        int j=mpb[a[i]];
        if(j>=i)
            mp2[j-i]++;
        else
            mp2[j+n-i]++;
    }
    map<int,int> :: iterator it;
    int maxi=0;
    for(it=mp1.begin();it!=mp1.end();it++)
        maxi=max(maxi,it->second);
    for(it=mp2.begin();it!=mp2.end();it++)
        maxi=max(maxi,it->second);
    pdn(maxi);
    return 0;
}