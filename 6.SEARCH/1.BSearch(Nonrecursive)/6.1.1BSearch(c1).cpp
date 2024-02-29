/*寻找序列中任意一个与目标值相同的元素（最基础的二分查找）（其他类型见笔记图片）*/ 
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define SIZE 20
int nums[SIZE+1];
void CreateFile();
void ReadFileToArray();
void BSearch_NonRecursive(int x);
int compareInteger(const void *a, const void *b);
int main(){
    CreateFile();
    ReadFileToArray();
    int x;
    printf("\nEnter your number："); scanf("%d",&x);
    qsort(nums + 1, SIZE, sizeof(int), compareInteger);
    for(int i=1;i<=SIZE;++i) printf("%d ",nums[i]);
    BSearch_NonRecursive(x);
    return 0;
}
int compareInteger(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}
void CreateFile(){
    //打开文件
    FILE * fp=fopen("datafile.txt", "w+");
    if(fp==NULL){ printf("error-fail to open file"); exit(-1); }
    //写入随机数
    srand((unsigned)time(0));
    for(int i=1;i<=SIZE;++i) fprintf(fp,"%d ",rand()%(SIZE+1));
    fclose(fp);
}
void ReadFileToArray(){
    //打开文件
    FILE * fp=fopen("datafile.txt", "r+");
    if(fp==NULL){ printf("error-fail to open file"); exit(1); }
    //读取数据到数组
    for(int i=1;i<=SIZE;i++){fscanf(fp,"%d",nums+i); printf("%d ",nums[i]);}
    fclose(fp);
}
void BSearch_NonRecursive(int x){
    int min=1,max=SIZE,mid;
    while(min<=max){
        mid=(x-nums[min])/(nums[max]-nums[min])*(max-min)+min;//用插值法改进的二分法（若数组有重复元素则不能用！可能出现nums[max]-nums[min]，分母会为0） 
        if(nums[mid]<x) min=mid+1;
        else if(nums[mid]>x) max=mid-1;
        else break;
    }
    if(min>max) printf("\nBinary Search : Your number doesn't exist.");
    else printf("\nBinary Search : Your number is found at index %d.",mid);
}
