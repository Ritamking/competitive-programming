// Codeforces: https://codeforces.com/contest/2227/D
// Problem: Palindromex
// Submission: https://codeforces.com/contest/2227/submission/396411679
// Language: C++20 (GCC 13-64)
// Submitted: 2026-10-28T11:46:45.000Z
// Rating: 1200
#include <bits/stdc++.h>
using namespace std;
long long int mex(map <long long int,long long int> &mp,long long int n)
{
    long long int ans = n;
    for(long long int i=0;i<n;i++)
    {
        if(mp[i]==0)
        {
            ans = i;
            break;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tests;
    cin>>tests;
    for(int i=1 ; i<=tests ; i++)
    {
        long long int n;
        cin>>n;
        vector<long long int>a(2*n);
        vector<long long int>z;
        for(int i=0; i<2*n;i++)
        {
            cin>>a[i];
            if(a[i]==0)
            {
                z.push_back(i);
            }
        }   
        long long int z1 = z[0];
        long long int z2 = z[1];
        long long int i1 = 0;
        map<long long int,long long int>mp1;
        map<long long int,long long int>mp2;
        while(i1<z2-z1)
        {
            if((z1+i1>=2*n) || (z1-i1<0) || (a[z1+i1]!=a[z1-i1]))
            {
                i1--;
                break;
            }
            mp1[a[z1+i1]]++;
            i1++;
        }
        long long int ans1 = mex(mp1,n);
        long long int i2 = 0;
        while(i2<z2-z1)
        {
            if((z2+i2>=2*n) || (z2-i2<0) || a[z2+i2]!=a[z2-i2])
            {
                i2--;
                break;
            }
            mp2[a[z2+i2]]++;
            i2++;
        }
        long long int ans2 = mex(mp2,n);
        long long int start = z1;
        long long int end = z2;
        long long int cnt = 0;
        map<long long int,long long int>mp3;
        while(start<=end)
        {
            if(a[start]!=a[end])
            {
                cnt = 1;
                break;
            }
            mp3[a[start]]++;
            start++;
            end--;
        }
        if(cnt==1)
        {
            cout<<max(ans1,ans2)<<endl;
            continue;
        }
        start= z1-1;
        end = z2+1;
        while(start>=0 && end<2*n && a[start]==a[end])
        {
            mp3[a[start]]++;
            start--;
            end++;
        }
        long long int ans3 = mex(mp3,n);
        long long int ans = max(ans1,max(ans2,ans3));
        cout<<ans<<endl;
    }

}
