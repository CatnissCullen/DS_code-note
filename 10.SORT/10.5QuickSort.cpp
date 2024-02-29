# include<iostream>
# include <stdlib.h>
# include <time.h>
# define LENGTH 10000000
using namespace std;
FILE* fp=fopen("intfile.dat","r+");
int* Nums;
void InitializeList();
void CreateFile();
void FileToArray();
void QuickSort(int* &nums, int i, int j);
void Output(double duration);
int main(){
    printf("For %d random numbers: \n",LENGTH);
    Nums=new int[LENGTH+1];
    CreateFile();
    FileToArray();
    clock_t startT,endT;
    double duration;
    startT=clock();//��ȡ������ʼʱ��
    QuickSort(Nums, 1, LENGTH);
    endT=clock();//��ȡ��������ʱ��
    duration=(double)(endT-startT)/CLOCKS_PER_SEC;//����ʱ��
    Output(duration);
    fclose(fp);
}
void Swap(int &a,int &b){
    if(a!=b){
        a^=b; b^=a; a^=b;
    }
}
void CreateFile(){
    if(fp==NULL){
        printf("error-fail to open this file");
        exit(-1);
    }
    int x;
    srand((unsigned)time(0));
    for(int i=1; i <= LENGTH; ++i){
        x=rand()%(LENGTH+1);
        fprintf(fp,"%d ",x);
    }
}
void FileToArray(){
    rewind(fp);
    for(int i=1; i <= LENGTH; ++i){
        fscanf(fp,"%d",&Nums[i]);
    }
}
/*����ȡ�л�ȡ����ֵ�ŵ�����0�±괦*/
void GetPivot(int &pivot,int a,int b,int c){//����������������λ�õ������м�����Ϊ����ֵ 
    if((a-b)*(b-c)>=0) pivot=b;
    else if((a-c)*(c-b)>=0) pivot=c;
    else pivot=a;
}
/*��������*/
void QuickSort(int* &nums, int l, int r){
    if(l>=r) return;
    int i=l-1,j=r+1;
    GetPivot(nums[0],nums[l],nums[(l+r-1)>>1],nums[r-1]);//���ݹ�ʱ��j�ֽ磬����ֵһ������ȡ��r���������ѭ���������ұߵ���Ӧȡr-1�� �� 
    while(1){
        do{ ++i; }while(nums[i]<nums[0]);//���ܼӵȺ� 
        do{ --j; }while(nums[j]>nums[0]);
        if(i<j) Swap(nums[i],nums[j]);
        else break;
    }//��ǰһ���ݹ��ұ߽�дi-1����һ���ݹ���߽�дi��������ֵһ������ȡ��l���������ѭ����Ҫ��(l+1)��ʼ���м�����a�ĳ�l+1�ţ�b�ĳɣ�l+r+1��/2�ţ�����һ��ֻ��������ʱb������߽磩 
    QuickSort(nums,l,j); QuickSort(nums,j+1,r); 
}
void Output(double duration){
    printf("Duration: %4.4f seconds.\n",duration);
}
