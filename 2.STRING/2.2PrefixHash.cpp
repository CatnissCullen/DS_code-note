# include <iostream>
# include <math.h>
using namespace std;
typedef unsigned long long ull;
# define N 100010
# define p 131
int n,m;//n为字符串长度（不含空字符）
char str[N];
ull preHVal[N],pStm[N];//pStm[i]=p^i（方便表示计算公式）
void Initialize();
ull SubStrHVal(int L, int R);
int main(){
    cin>>n>>m;
    scanf("%s",str+1);
    Initialize();
    int L1,R1,L2,R2;
    while(m--){
        scanf("%d%d%d%d", &L1, &R1, &L2, &R2);
        if(SubStrHVal(L1, R1)==SubStrHVal(L2, R2)) puts("Yes");
        else puts("No");
    }
}
void Initialize(){
    pStm[0]=1;
    for(int i=1;i<=n;++i){
        pStm[i]=pStm[i-1]*p;
        preHVal[i]=preHVal[i-1]*p+str[i];
    }
}
ull SubStrHVal(int L, int R){
    return preHVal[R]-preHVal[L-1]*pStm[R-L+1];
}

