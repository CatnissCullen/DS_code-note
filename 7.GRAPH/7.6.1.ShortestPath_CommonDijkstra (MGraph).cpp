/*�ڽӾ�������Dijkstra*/
//ֻ�洢��1-n��������ֵ�����Ƕ����ţ����Ƕ���˳��Ҳ�Ƕ�����ֵ����������ֵ����1-n����Ҫ�ٿ�������齨��ӳ���ϵ
# include<iostream>
# include<cstring>
# include <algorithm>
# define N 501
# define INF 0x3f3f3f3f
using namespace std;
# define WghType int
typedef struct{
    int n;
    int m;
    WghType edges[N][N];
}MGraph;
MGraph G;
int d[N];//d[i]=length ���� i �ŵ㵽���ľ���
int flg[N];//flg[i]=1 ���� i �ŵ㣨�յ㣩�����ľ�����ȷ��������Ϊ0��
void AddEdges(int hd, int tl, WghType w);
void Dijkstra(int st);
int main(){
    cin>>G.n>>G.m;
    memset(G.edges,0x3f,sizeof(G.edges));
    for(int i=1;i<=G.n;++i) G.edges[i][i]=0;//�Խ��߸�Ϊ0
    int a,b,w;
    for(int i=1;i<=G.m;i++){
        cin>>a>>b>>w;
//     GetIndex(a,b);     //���󶥵����ɶ�����
        AddEdges(a,b,w);
//     AddEdges(b,a);   //����ͼ
    }
    Dijkstra(1);
//    int ed; cin>>ed;//�����յ�
    if(d[G.n]==INF) cout<<-1;//�������������·��d[ed]���������˵����㵽���յ㲻��ͨ
    else cout<<d[G.n];
}
void AddEdges(int hd, int tl, WghType w){
    G.edges[hd][tl]=min(G.edges[hd][tl],w); //�����رߣ�ֻ������̱�
}
void Dijkstra(int st){
    memset(d,0x3f,sizeof d);//��ʼ������dΪ����� 
    d[st]=0;//��㵽��������Ϊ0
    for(int k=1;k<=G.n;++k){//n�α�����������㵽n��������·
        int t=-1;
        for(int i=1;i<=G.n;++i)
            if(!flg[i]&&(t==-1||d[i]<d[t])) t=i;
        flg[t]=1;
        for(int j=1;j<=G.n;++j)
            d[j]=min(d[j],d[t]+G.edges[t][j]);
    }
}
