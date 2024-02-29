/*��̬�ڽӱ���/����ͼ/����ͼ������ֵ����<��������Ҫ�Լ�ӳ���������ֵ�������������д��涥��ʵ��ֵ��*/
# include <iostream>
# include <map>
using namespace std;
# define ElemType int
# define N 100010
# define M 2*N//����ͼ�������Ϊ����������
typedef struct{
    ElemType dta;
    int nxt;
}TlNode;//�ڽ������㣨β���㣩
map<ElemType,int> fstTail;//fstTail[data]=i��ֵΪdata�Ķ���ı߱��У��׳���Ϊ�� i ����
TlNode tlLists[M];
int idx;
int n,m;//������������
map<ElemType,bool> flag;//DFS�������飬����Ƿ��ѱ�����
ElemType qB[M];//BFS��������
map<ElemType,int> d;//BFS�������飬��¼���㵽�������Ĳ��������Ե�flg��
ElemType qT[M];//��������������
map<ElemType,int> in;//�������������飬��¼��ȣ�ģ��ɾ����
int f,r;
void AddEdge(ElemType dt1,ElemType dt2);
void DFS(ElemType hdDta);
void BFS(ElemType stDta);
bool TopologicalSort();
int main(){
    int a,b;
    cin>>n>>m;

    for(ElemType e=1;e<=n;++e) { fstTail[e]=-1; in[e]=0; }//һ��������ֵ������ģ�������һ�������г�ȫ���������ݣ���һ���Գ�ʼ��fstEdge��in��
    //����һ�߶����һ�����map<ElemType,int>����Ϊ�п����й����㣬��ӱ�ʱ��Ӳ������㣻
    //�������洢�����㵽fstEdge��in�������������޻�ͼ����������Ҫ�������������������������У����ʱ�������޷�˳����ӳ��ӣ�
    //���ն��������ж��㲻��n����βָ���Ʋ���n-1���ᰴ�л�ͼ���-1�����洢�˹����㣬���ڹ��������Ϊ0��ָ��-1�����Ի���������������
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        AddEdge(a,b);
//		AddEdge(b,a); //����ͼ��Ҫ�ԳƵؼ�������
    }

    for(ElemType st=1;st<=n;++st)//���߱���������ĸ 
        if(flag.find(st)==flag.end()) DFS(st);//������ȱ���

    for(ElemType st=1;st<=n;++st)//���߱���������ĸ
        if(in.find(st)==in.end()) BFS(st);//������ȱ���

    if(!TopologicalSort()) cout<<-1;//�л�ͼ����ӡ-1
    else for(int i=0;i<n;++i) printf("%d ",qT[i]);//�޻�ͼ����ӡ��������
}
void AddEdge(ElemType dt1,ElemType dt2){
    tlLists[idx].dta=dt2;//�����idx���ߵ�β�������ݣ�tlLists�е�dt2���ܳ��ֶ�Σ��Ƕ����ߵ�β���㣩
    tlLists[idx].nxt=fstTail[dt1]; fstTail[dt1]=idx;//��dt1->dt2��ͷ�巨��ͷ����ĳ��߱�
    ++in[dt2];//β���������һ
    ++idx;
}
void DFS(ElemType hdDta){
    flag[hdDta]=true;
    printf("%d ",hdDta);
    for(int j=fstTail[hdDta]; j!=-1; j=tlLists[j].nxt){
        int tlDta=tlLists[j].dta;
        if(flag.find(tlDta)==flag.end()) DFS(tlDta);
    }
}
void BFS(ElemType stDta){
    f=0,r=-1;
    qB[++r]=stDta;
    d[stDta]=0;
    while(f<=r){
        ElemType hdDta=qB[f++];
        printf("%d ",hdDta);
        for(int j=fstTail[hdDta]; j!=-1; j=tlLists[j].nxt){
            ElemType tlDta=tlLists[j].dta;
            if(d.find(tlDta)==d.end()){
                d[tlDta]=d[hdDta]+1;
                qB[++r]=tlDta;
            }
        }
    }
}
bool TopologicalSort(){
    f=0,r=-1;
    for(pair<ElemType,int> it:in)
        if(!it.second) qT[++r]=it.first;
    while(f<=r){
        ElemType hdDta=qT[f++];
        for(int i=fstTail[hdDta]; i!=-1; i=tlLists[i].nxt){
            ElemType tlDta=tlLists[i].dta;
            --in[tlDta];
            if(!in[tlDta]) qT[++r]=tlDta;
        }
    }
    return r==n-1;
}
