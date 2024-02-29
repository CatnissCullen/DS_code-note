# include <iostream>
using namespace std;
# define ElemType int
# define N 100010
ElemType stack[N],nums[N];
int top;
void InitializeStack();
void PushNode(int x);
void PopNode();
bool Empty();
int Query();
int main(){
    InitializeStack();
    int m,x,i;
    cin>>m;
    for(i=0;i<m;++i) scanf("%d",&nums[i]);
    for(i=0;i<m;++i){
        while(top>-1&&Query()>=nums[i]) PopNode();
        if(!Empty()) printf("%d ",Query());
        else printf("-1 ");
        PushNode(nums[i]);
    }
}
void InitializeStack(){
    top=-1;//’ªø’±Í÷æ
}
void PushNode(ElemType x){
    stack[++top]=x;
}
void PopNode(){
    --top;
}
bool Empty(){
    return top==-1;
}
int Query(){
    return stack[top];
}
