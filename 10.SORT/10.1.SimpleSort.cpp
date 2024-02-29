# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <math.h>
# define LENGTH 100000
/*顺序表结构（数据对象：数组）*/
typedef struct{
    int* A;//A[0]闲置或作可利用空间
    int length;
}SqList;
FILE* fp=fopen("intfile.dat","r+");
long long int cnt1=0;//记录交换和移动总次数
long long int cnt2=0;//记录比较次数
SqList list;
/*初始化顺序表*/
void InitializeList(){
    list.A=(int*)calloc(LENGTH+1,sizeof(int));
    list.length=LENGTH;
}
void CreateFile(){
    if(fp==NULL){
        printf("error-fail to open this file");
        exit(-1);
    }
    int x;
    srand((unsigned)time(0));
    for(int i=1;i<=list.length;++i){
        x=rand()%(LENGTH+1);
        fprintf(fp,"%d ",x);
    }
}
void FileToArray(){
    rewind(fp);
    for(int i=1;i<=list.length;++i){
        fscanf(fp,"%d",&list.A[i]);
    }
}
void ReverseArray(){
    int t;
    for(int i=1;i<=list.length/2;++i){
        t=list.A[i]; list.A[i]=list.A[list.length-i+1]; list.A[list.length-i+1]=t;
    }
}
void Swap(int &a,int &b,int t){
    t=a; a=b; b=t;
}
void OutPut(double duration,long long int times1,long long int times2){
    printf("Duration: %4.4f seconds.\n",duration);
    printf("Times of comparisons: %lld in total.\n", times2);
    printf("Times of swaps & moves: %lld in total.\n\n", times1);
}
/*冒泡排序：稳定；时间复杂度O(n^2)；空间复杂度O(1)（即A[0]）；适用于元素数少或基本有序*/
void BubbleSort(){
    clock_t startT,endT;
    double duration;
    FileToArray();
    cnt1=0; cnt2=0;
    startT=clock();//获取函数开始时刻
    for(int i=1;i<=list.length;++i){//i为排序趟数；每趟排序开始时flag为1，进入循环
        for(int j=1;j<=list.length-i;++j){//j为每趟排序中每次比较时前面元素的下标
            if(list.A[j]>list.A[j+1]) {//若前面元素大于后面元素
                Swap(list.A[j],list.A[j+1],list.A[0]);//交换元素
                cnt1++;
            }
            cnt2++;
        }
    }
    endT=clock();//获取函数结束时刻
    duration=(double)(endT-startT)/CLOCKS_PER_SEC;//计算时长
    printf("BUBBLE SORT\n");
    OutPut(duration,cnt1,cnt2);
}
/*简单选择排序：不稳定；时间复杂度O(n^2)；空间复杂度O(1)（即A[0]）；适用于元素数少或无需完全排序（只用找到按顺序的第n个元素）*/
void SelectionSort(){
    clock_t startT,endT;
    double duration;
    FileToArray();
    cnt1=0; cnt2=0;
    startT=clock();//获取函数开始时刻
    int min;//当前最小值的下标
    for(int i=1;i<=list.length;++i){//i为各元素位置下标，从位置1开始依次选出按次序应该放在该位置i的元素
        min=i;//选择位置i的元素时，min初始化为当前i
        for(int j=i+1;j<=list.length;++j){
            if(list.A[j]<list.A[min])//如果后面找到了比当前i出元素小的值
                min=j;//用min记录新元素的下标，继续往后找更小元素的下标
            cnt2++;
        }
        if(min!=i){//全部检查完，最终min的值即为应该放在下标i位置的元素下标
            Swap(list.A[min],list.A[i],list.A[0]);//若min相对于最开始的i值发生了改变，则交换元素
            cnt1++;
        }
    }
    endT=clock();//获取函数结束时刻
    duration=(double)(endT-startT)/CLOCKS_PER_SEC;//计算时长
    printf("SELECTION SORT\n");
    OutPut(duration,cnt1,cnt2);
}
/*直接插入排序：稳定；时间复杂度O(n^2)；空间复杂度O(1)（即A[0]）；适用于元素数少或基本有序*/
void StraightInsertionSort(){
    clock_t startT,endT;
    double duration;
    FileToArray();
    cnt1=0; cnt2=0;
    startT=clock();//获取函数开始时刻
    for(int i=2;i<=list.length-1;i++){//i为各元素位置下标，从位置2开始逐个检查是否和前一位元素排序正确
        if(list.A[i-1]>list.A[i]){//若前一位元素更大，说明需要将i处元素往前插（i-1处以前可能还有比i处大的元素）
            list.A[0]=list.A[i]; cnt1++;//设置第0位为A[i]（“哨兵”），方便最后将A[i]原本的值插回数组（因为腾位置时会改变i处的值）
            int j;
            for(j=i;list.A[j-1]>list.A[0];j--){
                cnt2++;
                //腾位置，j从i的位置开始往前，前一位元素移到当前位置，直到前一位置元素比“哨兵”小
                list.A[j]=list.A[j-1]; cnt1++;
            }
            cnt2++;
            list.A[j]=list.A[0]; cnt1++;//将“哨兵“插回数组腾出的位置（即j最后所在位置）
        }
        cnt2++;
    }
    endT=clock();//获取函数结束时刻
    duration=(double)(endT-startT)/CLOCKS_PER_SEC;//计算时长
    printf("STRAIGHT INSERTION SORT\n");
    OutPut(duration,cnt1,cnt2);
}
int main() {
	printf("For %d random numbers: \n",LENGTH);
    InitializeList();
    CreateFile();
    BubbleSort();
    SelectionSort();
    StraightInsertionSort();
    fclose(fp);
}
