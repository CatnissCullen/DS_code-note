/*�ڽӱ�������ȱ�����������ȱ�������������*/
# include<iostream>
# include<map>
# include<cstring>
# define N 1000
# define null 0x3f3f3f3f
using namespace std;
# define WghType int
# define ElemType int
typedef struct edge{//���߱���
    ElemType tlDta;
    WghType w;
    struct edge* nxtEdge;
}Edge;
typedef struct{
    int n;
    int m;
    map<ElemType,Edge*> fstEdge;//���߱��׳��߼�
}LGraph;
LGraph G;
map<ElemType,int> flg;//DFS�������飬����Ƿ��ѱ�����
ElemType qB[N];//BFS��������
map<ElemType,int> d;//BFS�������飬��¼���㵽�������Ĳ��������Ե�flg��
ElemType qT[N];//��������������
map<ElemType,int> in;//�������������飬��¼��ȣ�ģ��ɾ����
void AddEdge(ElemType hdDta, ElemType tlDta,WghType w);
void DFS(ElemType hdDta);
void BFS(ElemType stDta);
bool TopologicalSort();
int main(){
    cin>>G.n>>G.m;
    for(ElemType e=1;e<=G.n;++e){ G.fstEdge[e]=NULL; in[e]=0; }
    int a,b,w;
    for(int i=1;i<=G.m;++i){
        scanf("%d%d%d",&a,&b,&w);
        AddEdge(a,b,w);
    }
    for(ElemType e=1;e<=G.n;++e)//������ȱ���
        if(flg.find(e)==flg.end()) DFS(e);
    cout<<endl;
    for(ElemType e=1;e<=G.n;++e)//������ȱ���
        if(d.find(e)==d.end()) BFS(e);
    cout<<endl;
    if(TopologicalSort()) for(int i=0;i<G.n;++i) printf("%d ",qT[i]);//��������
    else cout<<-1;
}
void AddEdge(ElemType hdDta, ElemType tlDta,WghType w){
    Edge* edge=new Edge[1];
    edge->tlDta=tlDta; edge->w;
    edge->nxtEdge=G.fstEdge[hdDta]; G.fstEdge[hdDta]=edge;//ͷ�巨
    ++in[tlDta];//β���������һ
}
void DFS(ElemType hdDta){
    flg[hdDta]=1;
    printf("%d ",hdDta);
    Edge* p=G.fstEdge[hdDta];
    while(p!=NULL){
        if(flg.find(p->tlDta)==flg.end()) DFS(p->tlDta);
        p=p->nxtEdge;
    }
}
void BFS(ElemType stDta){
    int f=0,r=-1;
    qB[++r]=stDta;
    d[stDta]=0;
    while(f<=r){
        ElemType hdDta=qB[f++];
        printf("%d ",hdDta);
        Edge* p=G.fstEdge[hdDta];
        while(p!=NULL&&d.find(p->tlDta)==d.end()){
            qB[++r]=p->tlDta;
            d[p->tlDta]=d[hdDta]+1;
            p=p->nxtEdge;
        }
    }
}
bool TopologicalSort(){
    int f=0,r=-1;
    for(pair<ElemType,int> it:in)
        if(it.second==0) qT[++r]=it.first;
    while(f<=r){
        ElemType hdDta=qT[f++];
        Edge* p=G.fstEdge[hdDta];
        while(p!=NULL){
            --in[p->tlDta];
            if(!in[p->tlDta]) qT[++r]=p->tlDta;
            p=p->nxtEdge;
        }
    }
    return r==G.n-1;
}
