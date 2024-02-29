# include <iostream>
# include <string.h>
using namespace std;
# define N 200100//���������Ϊ100000����������divisor��������Ƕ��٣������Ϊ2*N+100��+100�㹻���գ�
# define null 0x3f3f3f3f//"�����"
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
void Initialize(){//��ϣ��ȫ��Ϊ��
    memset(hashTab,0x3f,sizeof(hashTab));
}
int GetDivisor(int n){//��������һ��Ϊn����Ҫ�ҵ�����2*n����3*n������С������Ϊdivisor
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
int Find(int x,int &i){//�ҵ���λ����0���ҵ�x����1����x�ұ�������-1
    int hashVal; hashVal=(x%divisor+divisor)%divisor;//��֤�����Ĺ�ϣֵҲ������
    int di=0; i=hashVal;
    while(1){
        if(hashTab[i]==null) return 0;
        else if(hashTab[i]==x) return 1;
        else{//�г�ͻ
            if(di==hashSize) return -1;
            else i=(hashVal+(++di))%hashSize;
        }
    }
}
int Add(int x){//�ɹ���ӷ���0���ҵ�x����1���޿�λ����-1
    int i; int op;
    op=Find(x,i);
    switch(op){
        case 0: hashTab[i]=x; return 0;
        case 1: return 1;
        case -1: return -1;
    }
}
int Delete(int x){//�ɹ�ɾ������1����x����-1
    int i; int op;
    op=Find(x,i);
    switch(op){
        case 0:case -1: return -1;
        case 1: hashTab[i]=null; return 1;
    }
}
