# include <iostream>
using namespace std;
# define ElemType int
# define N 100010
# define head_I 0
# define tail_I 1
int idx;//idx表示当前未使用的最小索引
ElemType val[N],pre_I[N],next_I[N];//数组已初始化为0
void InitializeLinkedList();
void InsertNode_toKNext(int k,ElemType x);
void InsertNode_toKPre(int k,ElemType x);
void DeleteNode_atK(int k);
int main(){
    InitializeLinkedList();
    int m; cin>>m;
    while(m--){
        int k,x; char op;
        cin>>op;
        switch(op){//读入的k指结点插入次序，其在val中的实际索引为k+1
            case 'L':
                cin>>x;
                InsertNode_toKNext(0,x);
                break;
            case 'R':
                cin>>x;
                InsertNode_toKPre(1,x);
                break;
            case 'D':
                cin>>k;
                DeleteNode_atK(k+1);
                break;
            case 'I':
                cin>>op>>k>>x;
                if(op=='L') InsertNode_toKPre(k+1,x);
                else InsertNode_toKNext(k+1,x);
                break;
        }
    }
    int i=next_I[0];
    while(i!=1){
        cout<<val[i]<<" "; i=next_I[i];
    }
}
void InitializeLinkedList(){
    next_I[head_I]=tail_I, pre_I[tail_I]=head_I;
    idx=2;
}
//void AddNode_toHead(ElemType x){//头插法添加结点（已有头结点，可与一般的插入结点合并）
//    val[idx]=x;
//    next_I[idx]=first_I, first_I=idx++;
//}
void InsertNode_toKNext(int k,ElemType x){//插到索引为k的结点后
    val[idx]=x;
    next_I[idx]=next_I[k], next_I[k]=idx;
    pre_I[idx]=k, pre_I[next_I[idx]]=idx;
    ++idx;
}
void InsertNode_toKPre(int k,ElemType x){//插到索引为k的结点前
    val[idx]=x;
    pre_I[idx]=pre_I[k], pre_I[k]=idx;
    next_I[idx]=k, next_I[pre_I[idx]]=idx;
    ++idx;
}
void DeleteNode_atK(int k){//删除索引为k的结点
    next_I[pre_I[k]]=next_I[k];
    pre_I[next_I[k]]=pre_I[k];
}
