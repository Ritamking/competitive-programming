// Codeforces: https://codeforces.com/contest/1701/C
// Problem: Schedule Management
// Submission: https://codeforces.com/contest/1701/submission/396735808
// Language: C++20 (GCC 13-64)
// Submitted: 2026-10-30T19:24:09.000Z
// Rating: 1400
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tests;
    cin>>tests;
    for(int i=1 ; i<=tests ; i++)
    {
        long long int n,m;
        cin>>n>>m;
        vector<long long int>a(m);
        map<long long int,long long int>mp;
        for(int i=0; i<m;i++)
        {
            cin>>a[i];
            mp[a[i]]++;
        }
        long long int start = 0;
        long long int end = 2*m;
        long long int mid = m;
        long long int ans = 2*m;
        while(start<=end)
        {
            long long int mid = start + (end - start)/2;
            long long int curr = 0;
            for(long long int i=1;i<=n;i++)
            {
                long long int count = min(mp[i],mid);
                long long int rest = (mid - count)/2;
                curr += rest + count;
            }
            if(curr>=m)
            {
                ans = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }

        }
        cout<<ans<<endl;
    }

}
