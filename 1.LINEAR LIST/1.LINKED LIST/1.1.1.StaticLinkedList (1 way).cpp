# include <iostream>
using namespace std;
# define ElemType int
# define N 100010
int head_I,idx;//idx��ʾ��ǰδʹ�õ���С����
ElemType val[N], next_I[N];//�����ѳ�ʼ��Ϊ0
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
        switch(op){//�����kָ�������������val�е�ʵ������Ϊk-1
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
    head_I=-1;//���ձ�־
    idx=0;
}
void AddNode_toHead(ElemType x){//ͷ�巨��ӽ��
    val[idx]=x;
    next_I[idx]=head_I, head_I=idx++;
}
void InsertNode_toKNext(int k,ElemType x){//�嵽����Ϊk�Ľ��󣨱��봫�뱻�������ǰһ����������ʱ�临�ӶȲ�Ϊ1��
    val[idx]=x;
    next_I[idx]=next_I[k], next_I[k]=idx++;
}
void DeleteNode_atKNext(int k){//ɾ������Ϊk�Ľ����һ��㣨���봫�뱻ɾ������ǰһ����������ʱ�临�ӶȲ�Ϊ1��
    if(k!=-1) next_I[k]=next_I[next_I[k]];//ɾ�����׽��������
    else head_I=next_I[head_I];//ɾ�����׽��
}
