# include <iostream>
using namespace std;
# define N 100010
int heap[N],heapSize;//小顶堆；heap存结点值的层序遍历 
void down(int k);//已知k处元素比上方元素都大，将其下沉归位 
int main(){
    int n,m;
    cin>>n>>m; heapSize=n;
    for(int i=1;i<=n;++i) scanf("%d",&heap[i]);//从1起编号 
    //小顶堆排序 ——本质：从下往上，先铺最后一层，其所有元素小于下方元素（即假设为极大值，可设0x3f3f3f3f），
	//以后每铺一层就 down()一层，当前层所有元素均大于上方元素（即假设为极小值，可设-0x3f3f3f3f） ， 
	//为方便据层序取索引，从倒数第二层末端开始沿倒层序遍历并 down()结点，时间复杂度 O(n)
	//【乱堆有序化；也可以另开空堆数组用插入结点方法建堆】 
    for(int i=n/2;i>0;--i) down(i); 
    while(m--){//输出从小到大的堆排序序列
        printf("%d ",heap[1]);//先打印堆顶
        heap[1]=heap[heapSize]; --heapSize; down(1);//再删除堆顶并重新调整堆 【维护堆（特指对有序堆的维护）】 
    }
}
void Swap(int &a,int &b){
    a^=b; b^=a; a^=b;
}
void down(int k){//已知k处元素比上方元素都大，将其下沉归位 
    int t=k;
    //找到以k为根结点的最小子堆中（三个结点）值最小的结点（t号） 
    if(2*k<=heapSize&&heap[2*k]<heap[t]) t=2*k;
    if(2*k+1<=heapSize&&heap[2*k+1]<heap[t]) t=2*k+1;
    if(t!=k){ 
        Swap(k,t);//交换当前根（k号结点）与t号结点元素 
        down(t);//t号位元素有改动，则需重新调整以其为根的子堆
    }
}

