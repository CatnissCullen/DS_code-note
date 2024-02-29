/*静态邻接表Kruskal*/
# include <iostream>
# include <cstring>
# include <algorithm>
using namespace std;
# define ElemType int
# define WghType int
# define N 100010
# define M 2*N//无向图（允许自环）边数最多为点数的两倍-1
typedef struct{
	ElemType a,b;
	WghType w;
}Edge;
Edge edges[M];//边集数组 
int rts[N];//辅助并查集 
int tLen;
int cntEd;//记录当前已加入的边数 
int n,m; 
void Kruskal();
int main(){
    cin>>n>>m;
    for(int i=0;i<m;++i) scanf("%d%d%d",&edges[i].a,&edges[i].b,&edges[i].w);  
    Kruskal();
    if(cntEd<n-1) cout<<"impossible";
    else cout<<tLen;
}
bool CmpWeight(Edge a,Edge b){
	return a.w < b.w;
}
ElemType FindRoot(ElemType x){//借并查集查找顶点x所在子连通块的根结点（判断所在子连通块的标志） 
	if(rts[x]!=x) rts[x]=FindRoot(rts[x]);
	return rts[x];//【递归的路径压缩法】
}//不用递归且无路径压缩（详见Typora笔记）可能会超时
void Kruskal(){
	sort(edges,edges+m,CmpWeight);//对权值从小到大排序 
	for(int i=1;i<=n;++i) rts[i]=i;//初始化并查集
	for(int i=0;i<m;++i){//从小到大遍历权值有序的边集 
		ElemType rt1=FindRoot(edges[i].a), rt2=FindRoot(edges[i].b);
		if(rt1!=rt2){
			rts[rt1]=rt2;
			tLen+=edges[i].w; ++cntEd;
		}
	}
}

