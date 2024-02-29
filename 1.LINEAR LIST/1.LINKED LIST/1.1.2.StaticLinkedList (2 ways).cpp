# include <iostream>
using namespace std;
# define ElemType int
# define N 100010
# define head_I 0
# define tail_I 1
int idx;//idx��ʾ��ǰδʹ�õ���С����
ElemType val[N],pre_I[N],next_I[N];//�����ѳ�ʼ��Ϊ0
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
        switch(op){//�����kָ�������������val�е�ʵ������Ϊk+1
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
//void AddNode_toHead(ElemType x){//ͷ�巨��ӽ�㣨����ͷ��㣬����һ��Ĳ�����ϲ���
//    val[idx]=x;
//    next_I[idx]=first_I, first_I=idx++;
//}
void InsertNode_toKNext(int k,ElemType x){//�嵽����Ϊk�Ľ���
    val[idx]=x;
    next_I[idx]=next_I[k], next_I[k]=idx;
    pre_I[idx]=k, pre_I[next_I[idx]]=idx;
    ++idx;
}
void InsertNode_toKPre(int k,ElemType x){//�嵽����Ϊk�Ľ��ǰ
    val[idx]=x;
    pre_I[idx]=pre_I[k], pre_I[k]=idx;
    next_I[idx]=k, next_I[pre_I[idx]]=idx;
    ++idx;
}
void DeleteNode_atK(int k){//ɾ������Ϊk�Ľ��
    next_I[pre_I[k]]=next_I[k];
    pre_I[next_I[k]]=pre_I[k];
}
