/*�ڽӾ���������ȱ����͹�����ȱ���*/
//ֻ�洢��1-n��������ֵ�����Ƕ����ţ����Ƕ���˳��Ҳ�Ƕ�����ֵ����������ֵ����1-n����Ҫ�ٿ�������齨��ӳ���ϵ
# include<iostream>
# include<map>
# include<cstring>
# define N 510//����һά���Ȳ��ܶ࿪̫�࣬ƽ�����ڴ����� 
# define null 0x3f3f3f3f
using namespace std;
# define WghType int
typedef struct{
    int n;
    int m;
    WghType edges[N][N];
}MGraph;
MGraph G;
map<int,int> flg;//DFS�������飬����Ƿ��ѱ�����
int qu[N];//BFS��������
map<int,int> d;//BFS�������飬��¼���㵽�������Ĳ��������Ե�flg�ã�δ��������d�����ڣ���map�����ʼ����
void AddEdges(int hd, int tl, WghType w);
void DFS(int hd);
void BFS(int st);
int main(){
    cin>>G.n>>G.m;
    memset(G.edges,0x3f,sizeof(G.edges));
    for(int i=1;i<=G.n;++i) G.edges[i][i]=0;//�Խ��߸�Ϊ0
    int a,b,w;
    for(int i=1;i<=G.m;i++){
        cin>>a>>b>>w;
//     GetIndex(a,b);
        AddEdges(a,b,w);
//     AddEdges(b,a);   //����ͼ
    }
    for(int st=1;st<=G.n;++st)
        if(flg.find(st)==flg.end()) DFS(st);
    cout<<endl;
    for(int st=1;st<=G.n;++st)
        if(d.find(st)==d.end()) BFS(st);
}
void AddEdges(int hd, int tl, WghType w){
    G.edges[hd][tl]=w;//�������ر� 
}
void DFS(int hd){
    flg[hd]=1;
    printf("%d ",hd);
    for(int tl=1;tl<=G.n;++tl)
        if(G.edges[hd][tl]!=null&&flg.find(tl)==flg.end())//����hd��δ����β����
            DFS(tl);
}
void BFS(int st){
    int f=0,r=-1;
    d[st]=0;
    qu[++r]=st;
    while(f<=r){
        int hd=qu[f++];
        printf("%d ",hd);
        for(int tl=1;tl<=G.n;++tl)
            if(G.edges[hd][tl]!=null&&d.find(tl)==d.end()){//����hd��δ����β����
                d[tl]=d[hd]+1;
                qu[++r]=tl;
            }
    }
}
