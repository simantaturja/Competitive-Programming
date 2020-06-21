#include <bits/stdc++.h> 
using namespace std;
#define endl "\n"
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        string ans;
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
            ans += ' ';

        int b[m];
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        int cnt = 0;
        map<int, int> mp;
        for (int i = 0; i < str.size(); i++)
        {
            mp[str[i]]++;
        }

        auto itr = mp.end();
        itr--;
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            if (b[i] == 0)
                count++;
        }

        while (itr != mp.begin() && itr->second < count)
        {
            itr--;
        }
        for (int i = 0; i < m; i++)
        {
            if (b[i] == 0)
                ans[i] = itr->first;
        }
        //	cout<<count<<" "<<ans<<endl;
        cnt = count;
        //cout<<cnt<<endl;
        cout << cnt << endl;
        while (cnt != m)
        {
            if (itr != mp.begin())
                itr--;
            int a[m] = {0};
            int y = 0;
            for (int i = 0; i < m; i++)
            {
                //	cout<<ans[i]<<endl;
                if (ans[i] != ' ')
                    continue;

                for (int j = 0; j < m; j++)
                {
                    if (ans[j] != ' ')
                    {
                        //		cout<<i<<" "<<j<<endl;
                        y = abs(i - j);
                        a[i] += y;
                    }
                }
            }
            count = 0;
            //	cout<<11<<endl;
            for (int i = 0; i < m; i++)
            {
                if (ans[i] != ' ')
                    continue;
                if (a[i] == b[i])
                    count++;
            }
            cout << count << endl;
            
            /*	for(int i=0;i<m;i++){
 			cout<<a[i]<<" "<<b[i];
 			cout<<endl;
 			
 		}*/
            while (itr != mp.begin() && itr->second < count)
            {
                itr--;
            }
            for (int i = 0; i < m; i++)
            {
                if (ans[i] != ' ')
                {
                    continue;
                }

                if (a[i] == b[i])
                    ans[i] = itr->first;
            }
            cnt += count;
            cout << cnt << ' ' << count << endl;
        }

        cout << ans << endl;
    }
    return 0;
}