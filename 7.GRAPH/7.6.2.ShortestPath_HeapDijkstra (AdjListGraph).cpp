/*静态邻接表堆优化Dijkstra*/
# include <iostream>
# include <cstring>
# include <algorithm>
# include <queue>
using namespace std;
# define ElemType int
# define WghType int
# define N 100010
# define M 2*N//有向图边数最多为点数的两倍
# define INF 0x3f3f3f3f
typedef pair<int,int> Pair;//终点号和路径权值的数对 {di, i} ，用于建堆
typedef struct{
    ElemType dta;
    WghType w;//求最短路需要权值，加上
    int nxt;
}TlNode;//邻接链表结点（尾顶点）
int fstTail[N];//fstTail[data]=i：值为dta的顶点的边表中，首出边为第 i 条边
TlNode tlLists[M];
int idx;
int n,m;//顶点数，边数
int d[N];//d[i]=length —— i 号点到起点的距离
int flg[N];//flg[i]=1 —— i 号点（终点）到起点的距离已确定（否则为0）
void AddEdge(ElemType dt1,ElemType dt2,WghType w);
void Dijkstra(int st);
int main(){
    cin>>n>>m;
    memset(fstTail,-1,sizeof fstTail);
    int a,b,w;
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&a,&b,&w);
        AddEdge(a,b,w);
//		AddEdge(b,a); //无向图需要对称地加两条边
    }
    Dijkstra(1);
    if(d[n]==INF) cout<<-1;//若求完所有最短路，d[ed]仍是无穷大，说明起点到该终点不连通
    else cout<<d[n];
}
void AddEdge(ElemType dt1,ElemType dt2,WghType w){
    tlLists[idx].dta=dt2, tlLists[idx].w=w;//读入第idx条边的尾顶点数据和边权（tlLists中的dt2可能出现多次，是多条边的尾顶点）
    tlLists[idx].nxt=fstTail[dt1]; fstTail[dt1]=idx;//边dt1->dt2以头插法入头顶点的出边表
    ++idx;
}
void Dijkstra(int st){
    memset(d,0x3f,sizeof d);//初始化d
    d[st]=0;//起点到起点距离设为0
    priority_queue<Pair,vector<Pair>,greater<Pair>> heap;//辅助堆
    heap.push({0,1});
    while(heap.size()){
        auto t=heap.top();//默认a是小顶堆，按Pair的第一个参数（路径权值）排序
        heap.pop();
        int di=t.first, i=t.second;
        if(flg[i]) continue;//跳过已找到最短路的终点
        flg[i]=1;
        for(int p=fstTail[i]; p!=-1; p=tlLists[p].nxt){
            d[tlLists[p].dta]=min(d[tlLists[p].dta], di+tlLists[p].w);
            heap.push({d[tlLists[p].dta],tlLists[p].dta});
        }
    }
}

