#include <bits/stdc++.h>
using namespace std;
long long Count1 = 0;
long long n,l,r,length=0;
void dfs(long long int n, long long int left, long long int right)
{
    
    long long int mid =(left+right)/2;
    if(left>r)
    return;
    if(right<l)
    return;
    if(n==1)
    {
      Count1++;
      return;
    }
    if(n%2==1&&mid>=l&&mid<=r)
    {
      Count1++;
    }
    dfs(n/2,left,mid-1);
    dfs(n/2,mid+1,right);
    
}

int main()
{
 cin >> n>>l>>r;
 for(int i=0;pow(2,i)<=n;i++)
 {
    length+=pow(2,i);
 }
 dfs(n,1,length);
 cout << Count1 << endl;
 system("pause");
 return 0;
}