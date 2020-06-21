#include <bits/stdc++.h>
using namespace std;
bool chec(int long long n)
{
    while(n!=0)
    {
        if(n%10==0)
        {
            return true;
        }
        n/=10;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int long long n,t,q,k,st,maxi,mini,ans,cnt,a,b,c,m,len,x,y,en;
    bool flag;
    string str;
    cin>>t;
    while(t--)
    {
        ans=0;
        flag=true;
        cin>>n>>k;
        vector<int long long>v;
        ans=n;
        while(1)
        {
            v.push_back(ans);
            if(chec(ans))
            {
                break;
            }
            cnt=ans;
        maxi=INT_MIN;
        mini=INT_MAX;
 
            while(cnt!=0)
            {
                mini=min(mini,cnt%10);
                maxi=max(maxi,cnt%10);
                cnt/=10;
            }
            ans+=mini*maxi;
        }
        if(k>=v.size())
        {
            cout<<v[v.size()-1]<<endl;
        }
        else
        cout<<v[k-1]<<endl;
    }
}