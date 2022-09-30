
#include<bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef double db;

char now[2][5]={" /\\ ","/__\\"};
char map1[3000][3000];
void draw(int u,int d,int l,int r,int n)
{
	if(n==1)
	{
		for(int i=0;i<2;i++)
		for(int j=0;j<4;j++)
		map1[u+i][l+j]=now[i][j];
		return ;
	}
	int md=u+d>>1,mr=l+r>>1;
	int mk1=l+mr>>1,mk2=r+mr>>1;
	draw(u,md,mk1,mk2,n-1);
	draw(md,d,l,mr,n-1);
	draw(md,d,mr,r,n-1);
	return ;
}

int main()
{
	int i,j,n,a,b,c,d;
	cin>>n;
	a=0; b=1<<n; c=0; d=2<<n;
	draw(a,b,c,d,n);
	for(i=a;i<b;i++)
	{
		for(j=c;j<d;j++)
		{
			if(!map1[i][j]) cout<<' ';
			else cout<<map1[i][j];
		}
		cout<<endl;
	}
    return 0;
}