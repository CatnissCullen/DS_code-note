/*邻接矩阵朴素Dijkstra*/
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
int d[N];//d[i]=length —— i 号点到起点的距离
int flg[N];//flg[i]=1 —— i 号点（终点）到起点的距离已确定（否则为0）
void AddEdges(int hd, int tl, WghType w);
void Dijkstra(int st);
int main(){
    cin>>G.n>>G.m;
    memset(G.edges,0x3f,sizeof(G.edges));
    for(int i=1;i<=G.n;++i) G.edges[i][i]=0;//对角线赋为0
    int a,b,w;
    for(int i=1;i<=G.m;i++){
        cin>>a>>b>>w;
//     GetIndex(a,b);     //具象顶点抽象成顶点编号
        AddEdges(a,b,w);
//     AddEdges(b,a);   //无向图
    }
    Dijkstra(1);
//    int ed; cin>>ed;//读入终点
    if(d[G.n]==INF) cout<<-1;//若求完所有最短路，d[ed]仍是无穷大，说明起点到该终点不连通
    else cout<<d[G.n];
}
void AddEdges(int hd, int tl, WghType w){
    G.edges[hd][tl]=min(G.edges[hd][tl],w); //若有重边，只保留最短边
}
void Dijkstra(int st){
    memset(d,0x3f,sizeof d);//初始化所有d为无穷大 
    d[st]=0;//起点到起点距离设为0
    for(int k=1;k<=G.n;++k){//n次遍历，找完起点到n个点的最短路
        int t=-1;
        for(int i=1;i<=G.n;++i)
            if(!flg[i]&&(t==-1||d[i]<d[t])) t=i;
        flg[t]=1;
        for(int j=1;j<=G.n;++j)
            d[j]=min(d[j],d[t]+G.edges[t][j]);
    }
}
