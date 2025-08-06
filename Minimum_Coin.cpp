#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    int money;
    cin>>money;
    sort(v.begin(),v.end());
    int coin_need=0;
    for(int i=n-1; i>=0; i--)
    {
        int k=(money/v[i]);
        coin_need+=k;
        money-=(v[i]*k);
    }
    cout<<coin_need<<endl;

    return 0;
}

///time complexity: O(n)
/*
4
1 2 5 10
39
*/
