# include <iostream>
# include <string.h>
using namespace std;
# define N 200100//数据量最多为100000个，则无论divisor求出来会是多少，先设表长为2*N+100（+100足够保险）
# define null 0x3f3f3f3f//"无穷大"
int hashTab[N];
int hashSize; int divisor;
void Initialize();
int GetDivisor(int n);
int Find(int x,int &i);
int Add(int x);
int main(){
    int n;
    cin>>n; hashSize=n;
    divisor=GetDivisor(hashSize);
    Initialize();
    char op[2]; int x; int i; int res;
    while(n--){
        scanf("%s%d",op,&x);
        if(op[0]=='I') Add(x);
        else{
            res=Find(x,i);
            if(res==1) puts("Yes");
            else puts("No");
        }
    }
}
void Initialize(){//哈希表全设为空
    memset(hashTab,0x3f,sizeof(hashTab));
}
int GetDivisor(int n){//若数据量一共为n，则要找到大于2*n（或3*n）的最小质数作为divisor
    int i=2*n;
    while(1){
        bool flag=true;
        for(int j=2;j*j<=i;++j)
            if(i%j==0){
                flag=false; break;
            }
        if(flag) break;
        ++i;
    }
    return i;
}
int Find(int x,int &i){//找到空位返回0，找到x返回1，无x且表满返回-1
    int hashVal; hashVal=(x%divisor+divisor)%divisor;//保证负数的哈希值也是正数
    int di=0; i=hashVal;
    while(1){
        if(hashTab[i]==null) return 0;
        else if(hashTab[i]==x) return 1;
        else{//有冲突
            if(di==hashSize) return -1;
            else i=(hashVal+(++di))%hashSize;
        }
    }
}
int Add(int x){//成功添加返回0，找到x返回1，无空位返回-1
    int i; int op;
    op=Find(x,i);
    switch(op){
        case 0: hashTab[i]=x; return 0;
        case 1: return 1;
        case -1: return -1;
    }
}
int Delete(int x){//成功删除返回1，无x返回-1
    int i; int op;
    op=Find(x,i);
    switch(op){
        case 0:case -1: return -1;
        case 1: hashTab[i]=null; return 1;
    }
}
