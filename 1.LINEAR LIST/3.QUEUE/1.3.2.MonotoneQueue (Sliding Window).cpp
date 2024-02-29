# include <iostream>
using namespace std;
# define N 1000010
int queue[N],front,rear,nums[N];
void InitializeQueue();
void PushNode(int x);
void PopNode_front();
void PopNode_rear();
bool Empty();
int Query_front();
int Query_rear();
int main(){
    int n,m,x,i;
    cin>>n>>m;
    for(i=0;i<n;++i) scanf("%d",&nums[i]);
    i=0;
    InitializeQueue();
    while(i<n){//最小值
        if(i>=m&&!Empty()&&queue[front]<i-m+1) PopNode_front();
        while(!Empty()&&nums[Query_rear()]>=nums[i]) PopNode_rear();
        PushNode(i);
        if(i>=m-1) printf("%d ", nums[Query_front()]);
        ++i;
    }
    cout<<endl;
    i=0;
    InitializeQueue();
    while(i<n){//最大值
        if(i>=m&&!Empty()&&queue[front]<i-m+1) PopNode_front();
        while(!Empty()&&nums[Query_rear()]<=nums[i]) PopNode_rear();
        PushNode(i);
        if(i>=m-1) printf("%d ", nums[Query_front()]);
        ++i;
    }
}
void InitializeQueue(){
    front=rear=0;
}
void PushNode(int x){
    queue[rear++]=x;
}
void PopNode_front(){
    ++front;
}
void PopNode_rear(){
    --rear;
}
bool Empty(){
    return front==rear;
}
int Query_front(){
    return queue[front];
}
int Query_rear(){
    return queue[rear-1];
}
