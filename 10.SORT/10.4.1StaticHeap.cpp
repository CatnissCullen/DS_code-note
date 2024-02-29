# include <iostream>
# include <string.h>
# include <algorithm>
using namespace std;
# define N 100010
int heap[N],heapSize;//小顶堆；heap存结点值的层序遍历 
int nodeNums[N];//存放层序次序为i的元素的插入次序nodeNums[i]
int nodeIndexes[N];//存放第j个插入的元素在堆中的索引nodeIndexes[j]
void down(int k);//已知k处元素比上方元素都大，将其下沉归位 
void up(int k);//已知k处元素比下方元素都小，将其上浮归位 
void Swap(int a_index,int b_index);
int main(){
    int n,cnt=0;//cnt记录插入次序
    cin>>n;
    while(n--){
        char op[5];
        int j,x;
        scanf("%s",op);
        if(strcmp(op,"I")==0){
		//插入结点操作（原来为空堆，所有结点值为极大值，可设0x3f3f3f3f） 
		//【建有序堆（不同于堆排序！！堆排序是对乱堆的调整）】 
            scanf("%d",&x); ++heapSize; ++cnt;
            heap[heapSize]=x;//先放到堆尾
            nodeIndexes[cnt]=heapSize; nodeNums[heapSize]=cnt;
            up(heapSize);//往上浮
        }
        else if(strcmp(op,"PM")==0) printf("%d\n",heap[1]);//输出最小值操作
        else if(strcmp(op,"DM")==0){//删除最小值操作【维护堆（特指对有序堆的维护）】 
            Swap(1,heapSize);//先交换堆尾和堆顶（最小值）
            --heapSize;//删除堆尾
            down(1);//重新调整堆
        }
        else if(strcmp(op,"D")==0){//删除第j个插入的结点操作【维护堆（特指对有序堆的维护）】 
            scanf("%d",&j);
            int i=nodeIndexes[j];
            Swap(i,heapSize);//先交换堆尾和i
            --heapSize;//删除堆尾
            down(i); up(i);//i处为原堆尾元素，重新调整根为i号结点的子堆
        }
        else{//修改第j个插入的结点操作【维护堆（特指对有序堆的维护）】 
            scanf("%d%d",&j,&x);
            int i=nodeIndexes[j];
            heap[i]=x;
            down(i); up(i);//重新调整位置i
        }
    }
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
void up(int k){//已知k处元素比下方元素都小，将其上浮归位 
    if(k/2>0&&b[k]<b[k/2]){
        Swap(k,k/2);
        up(k/2);
    }
}
void Swap(int a_Index,int b_Index){//交换包括堆数组中结点索引交换、数据的索引交换、索引的数据交换 
    swap(heap[a_Index],heap[b_Index]);
    swap(nodeIndexes[nodeNums[a_Index]],nodeIndexes[nodeNums[b_Index]]);
    swap(nodeNums[a_Index],nodeNums[b_Index]);
}
