# include<iostream>
# include <stdlib.h>
# include <time.h>
# define LENGTH 1000000
using namespace std;
FILE* fp=fopen("intfile.dat","r+");
int Nums[LENGTH]; 
int tMerged[LENGTH]; //暂存递归归并结果的数组（无法在每次递归前新建，因为数组大小可能很大，不能在栈内存开，
//于是不能用大话数据结构上的写法，只能用Acwing的方法，在堆内存开一个公用的暂存数组，通过循环遍历将其复制到Nums，
//两种方法时间复杂度相同，这个循环遍历相当于大话数据结构方法最内层循环时的TR1[s]=SR[s]） 
void InitializeList();
void CreateFile();
void FileToArray();
void MergeSort(int* nums, int i, int j);
void Output(double duration);
int main(){
    printf("For %d random numbers: \n",LENGTH);
    CreateFile();
    FileToArray();
    clock_t startT,endT;
    double duration;
    startT=clock();//获取函数开始时刻
    MergeSort(Nums,0, LENGTH-1);
    endT=clock();//获取函数结束时刻
    duration=(double)(endT-startT)/CLOCKS_PER_SEC;//计算时长
    Output(duration);
    fclose(fp);
}
void CreateFile(){
    if(fp==NULL){
        printf("error-fail to open this file");
        exit(-1);
    }
    int x;
    srand((unsigned)time(0));
    for(int i=0; i<LENGTH; ++i){
        x=rand()%(LENGTH+1);
        fprintf(fp,"%d ",x);
    }
}
void FileToArray(){
    rewind(fp);
    for(int i=0; i<LENGTH; ++i){
        fscanf(fp,"%d",&Nums[i]);
    }
}
/*归并排序（递归版）*///nums为待排序数组，tMerged暂存结果数组，
void MergeSort(int* nums,int l,int r){
    if(l>=r) return;  
    int m,i,j,k;
    m=(l+r)>>1;
    MergeSort(nums,l,m); MergeSort(nums,m+1,r);
    i=l; j=m+1; k=l;
    while(i<=m&&j<=r)
        if(nums[i]<=nums[j]) tMerged[k++]=nums[i++];
        else tMerged[k++]=nums[j++];
    while(i<=m) tMerged[k++]=nums[i++];
    while(j<=r) tMerged[k++]=nums[j++];
    for(i=l,k=l;i<=r;++i,++k) nums[i]=tMerged[k];
}
void Output(double duration){
    printf("Duration: %4.4f seconds.\n",duration);
}

