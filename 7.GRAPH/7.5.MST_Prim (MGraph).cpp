/*邻接矩阵朴素Prim*/
//只存储从1-n的有序数值，既是顶点编号（不是读入顺序）也是顶点数值，若顶点数值不是1-n，需要再开别的数组建立映射关系
# include<iostream>
# include<cstring>
# include <algorithm>
# define N 501
# define INF 0x3f3f3f3f
using namespace std;
# define WghType int
typedef struct{
    int n;
    int m;
    WghType edges[N][N];
}MGraph;
MGraph G;
int d[N];//d[i]=length —— i 号点到子生成树的距离
int flg[N];//flg[i]=1 —— i 号点已在子生成树中（否则为0）
int tLen;
void AddEdges(int hd, int tl, WghType w);
void Prim();
int main(){
    cin>>G.n>>G.m;
    memset(G.edges,0x3f,sizeof(G.edges));
    for(int i=1;i<=G.n;++i) G.edges[i][i]=0;//对角线赋为0
    int a,b,w;
    for(int i=1;i<=G.m;i++){
        cin>>a>>b>>w;
//     GetIndex(a,b);     //具象顶点抽象成顶点编号
        AddEdges(a,b,w);
        AddEdges(b,a,w);   //无向图
    }
    Prim();
    if(tLen==INF) cout<<"impossible";
    else cout<<tLen;
}
void AddEdges(int hd, int tl, WghType w){
    G.edges[hd][tl]=min(G.edges[hd][tl],w); //若有重边，只保留最短边
}
void Prim(){
    memset(d,0x3f,sizeof d);//初始化所有d为无穷大 
    d[1]=0;//起点设为点1，到子生成树距离设为0
    for(int k=1;k<=G.n;++k){//n次遍历，找完起点到n个点的最短路
        int t=-1;
        for(int i=1;i<=G.n;++i)
            if(!flg[i]&&(t==-1||d[i]<d[t])) t=i;
		if(d[t]!=INF) tLen+=d[t];
		else{ tLen=INF; return; }
		flg[t]=1; 
        for(int j=1;j<=G.n;++j)//必须先加tLen再更新！（因为若有自环会更新到自己，但生成树应无环） 
            d[j]=min(d[j],G.edges[t][j]);//这一步在整个外循环中的时间复杂度其实是m（也即n^2，稠密图的m和n^2是同一级别），因为G.edges[t]会遍历所有边；
    }
}
