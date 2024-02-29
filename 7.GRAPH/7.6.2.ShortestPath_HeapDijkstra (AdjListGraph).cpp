/*��̬�ڽӱ���Ż�Dijkstra*/
# include <iostream>
# include <cstring>
# include <algorithm>
# include <queue>
using namespace std;
# define ElemType int
# define WghType int
# define N 100010
# define M 2*N//����ͼ�������Ϊ����������
# define INF 0x3f3f3f3f
typedef pair<int,int> Pair;//�յ�ź�·��Ȩֵ������ {di, i} �����ڽ���
typedef struct{
    ElemType dta;
    WghType w;//�����·��ҪȨֵ������
    int nxt;
}TlNode;//�ڽ������㣨β���㣩
int fstTail[N];//fstTail[data]=i��ֵΪdta�Ķ���ı߱��У��׳���Ϊ�� i ����
TlNode tlLists[M];
int idx;
int n,m;//������������
int d[N];//d[i]=length ���� i �ŵ㵽���ľ���
int flg[N];//flg[i]=1 ���� i �ŵ㣨�յ㣩�����ľ�����ȷ��������Ϊ0��
void AddEdge(ElemType dt1,ElemType dt2,WghType w);
void Dijkstra(int st);
int main(){
    cin>>n>>m;
    memset(fstTail,-1,sizeof fstTail);
    int a,b,w;
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&a,&b,&w);
        AddEdge(a,b,w);
//		AddEdge(b,a); //����ͼ��Ҫ�ԳƵؼ�������
    }
    Dijkstra(1);
    if(d[n]==INF) cout<<-1;//�������������·��d[ed]���������˵����㵽���յ㲻��ͨ
    else cout<<d[n];
}
void AddEdge(ElemType dt1,ElemType dt2,WghType w){
    tlLists[idx].dta=dt2, tlLists[idx].w=w;//�����idx���ߵ�β�������ݺͱ�Ȩ��tlLists�е�dt2���ܳ��ֶ�Σ��Ƕ����ߵ�β���㣩
    tlLists[idx].nxt=fstTail[dt1]; fstTail[dt1]=idx;//��dt1->dt2��ͷ�巨��ͷ����ĳ��߱�
    ++idx;
}
void Dijkstra(int st){
    memset(d,0x3f,sizeof d);//��ʼ��d
    d[st]=0;//��㵽��������Ϊ0
    priority_queue<Pair,vector<Pair>,greater<Pair>> heap;//������
    heap.push({0,1});
    while(heap.size()){
        auto t=heap.top();//Ĭ��a��С���ѣ���Pair�ĵ�һ��������·��Ȩֵ������
        heap.pop();
        int di=t.first, i=t.second;
        if(flg[i]) continue;//�������ҵ����·���յ�
        flg[i]=1;
        for(int p=fstTail[i]; p!=-1; p=tlLists[p].nxt){
            d[tlLists[p].dta]=min(d[tlLists[p].dta], di+tlLists[p].w);
            heap.push({d[tlLists[p].dta],tlLists[p].dta});
        }
    }
}

