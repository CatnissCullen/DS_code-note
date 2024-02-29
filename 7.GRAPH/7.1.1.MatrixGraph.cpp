/*邻接矩阵深度优先遍历和广度优先遍历*/
//只存储从1-n的有序数值，既是顶点编号（不是读入顺序）也是顶点数值，若顶点数值不是1-n，需要再开别的数组建立映射关系
# include<iostream>
# include<map>
# include<cstring>
# define N 510//矩阵一维长度不能多开太多，平方后内存会溢出 
# define null 0x3f3f3f3f
using namespace std;
# define WghType int
typedef struct{
    int n;
    int m;
    WghType edges[N][N];
}MGraph;
MGraph G;
map<int,int> flg;//DFS辅助数组，标记是否已遍历过
int qu[N];//BFS辅助队列
map<int,int> d;//BFS辅助数组，记录顶点到各自起点的步数，可以当flg用，未遍历过则d不存在（用map无需初始化）
void AddEdges(int hd, int tl, WghType w);
void DFS(int hd);
void BFS(int st);
int main(){
    cin>>G.n>>G.m;
    memset(G.edges,0x3f,sizeof(G.edges));
    for(int i=1;i<=G.n;++i) G.edges[i][i]=0;//对角线赋为0
    int a,b,w;
    for(int i=1;i<=G.m;i++){
        cin>>a>>b>>w;
//     GetIndex(a,b);
        AddEdges(a,b,w);
//     AddEdges(b,a);   //无向图
    }
    for(int st=1;st<=G.n;++st)
        if(flg.find(st)==flg.end()) DFS(st);
    cout<<endl;
    for(int st=1;st<=G.n;++st)
        if(d.find(st)==d.end()) BFS(st);
}
void AddEdges(int hd, int tl, WghType w){
    G.edges[hd][tl]=w;//不考虑重边 
}
void DFS(int hd){
    flg[hd]=1;
    printf("%d ",hd);
    for(int tl=1;tl<=G.n;++tl)
        if(G.edges[hd][tl]!=null&&flg.find(tl)==flg.end())//遍历hd的未遍历尾顶点
            DFS(tl);
}
void BFS(int st){
    int f=0,r=-1;
    d[st]=0;
    qu[++r]=st;
    while(f<=r){
        int hd=qu[f++];
        printf("%d ",hd);
        for(int tl=1;tl<=G.n;++tl)
            if(G.edges[hd][tl]!=null&&d.find(tl)==d.end()){//遍历hd的未遍历尾顶点
                d[tl]=d[hd]+1;
                qu[++r]=tl;
            }
    }
}
