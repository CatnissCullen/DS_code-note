/*求1号点到n号点的最短距离（无权有向图），无法走到则输出-1*/
# include <iostream>
# include <map>
using namespace std;
# define ElemType int
# define N 100010
# define M 2*N//有向图边数最多为点数的两倍
map<ElemType,int> fstEdge;//fstEdge[data]=i：值为data的顶点的边表中，首出边为第 i 条边
int nxtEdge[M];//nxtEdge[i]=j：在第 i 条边头顶点的出边表中，下一条边为第 j 条边
ElemType edTails[M];//edTails[j]=data：第 j 条边尾顶点的数据
int idx;
int n,m;//顶点数，边数
map<ElemType,bool> flag;//记录是否已遍历过（未遍历过的flag不存在）
ElemType qu[M];//BFS辅助队列
map<ElemType,int> d;//各点到起点的距离
int f=0,r=-1;
void AddEdge(ElemType dt1,ElemType dt2);
void BFS(ElemType stData);
int main(){
    int a,b;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        AddEdge(a,b);
    }
    ElemType st=1;//根据输入的头顶点数据任意设置一个遍历起点（必须是头顶点）
    BFS(st);//深度优先遍历
    if(d.find(n)!=d.end()) cout<<d[n];
    else cout<<-1;
}
void AddEdge(ElemType dt1,ElemType dt2){
    if(fstEdge.find(dt1)==fstEdge.end()) fstEdge[dt1]=-1;//若头顶点第一次出现，初始化fstEdge为-1
    edTails[idx]=dt2;//读入尾顶点数据
    nxtEdge[idx]=fstEdge[dt1]; fstEdge[dt1]=idx;//边dt1->dt2以头插法入头顶点的出边表
    ++idx;
}
void BFS(ElemType stData){
    qu[++r]=stData;
    d[stData]=0;//起点到本身的距离为0
    while(f<=r){
        ElemType hdData=qu[f++];//取出队头
        for(int j=fstEdge[hdData];j!=-1;j=nxtEdge[j]){//遍历队头各尾顶点
            ElemType tlData=edTails[j];
            if(d.find(tlData)==d.end()){//若队头当前尾顶点未被遍历过
                d[tlData]=d[hdData]+1;//更新队头尾顶点到起点的距离
                qu[++r]=tlData;//尾顶点入队
            }
        }
    }
}
