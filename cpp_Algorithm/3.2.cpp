#include <bits/stdc++.h>
using namespace std;
int dp[3010][3010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,i,j;
    cin >> n;
    int a[5010];
    unordered_map<int, int> map1;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        map1[a[i]]=i;
    }
  int result = 0;     
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                int ak = a[i] + a[j];
                auto it = map1.find(ak);
                if(it!=map1.end()) {
                    dp[j][it->second] = dp[i][j] + 1;
                    result = max(result, dp[j][it->second]);
                }
            }
        }
    if (result!=0)
    {
        cout<<result+2;
    }
    else 
        cout<<-1;
    
    system("pause");
    return 0;
}