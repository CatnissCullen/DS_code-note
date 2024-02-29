# include <iostream>
using namespace std;
int n;
int* Nums;
int* tMerged;
void MergeSort_non_recursive(int* nums,int len);
void Merge_pass(int* nums,int len,int subLen);
void Merge(int* nums,int l,int m,int r);//�������β�m����Ϊ[m+1,r]���ȿ��ܲ���subLen
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
void Merge_pass(int* nums,int len,int subLen){//����һ��subLenһ���Ĺ鲢
    int l; l=0;
    while(l<len-len%(2*subLen)){//��2*subLen��Ԫ������[l,r]���ι鲢
        Merge(nums,l,l+subLen-1,l+2*subLen-1);
        l+=2*subLen;
    }//��ʱlҪô����nums���⣨=len����Ҫô<len
    //��l<len��˵������ʣ��Ԫ��δ�鲢��������1*subLen�����ܲ���1*subLen
    if(len-l>subLen) Merge(nums,l,l+subLen-1,len-1);//��ʣ����1*subLen
    else return;//��ʣ�಻��1*subLen
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
