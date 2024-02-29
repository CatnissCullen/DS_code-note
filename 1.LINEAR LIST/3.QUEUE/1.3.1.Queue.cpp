# include <iostream>
using namespace std;
# define ElemType int
# define N 100010
int queue[N],front,rear;
void InitializeQueue();
void PushNode(int x);
void PopNode();
void Empty();
void Query();
int main(){
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
void InitializeQueue(){
    front=rear=0;
}
void PushNode(int x){
    queue[rear++]=x;
}
void PopNode(){
    ++front;
}
void Empty(){
    if(front==rear) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
}
void Query(){
    cout<<queue[front]<<endl;
}
