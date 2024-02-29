/*在有序序列中找第一个x和最后一个x（从当m满足x的性质时如何更新边界入手，
 * 若更新是l=m则写法类似[m]<=x的情况<找最后一个x>，若更新是r=m则写法类似[m]>=x的情况<找第一个x>）*/
# include<iostream>
using namespace std;
# define N 100000
int nums[N];
int n;
void BSearch(int x);
int main(){
    int q; int x;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;++i) scanf("%d",&nums[i]);
    for(int i=1;i<=q;++i){
        scanf("%d",&x); BSearch(x);
    }
}
void BSearch(int x){
    int m,l,r;
    l=0; r=n-1;//找第一个x：区间划分为[l,m-1][m,r]，始终保证m尽可能靠近x串第一位，最终满足性质的区间是[m,r]
    while(l<r){//while不能取=否则最后会一直在原地循环
        m=(l+r)>>1;
        if(nums[m]>=x) r=m;
        else l=m+1;
    }//最后l=r，m是上一次的m（m处不是x！l、r处才是！）
    
    if(nums[l]==x) printf("%d ",l);
    else{ printf("-1 -1\n"); return; }
    
    l=0; r=n-1;//找第最后一个x：区间划分为[l,m][m+1,r]，始终保证m尽可能靠近x串最后一位，最终满足性质的区间是[l,m]
    while(l<r){//while不能取=否则最后会一直在原地循环
        m=(l+r+1)>>1;
        if(nums[m]<=x) l=m;
        else r=m-1;
    }//最后l=r，m是上一次的m（m处不是x！l、r处才是！）
    printf("%d\n",r);
}
