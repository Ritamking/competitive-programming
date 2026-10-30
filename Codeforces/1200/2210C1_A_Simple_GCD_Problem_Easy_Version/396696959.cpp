// Codeforces: https://codeforces.com/contest/2210/C1
// Problem: A Simple GCD Problem (Easy Version)
// Submission: https://codeforces.com/contest/2210/submission/396696959
// Language: C++20 (GCC 13-64)
// Submitted: 2026-10-30T14:19:27.000Z
// Rating: 1200
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tests;
    cin>>tests;
    for(int i=1 ; i<=tests ; i++)
    {
        long long int n;
        cin>>n;
        vector<long long int>a(n);
        vector<long long int>b(n);
        for(int i=0; i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<n;i++)
        {
            cin>>b[i];
        }
        long long int ans = 0;
        if(a[0]>gcd(a[0],a[1]))
        {
            ans++;
        }
        if(a[n-1]>gcd(a[n-1],a[n-2]))
        {
            ans++;
        }
        for(int i=1;i<n-1;i++)
        {
            if(lcm(gcd(a[i],a[i-1]),gcd(a[i],a[i+1]))<a[i])
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }

}
