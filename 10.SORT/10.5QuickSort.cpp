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
    startT=clock();//获取函数开始时刻
    QuickSort(Nums, 1, LENGTH);
    endT=clock();//获取函数结束时刻
    duration=(double)(endT-startT)/CLOCKS_PER_SEC;//计算时长
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
/*三数取中获取枢轴值放到数组0下标处*/
void GetPivot(int &pivot,int a,int b,int c){//求数组左中右三个位置的数的中间数作为枢轴值 
    if((a-b)*(b-c)>=0) pivot=b;
    else if((a-c)*(c-b)>=0) pivot=c;
    else pivot=a;
}
/*快速排序*/
void QuickSort(int* &nums, int l, int r){
    if(l>=r) return;
    int i=l-1,j=r+1;
    GetPivot(nums[0],nums[l],nums[(l+r-1)>>1],nums[r-1]);//当递归时用j分界，枢轴值一定不能取到r！会进入死循环！于是右边的数应取r-1号 ！ 
    while(1){
        do{ ++i; }while(nums[i]<nums[0]);//不能加等号 
        do{ --j; }while(nums[j]>nums[0]);
        if(i<j) Swap(nums[i],nums[j]);
        else break;
    }//若前一个递归右边界写i-1，后一个递归左边界写i，则枢轴值一定不能取到l！会进入死循环！要从(l+1)开始找中间数（a改成l+1号，b改成（l+r+1）/2号，否则当一共只有两个数时b会是左边界） 
    QuickSort(nums,l,j); QuickSort(nums,j+1,r); 
}
void Output(double duration){
    printf("Duration: %4.4f seconds.\n",duration);
}
