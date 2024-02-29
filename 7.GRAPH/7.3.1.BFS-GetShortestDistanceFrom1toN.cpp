/*��1�ŵ㵽n�ŵ����̾��루��Ȩ����ͼ�����޷��ߵ������-1*/
# include <iostream>
# include <map>
using namespace std;
# define ElemType int
# define N 100010
# define M 2*N//����ͼ�������Ϊ����������
map<ElemType,int> fstEdge;//fstEdge[data]=i��ֵΪdata�Ķ���ı߱��У��׳���Ϊ�� i ����
int nxtEdge[M];//nxtEdge[i]=j���ڵ� i ����ͷ����ĳ��߱��У���һ����Ϊ�� j ����
ElemType edTails[M];//edTails[j]=data���� j ����β���������
int idx;
int n,m;//������������
map<ElemType,bool> flag;//��¼�Ƿ��ѱ�������δ��������flag�����ڣ�
ElemType qu[M];//BFS��������
map<ElemType,int> d;//���㵽���ľ���
int f=0,r=-1;
void AddEdge(ElemType dt1,ElemType dt2);
void BFS(ElemType stData);
int main(){
    int a,b;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        AddEdge(a,b);
    }
    ElemType st=1;//���������ͷ����������������һ��������㣨������ͷ���㣩
    BFS(st);//������ȱ���
    if(d.find(n)!=d.end()) cout<<d[n];
    else cout<<-1;
}
void AddEdge(ElemType dt1,ElemType dt2){
    if(fstEdge.find(dt1)==fstEdge.end()) fstEdge[dt1]=-1;//��ͷ�����һ�γ��֣���ʼ��fstEdgeΪ-1
    edTails[idx]=dt2;//����β��������
    nxtEdge[idx]=fstEdge[dt1]; fstEdge[dt1]=idx;//��dt1->dt2��ͷ�巨��ͷ����ĳ��߱�
    ++idx;
}
void BFS(ElemType stData){
    qu[++r]=stData;
    d[stData]=0;//��㵽����ľ���Ϊ0
    while(f<=r){
        ElemType hdData=qu[f++];//ȡ����ͷ
        for(int j=fstEdge[hdData];j!=-1;j=nxtEdge[j]){//������ͷ��β����
            ElemType tlData=edTails[j];
            if(d.find(tlData)==d.end()){//����ͷ��ǰβ����δ��������
                d[tlData]=d[hdData]+1;//���¶�ͷβ���㵽���ľ���
                qu[++r]=tlData;//β�������
            }
        }
    }
}
