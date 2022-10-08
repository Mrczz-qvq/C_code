#include <bits/stdc++.h>
using namespace std;
int n,i,j,q,kk,c[1000],v[1000],k[1000];
int x,y;
int dp1[3010][3010];
int dp2[3010][3010];
int V=1000;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> c[i]>>v[i]>>k[i]; //c 促销价 v 原价 k 数量
    }
    for(i=1; i<=n; i++)
    {
        int num = min(k[i], V / c[i]);
       for(kk=0; kk<=num; kk++)
       {
        for (int j = V; j >= c[i] * kk; j--) // 01背包
            dp1[i][j] = max(dp1[i][j], dp1[i-1][j - c[i] * kk] + v[i] * kk);
        }
    }
    for(i=n; i>0; i--)
    {
        int num = min(k[i], V / c[i]);
       for(kk=0; kk<=num; kk++)
       {
        for (int j = V; j >= c[i] * kk; j--) // 01背包
            dp2[i][j] = max(dp2[i][j], dp2[i+1][j - c[i] * kk] + v[i] * kk);
        }
    }
    
    cin>>q;
    int x1;
    while(q--){
        cin>>x>>y;
        y++;
        int ans =0 ;
        for(x1 = 0; x1<=x;x1++)
        {
            ans = max(ans,dp1[y-1][x1]+dp2[y+1][x-x1]);
        }
        cout<<ans<<endl;;
    }
    system("pause");
    return 0;
}