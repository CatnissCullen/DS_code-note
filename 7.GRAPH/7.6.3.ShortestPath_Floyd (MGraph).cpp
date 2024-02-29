/*邻接矩阵Floyd（允许负边权，但不能有负权回路）*/
//只存储从1-n的有序数值，既是顶点编号（不是读入顺序）也是顶点数值，若顶点数值不是1-n，需要再开别的数组建立映射关系
# include<iostream>
# include<cstring>
# include <algorithm>
# define N 210
# define INF 0x3f3f3f3f
using namespace std;
# define WghType int
typedef struct{
    int n;
    int m;
    WghType edges[N][N];
}MGraph;
MGraph G;
void AddEdges(int hd, int tl, WghType w);
void Floyd();
int main(){
    int r;
    cin>>G.n>>G.m>>r;
    memset(G.edges,0x3f,sizeof(G.edges));
    for(int i=1;i<=G.n;++i) G.edges[i][i]=0;//对角线赋为0
    int a,b,w;
    for(int i=1;i<=G.m;i++){
        cin>>a>>b>>w;
//     GetIndex(a,b);     //具象顶点抽象成顶点编号
        AddEdges(a,b,w);
//     AddEdges(b,a);   //无向图
    }
    Floyd();
    while(r--){
        cin>>a>>b;
        if(G.edges[a][b]>INF/2) cout<<"impossible"<<endl;//（==INF不准确！因为有负边权，导致非通路稍小于INF，可以限制为超过INF/2）
        else cout<<G.edges[a][b]<<endl;
    }
}
void AddEdges(int hd, int tl, WghType w){
    G.edges[hd][tl]=min(G.edges[hd][tl],w); //若有重边，只保留最短边
}
void Floyd(){//原地将邻接矩阵变为最短路径矩阵
    for(int k=1;k<=G.n;++k)//k为从i到j的中介点（必须把k放在最外层循环）
        for(int i=1;i<=G.n;++i)
            for(int j=1;j<=G.n;++j)
                G.edges[i][j]=min(G.edges[i][j],G.edges[i][k]+G.edges[k][j]);//不断求从各i途经各k到各j的最短路
}
