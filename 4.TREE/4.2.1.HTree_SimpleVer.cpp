# include <iostream>
# include <algorithm>
# define N 30
# define INF 0x3f3f3f3f
using namespace std;
typedef struct{
	int i,w;
}node;
node nd[2*N-1];
int W[N];
int p[2*N-1];
int n;
int idx;
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	cin>>n;
	int x;
	for(int i=0;i<n;++i){
		cin>>x;
		nd[i]={i,x}; W[i]=x;
	}
	idx=n;
	while(idx<2*n-1){
		sort(nd,nd+idx,cmp);
		nd[idx].w=nd[0].w+nd[1].w;
		nd[idx].i=idx;
		nd[0].w=nd[1].w=INF;
		p[nd[0].i]=p[nd[1].i]=idx;
		++idx;
	}
	int L=0;
	for(int i=0;i<n;++i){
		int j=p[i],l=1;
		while(p[j]){
			j=p[j]; ++l;
		}
		L+=W[i]*l;
	}
	cout<<L;
}
