/*�������������ҵ�һ��x�����һ��x���ӵ�m����x������ʱ��θ��±߽����֣�
 * ��������l=m��д������[m]<=x�����<�����һ��x>����������r=m��д������[m]>=x�����<�ҵ�һ��x>��*/
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
    l=0; r=n-1;//�ҵ�һ��x�����仮��Ϊ[l,m-1][m,r]��ʼ�ձ�֤m�����ܿ���x����һλ�������������ʵ�������[m,r]
    while(l<r){//while����ȡ=��������һֱ��ԭ��ѭ��
        m=(l+r)>>1;
        if(nums[m]>=x) r=m;
        else l=m+1;
    }//���l=r��m����һ�ε�m��m������x��l��r�����ǣ���
    
    if(nums[l]==x) printf("%d ",l);
    else{ printf("-1 -1\n"); return; }
    
    l=0; r=n-1;//�ҵ����һ��x�����仮��Ϊ[l,m][m+1,r]��ʼ�ձ�֤m�����ܿ���x�����һλ�������������ʵ�������[l,m]
    while(l<r){//while����ȡ=��������һֱ��ԭ��ѭ��
        m=(l+r+1)>>1;
        if(nums[m]<=x) l=m;
        else r=m-1;
    }//���l=r��m����һ�ε�m��m������x��l��r�����ǣ���
    printf("%d\n",r);
}
