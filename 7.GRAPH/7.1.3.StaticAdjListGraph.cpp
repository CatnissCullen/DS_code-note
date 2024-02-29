/*静态邻接表（树/无向图/有向图，顶点值有序<若无序需要自己映射成有序数值，用来在数组中代替顶点实际值）*/
# include <iostream>
# include <map>
using namespace std;
# define ElemType int
# define N 100010
# define M 2*N//有向图边数最多为点数的两倍
typedef struct{
    ElemType dta;
    int nxt;
}TlNode;//邻接链表结点（尾顶点）
map<ElemType,int> fstTail;//fstTail[data]=i：值为data的顶点的边表中，首出边为第 i 条边
TlNode tlLists[M];
int idx;
int n,m;//顶点数，边数
map<ElemType,bool> flag;//DFS辅助数组，标记是否已遍历过
ElemType qB[M];//BFS辅助队列
map<ElemType,int> d;//BFS辅助数组，记录顶点到各自起点的步数，可以当flg用
ElemType qT[M];//拓扑排序辅助队列
map<ElemType,int> in;//拓扑排序辅助数组，记录入度（模拟删除）
int f,r;
void AddEdge(ElemType dt1,ElemType dt2);
void DFS(ElemType hdDta);
void BFS(ElemType stDta);
bool TopologicalSort();
int main(){
    int a,b;
    cin>>n>>m;

    for(ElemType e=1;e<=n;++e) { fstTail[e]=-1; in[e]=0; }//一般点的数据值是有序的，若无序一定会先列出全部顶点数据，先一次性初始化fstEdge和in，
    //不能一边读入边一边添加map<ElemType,int>，因为有可能有孤立点，添加边时添加不到顶点；
    //而若不存储孤立点到fstEdge和in，则拓扑排序（无环图拓扑序列需要输出包括孤立点的完整顶点序列）求解时孤立点无法顺利入队出队，
    //最终队列数组中顶点不满n个，尾指针移不到n-1，会按有环图输出-1！若存储了孤立点，由于孤立点入度为0，指向-1，所以会优先入队优先输出
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        AddEdge(a,b);
//		AddEdge(b,a); //无向图需要对称地加两条边
    }

    for(ElemType st=1;st<=n;++st)//或者遍历有序字母 
        if(flag.find(st)==flag.end()) DFS(st);//深度优先遍历

    for(ElemType st=1;st<=n;++st)//或者遍历有序字母
        if(in.find(st)==in.end()) BFS(st);//广度优先遍历

    if(!TopologicalSort()) cout<<-1;//有环图：打印-1
    else for(int i=0;i<n;++i) printf("%d ",qT[i]);//无环图：打印拓扑序列
}
void AddEdge(ElemType dt1,ElemType dt2){
    tlLists[idx].dta=dt2;//读入第idx条边的尾顶点数据（tlLists中的dt2可能出现多次，是多条边的尾顶点）
    tlLists[idx].nxt=fstTail[dt1]; fstTail[dt1]=idx;//边dt1->dt2以头插法入头顶点的出边表
    ++in[dt2];//尾顶点入度增一
    ++idx;
}
void DFS(ElemType hdDta){
    flag[hdDta]=true;
    printf("%d ",hdDta);
    for(int j=fstTail[hdDta]; j!=-1; j=tlLists[j].nxt){
        int tlDta=tlLists[j].dta;
        if(flag.find(tlDta)==flag.end()) DFS(tlDta);
    }
}
void BFS(ElemType stDta){
    f=0,r=-1;
    qB[++r]=stDta;
    d[stDta]=0;
    while(f<=r){
        ElemType hdDta=qB[f++];
        printf("%d ",hdDta);
        for(int j=fstTail[hdDta]; j!=-1; j=tlLists[j].nxt){
            ElemType tlDta=tlLists[j].dta;
            if(d.find(tlDta)==d.end()){
                d[tlDta]=d[hdDta]+1;
                qB[++r]=tlDta;
            }
        }
    }
}
bool TopologicalSort(){
    f=0,r=-1;
    for(pair<ElemType,int> it:in)
        if(!it.second) qT[++r]=it.first;
    while(f<=r){
        ElemType hdDta=qT[f++];
        for(int i=fstTail[hdDta]; i!=-1; i=tlLists[i].nxt){
            ElemType tlDta=tlLists[i].dta;
            --in[tlDta];
            if(!in[tlDta]) qT[++r]=tlDta;
        }
    }
    return r==n-1;
}
