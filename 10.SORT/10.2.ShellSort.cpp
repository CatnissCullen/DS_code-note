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
    startT=clock();//��ȡ������ʼʱ��
    ShellSort(Nums);
    endT=clock();//��ȡ��������ʱ��
    duration=(double)(endT-startT)/CLOCKS_PER_SEC;//����ʱ��
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
/*����������*/
void SetGapsSeq(){
    int i=1,t;
    while(1){
        t=(1<<(i++))-1; 
        if(t<=LENGTH)gaps.push_back(t);
        else break;
    }
    reverse(gaps.begin(), gaps.end());
}
/*ϣ������*/
void ShellSort(int* &nums){
    SetGapsSeq();
    for(int i=0;gaps[i]>0;++i)//������ͬgap����Ӧ��ͬ�������飩��gap�ݼ�
        for(int j=1+gaps[i];j<=LENGTH;++j){//gapһ������������һ���������������У�����һ���������������һ����j��һλһλ���Ƶģ�
            int k=j-gaps[i];
            nums[0]=nums[j];//�����ڱ� 
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

