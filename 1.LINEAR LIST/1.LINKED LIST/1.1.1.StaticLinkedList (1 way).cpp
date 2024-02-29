# include <iostream>
using namespace std;
# define ElemType int
# define N 100010
int head_I,idx;//idx表示当前未使用的最小索引
ElemType val[N], next_I[N];//数组已初始化为0
void InitializeLinkedList();
void AddNode_toHead(ElemType x);
void InsertNode_toKNext(int k,ElemType x);
void DeleteNode_atKNext(int k);
int main(){
    InitializeLinkedList();
    int m; cin>>m;
    while(m--){
        int k,x; char op;
        cin>>op;
        switch(op){//读入的k指结点插入次序，其在val中的实际索引为k-1
            case 'H':
                cin>>x; AddNode_toHead(x); break;
            case 'D':
                cin>>k;
                DeleteNode_atKNext(k-1); break;
            case 'I':
                cin>>k>>x; InsertNode_toKNext(k-1,x); break;
        }
    }
    int i=head_I;
    while(i!=-1){
        cout<<val[i]<<" "; i=next_I[i];
    }
}
void InitializeLinkedList(){
    head_I=-1;//链空标志
    idx=0;
}
void AddNode_toHead(ElemType x){//头插法添加结点
    val[idx]=x;
    next_I[idx]=head_I, head_I=idx++;
}
void InsertNode_toKNext(int k,ElemType x){//插到索引为k的结点后（必须传入被插入结点的前一索引，否则时间复杂度不为1）
    val[idx]=x;
    next_I[idx]=next_I[k], next_I[k]=idx++;
}
void DeleteNode_atKNext(int k){//删除索引为k的结点下一结点（必须传入被删除结点的前一索引，否则时间复杂度不为1）
    if(k!=-1) next_I[k]=next_I[next_I[k]];//删除链首结点以外结点
    else head_I=next_I[head_I];//删除链首结点
}
