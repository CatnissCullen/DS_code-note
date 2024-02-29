/*�ڽӾ���Floyd��������Ȩ���������и�Ȩ��·��*/
//ֻ�洢��1-n��������ֵ�����Ƕ����ţ����Ƕ���˳��Ҳ�Ƕ�����ֵ����������ֵ����1-n����Ҫ�ٿ�������齨��ӳ���ϵ
# include<iostream>
# include<cstring>
# include <algorithm>
# define N 210
# define INF 0x3f3f3f3f
using namespace std;
# define WghType int
typedef struct{
    int n;
    int m;
    WghType edges[N][N];
}MGraph;
MGraph G;
void AddEdges(int hd, int tl, WghType w);
void Floyd();
int main(){
    int r;
    cin>>G.n>>G.m>>r;
    memset(G.edges,0x3f,sizeof(G.edges));
    for(int i=1;i<=G.n;++i) G.edges[i][i]=0;//�Խ��߸�Ϊ0
    int a,b,w;
    for(int i=1;i<=G.m;i++){
        cin>>a>>b>>w;
//     GetIndex(a,b);     //���󶥵����ɶ�����
        AddEdges(a,b,w);
//     AddEdges(b,a);   //����ͼ
    }
    Floyd();
    while(r--){
        cin>>a>>b;
        if(G.edges[a][b]>INF/2) cout<<"impossible"<<endl;//��==INF��׼ȷ����Ϊ�и���Ȩ�����·�ͨ·��С��INF����������Ϊ����INF/2��
        else cout<<G.edges[a][b]<<endl;
    }
}
void AddEdges(int hd, int tl, WghType w){
    G.edges[hd][tl]=min(G.edges[hd][tl],w); //�����رߣ�ֻ������̱�
}
void Floyd(){//ԭ�ؽ��ڽӾ����Ϊ���·������
    for(int k=1;k<=G.n;++k)//kΪ��i��j���н�㣨�����k���������ѭ����
        for(int i=1;i<=G.n;++i)
            for(int j=1;j<=G.n;++j)
                G.edges[i][j]=min(G.edges[i][j],G.edges[i][k]+G.edges[k][j]);//������Ӹ�i;����k����j�����·
}
