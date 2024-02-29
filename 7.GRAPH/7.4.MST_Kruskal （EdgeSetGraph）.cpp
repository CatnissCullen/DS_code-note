/*��̬�ڽӱ�Kruskal*/
# include <iostream>
# include <cstring>
# include <algorithm>
using namespace std;
# define ElemType int
# define WghType int
# define N 100010
# define M 2*N//����ͼ�������Ի����������Ϊ����������-1
typedef struct{
	ElemType a,b;
	WghType w;
}Edge;
Edge edges[M];//�߼����� 
int rts[N];//�������鼯 
int tLen;
int cntEd;//��¼��ǰ�Ѽ���ı��� 
int n,m; 
void Kruskal();
int main(){
    cin>>n>>m;
    for(int i=0;i<m;++i) scanf("%d%d%d",&edges[i].a,&edges[i].b,&edges[i].w);  
    Kruskal();
    if(cntEd<n-1) cout<<"impossible";
    else cout<<tLen;
}
bool CmpWeight(Edge a,Edge b){
	return a.w < b.w;
}
ElemType FindRoot(ElemType x){//�貢�鼯���Ҷ���x��������ͨ��ĸ���㣨�ж���������ͨ��ı�־�� 
	if(rts[x]!=x) rts[x]=FindRoot(rts[x]);
	return rts[x];//���ݹ��·��ѹ������
}//���õݹ�����·��ѹ�������Typora�ʼǣ����ܻᳬʱ
void Kruskal(){
	sort(edges,edges+m,CmpWeight);//��Ȩֵ��С�������� 
	for(int i=1;i<=n;++i) rts[i]=i;//��ʼ�����鼯
	for(int i=0;i<m;++i){//��С�������Ȩֵ����ı߼� 
		ElemType rt1=FindRoot(edges[i].a), rt2=FindRoot(edges[i].b);
		if(rt1!=rt2){
			rts[rt1]=rt2;
			tLen+=edges[i].w; ++cntEd;
		}
	}
}

