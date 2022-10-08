#include<bits/stdc++.h>
using namespace std;

const int M = 1000; //身上带的最多的钱
int C[800],V[800],K[800];
int F[801][3001], G[801][3001];

int main(){
	int N;
	scanf("%d",&N);
	for(int i=1; i<=N; ++i) scanf("%d%d%d",&C[i], &V[i], &K[i]);
	
	//正序购买商品 
	memset(F, 0, sizeof(F));
	for(int i=1; i<=N; ++i){ //考虑第i个商品 
		for(int k=0; k<=K[i]; ++k){   //第i个商品考虑买k个 
			for(int c=k*C[i]; c<=M; ++c){  //买该商品花费的钱 
				F[i][c] = max(F[i][c], F[i-1][c-k*C[i]]+k*V[i]); //产生的最大收益 
			}
		}
		for(int c=1; c<=M; ++c) F[i][c] = max(F[i][c], F[i][c-1]); //更新
	}
	
	//反序购买商品 
	memset(G, 0, sizeof(G));
	for(int i=N; i>0; --i){ //考虑第i个商品 
		for(int k=0; k<=K[i]; ++k){   //第i个商品考虑买k个 
			for(int c=k*C[i]; c<=M; ++c){  //买该商品花费的钱 
				G[i][c] = max(G[i][c], G[i+1][c-k*C[i]]+k*V[i]); //产生的最大收益 
			}
		}
		for(int c=1; c<=M; ++c) G[i][c] = max(G[i][c], G[i][c-1]); //更新 
	}

	int Q,x,y;
	scanf("%d",&Q);
	while(Q--){
		scanf("%d%d",&x, &y); 
		++y;  //因为商品编号从0开始 
		
		int ans=0;
		for(int c=0; c<=x; ++c){
			ans = max(ans, F[y-1][c]+G[y+1][x-c]); //第y个商品禁买，花费c买前y-1个商品，花费x-c买后y+1个商品 
		}	
		printf("%d\n",ans);
	}
	return 0;
}

// for (int i = 1; i <= n; i++) {
//     int num = min(p[i], V / c[i]); // V/c[i]是最多能放多少个进去，优化上界
//     for (int k = 1; num > 0; k <<= 1) { //这里的k就相当于上面例子中的1,2,4,6
//         if (k > num) k = num;
//         num -= k;
//         for (int j = V; j >= c[i] * k; j--) // 01背包
//             f[j] = max(f[j], f[j - c[i] * k] + w[i] * k);
//     }
// }
