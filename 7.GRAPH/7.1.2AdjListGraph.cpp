/*邻接表深度优先遍历、广度优先遍历、拓扑排序*/
# include<iostream>
# include<map>
# include<cstring>
# define N 1000
# define null 0x3f3f3f3f
using namespace std;
# define WghType int
# define ElemType int
typedef struct edge{//出边表结点
    ElemType tlDta;
    WghType w;
    struct edge* nxtEdge;
}Edge;
typedef struct{
    int n;
    int m;
    map<ElemType,Edge*> fstEdge;//出边表首出边集
}LGraph;
LGraph G;
map<ElemType,int> flg;//DFS辅助数组，标记是否已遍历过
ElemType qB[N];//BFS辅助队列
map<ElemType,int> d;//BFS辅助数组，记录顶点到各自起点的步数，可以当flg用
ElemType qT[N];//拓扑排序辅助队列
map<ElemType,int> in;//拓扑排序辅助数组，记录入度（模拟删除）
void AddEdge(ElemType hdDta, ElemType tlDta,WghType w);
void DFS(ElemType hdDta);
void BFS(ElemType stDta);
bool TopologicalSort();
int main(){
    cin>>G.n>>G.m;
    for(ElemType e=1;e<=G.n;++e){ G.fstEdge[e]=NULL; in[e]=0; }
    int a,b,w;
    for(int i=1;i<=G.m;++i){
        scanf("%d%d%d",&a,&b,&w);
        AddEdge(a,b,w);
    }
    for(ElemType e=1;e<=G.n;++e)//深度优先遍历
        if(flg.find(e)==flg.end()) DFS(e);
    cout<<endl;
    for(ElemType e=1;e<=G.n;++e)//广度优先遍历
        if(d.find(e)==d.end()) BFS(e);
    cout<<endl;
    if(TopologicalSort()) for(int i=0;i<G.n;++i) printf("%d ",qT[i]);//拓扑排序
    else cout<<-1;
}
void AddEdge(ElemType hdDta, ElemType tlDta,WghType w){
    Edge* edge=new Edge[1];
    edge->tlDta=tlDta; edge->w;
    edge->nxtEdge=G.fstEdge[hdDta]; G.fstEdge[hdDta]=edge;//头插法
    ++in[tlDta];//尾顶点入度增一
}
void DFS(ElemType hdDta){
    flg[hdDta]=1;
    printf("%d ",hdDta);
    Edge* p=G.fstEdge[hdDta];
    while(p!=NULL){
        if(flg.find(p->tlDta)==flg.end()) DFS(p->tlDta);
        p=p->nxtEdge;
    }
}
void BFS(ElemType stDta){
    int f=0,r=-1;
    qB[++r]=stDta;
    d[stDta]=0;
    while(f<=r){
        ElemType hdDta=qB[f++];
        printf("%d ",hdDta);
        Edge* p=G.fstEdge[hdDta];
        while(p!=NULL&&d.find(p->tlDta)==d.end()){
            qB[++r]=p->tlDta;
            d[p->tlDta]=d[hdDta]+1;
            p=p->nxtEdge;
        }
    }
}
bool TopologicalSort(){
    int f=0,r=-1;
    for(pair<ElemType,int> it:in)
        if(it.second==0) qT[++r]=it.first;
    while(f<=r){
        ElemType hdDta=qT[f++];
        Edge* p=G.fstEdge[hdDta];
        while(p!=NULL){
            --in[p->tlDta];
            if(!in[p->tlDta]) qT[++r]=p->tlDta;
            p=p->nxtEdge;
        }
    }
    return r==G.n-1;
}
