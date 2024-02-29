# include <iostream>
using namespace std;
# define ElemType int
# define N 100010
# define head_I 0
# define tail_I 1
int stack[N],top;
void InitializeStack();
void PushNode(ElemType x);
void PopNode();
void Empty();
void Query();
int main(){
    InitializeStack();
    int m,x; string op;
    cin>>m;
    while(m--){
        cin>>op;
        if(equal(op.begin(),op.end(),"push")){ cin>>x; PushNode(x); }
        else if(equal(op.begin(),op.end(),"pop")) PopNode();
        else if(equal(op.begin(),op.end(),"empty")) Empty();
        else if(equal(op.begin(),op.end(),"query")) Query();
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
void Empty(){
    if(top==-1) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
}
void Query(){
    cout<<stack[top]<<endl;
}
