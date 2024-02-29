# include<iostream>
# include <stdlib.h>
# include <time.h>
# include <vector>
# include <algorithm>
# define LENGTH 1000000
using namespace std;
FILE* fp=fopen("intfile.dat","r+");
int* Nums;
vector<int> gaps;
void CreateFile();
void FileToArray();
void ShellSort(int* &nums);
void Output(double duration);
int main(){
    printf("For %d random numbers: \n",LENGTH);
    Nums=new int[LENGTH+1];
    CreateFile();
    FileToArray();
    clock_t startT,endT;
    double duration;
    startT=clock();//获取函数开始时刻
    ShellSort(Nums);
    endT=clock();//获取函数结束时刻
    duration=(double)(endT-startT)/CLOCKS_PER_SEC;//计算时长
    Output(duration);
    fclose(fp);
    delete(Nums);
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
/*求增量序列*/
void SetGapsSeq(){
    int i=1,t;
    while(1){
        t=(1<<(i++))-1; 
        if(t<=LENGTH)gaps.push_back(t);
        else break;
    }
    reverse(gaps.begin(), gaps.end());
}
/*希尔排序*/
void ShellSort(int* &nums){
    SetGapsSeq();
    for(int i=0;gaps[i]>0;++i)//遍历不同gap（对应不同子序列组），gap递减
        for(int j=1+gaps[i];j<=LENGTH;++j){//gap一定，子序列组一定，遍历各子序列（不是一个子序列完成再下一个，j是一位一位后移的）
            int k=j-gaps[i];
            nums[0]=nums[j];//设置哨兵 
            while(k>=1&&nums[k]>nums[0]){
                nums[k+gaps[i]]=nums[k];
                k-=gaps[i];
            }
            nums[k+gaps[i]]=nums[0];
        }
}
void Output(double duration){
    printf("Duration: %4.4f seconds.\n",duration);
}

