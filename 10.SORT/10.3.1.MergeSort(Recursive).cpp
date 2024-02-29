# include<iostream>
# include <stdlib.h>
# include <time.h>
# define LENGTH 1000000
using namespace std;
FILE* fp=fopen("intfile.dat","r+");
int Nums[LENGTH]; 
int tMerged[LENGTH]; //�ݴ�ݹ�鲢��������飨�޷���ÿ�εݹ�ǰ�½�����Ϊ�����С���ܴܺ󣬲�����ջ�ڴ濪��
//���ǲ����ô����ݽṹ�ϵ�д����ֻ����Acwing�ķ������ڶ��ڴ濪һ�����õ��ݴ����飬ͨ��ѭ���������临�Ƶ�Nums��
//���ַ���ʱ�临�Ӷ���ͬ�����ѭ�������൱�ڴ����ݽṹ�������ڲ�ѭ��ʱ��TR1[s]=SR[s]�� 
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
    startT=clock();//��ȡ������ʼʱ��
    MergeSort(Nums,0, LENGTH-1);
    endT=clock();//��ȡ��������ʱ��
    duration=(double)(endT-startT)/CLOCKS_PER_SEC;//����ʱ��
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
/*�鲢���򣨵ݹ�棩*///numsΪ���������飬tMerged�ݴ������飬
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

