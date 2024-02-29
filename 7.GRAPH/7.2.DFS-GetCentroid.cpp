/*树的重心：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。
求重心对应的连通块中点数的最大值*/
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
int minRes;//最小的连通块最大点数（最终结果），设为全局变量方便每次DFS递归都可以更新到
map<ElemType,bool> flag;//记录是否已遍历过（未遍历过的flag不存在）
void AddEdge(ElemType dt1,ElemType dt2);
int DFS(ElemType hdData);
int main(){
    int a,b;
    cin>>n; m=n-1;
    minRes=n;//初始化miRes为总顶点数
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        AddEdge(a,b);//无向图需要对称地加两条边
        AddEdge(b,a);
    }
    ElemType st=1;//根据输入的数据任意设置一个遍历起点
    DFS(1);//main函数中不需要DFS的返回结果。因为返回的是sum
    cout<<minRes;//深度优先遍历求最小的 连通块最大顶点数
}
void AddEdge(ElemType dt1,ElemType dt2){
    if(fstEdge.find(dt1)==fstEdge.end()) fstEdge[dt1]=-1;//若头顶点第一次出现，初始化fstEdge为-1
    edTails[idx]=dt2;//读入尾顶点数据
    nxtEdge[idx]=fstEdge[dt1]; fstEdge[dt1]=idx;//边dt1->dt2以头插法入头顶点的出边表
    ++idx;
}
int  DFS(ElemType hdData){//返回以hdData为根的子树中的顶点数
    flag[hdData]=true;
    int sum=1;//子树总顶点数
    int res=0;//删除该根结点后，每个连通块的顶点数，不断更新最终得到最大值
    for(int j=fstEdge[hdData];j!=-1;j=nxtEdge[j]){//循环遍历根结点的所有尾顶点，求它们所在连通块的顶点数
        int tlData=edTails[j];
        if(flag.find(tlData)==flag.end()){
            int tRes=DFS(tlData);//递归得到当前尾顶点伸出的连通块上的总顶点数，
            // 一个“连通块”即从尾顶点开始的一条深搜支路（以尾顶点为根结点的子树）
            if(tRes>res) res=tRes;//回到头顶点递归层，判断：若当前尾顶点所在连通块的顶点数>res，则更新res
            sum+=tRes;//更新子树总顶点数
        }
    }//得到各尾顶点所在连通块顶点数中的最大值
    int tRes=n-sum;//再求当前子树根结点删除后，其顶上的连通块顶点数（即总树除去当前子树的部分）
    if(tRes>res) res=tRes;
    if(res<minRes) minRes=res;//每层递归最后将最大顶点数与当前minRes比较，更新minRes为更小的最大顶点数
    return sum;
}
