# include <iostream>
using namespace std;
int n;
int* Nums;
int* tMerged;
void MergeSort_non_recursive(int* nums,int len);
void Merge_pass(int* nums,int len,int subLen);
void Merge(int* nums,int l,int m,int r);//必须有形参m，因为[m+1,r]长度可能不足subLen
int main(){
    cin>>n; Nums=new int[n];
    for(int i=0;i<n;++i) scanf("%d",&Nums[i]);
    MergeSort_non_recursive(Nums,n);
    for(int i=0;i<n;++i) printf("%d ",Nums[i]);
}
void MergeSort_non_recursive(int* nums,int len){
    int subLen; subLen=1;
    while(subLen<len){
        Merge_pass(nums,len,subLen);
        subLen*=2;
    }
}
void Merge_pass(int* nums,int len,int subLen){//进行一趟subLen一定的归并
    int l; l=0;
    while(l<len-len%(2*subLen)){//满2*subLen的元素区间[l,r]依次归并
        Merge(nums,l,l+subLen-1,l+2*subLen-1);
        l+=2*subLen;
    }//此时l要么已在nums以外（=len），要么<len
    //若l<len，说明存在剩余元素未归并，可能满1*subLen，可能不足1*subLen
    if(len-l>subLen) Merge(nums,l,l+subLen-1,len-1);//若剩余满1*subLen
    else return;//若剩余不足1*subLen
}
void Merge(int* nums,int l,int m,int r){
    tMerged=new int[r-l+1];
    int i,j,k; i=l,j=m+1,k=0;
    while(i<=m&&j<=r){
        if(nums[i]<=nums[j]) tMerged[k++]=nums[i++];
        else tMerged[k++]=nums[j++];
    }
    while(i<=m) tMerged[k++]=nums[i++];
    while(j<=r) tMerged[k++]=nums[j++];
    for(k=0,i=l;i<=r;++i,++k) nums[i]=tMerged[k];
    delete(tMerged);
}
