/*�������ģ�������ָ���е�һ����㣬����������ɾ����ʣ�������ͨ���е��������ֵ��С����ô����ڵ㱻��Ϊ�������ġ�
�����Ķ�Ӧ����ͨ���е��������ֵ*/
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
int minRes;//��С����ͨ�������������ս��������Ϊȫ�ֱ�������ÿ��DFS�ݹ鶼���Ը��µ�
map<ElemType,bool> flag;//��¼�Ƿ��ѱ�������δ��������flag�����ڣ�
void AddEdge(ElemType dt1,ElemType dt2);
int DFS(ElemType hdData);
int main(){
    int a,b;
    cin>>n; m=n-1;
    minRes=n;//��ʼ��miResΪ�ܶ�����
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        AddEdge(a,b);//����ͼ��Ҫ�ԳƵؼ�������
        AddEdge(b,a);
    }
    ElemType st=1;//���������������������һ���������
    DFS(1);//main�����в���ҪDFS�ķ��ؽ������Ϊ���ص���sum
    cout<<minRes;//������ȱ�������С�� ��ͨ����󶥵���
}
void AddEdge(ElemType dt1,ElemType dt2){
    if(fstEdge.find(dt1)==fstEdge.end()) fstEdge[dt1]=-1;//��ͷ�����һ�γ��֣���ʼ��fstEdgeΪ-1
    edTails[idx]=dt2;//����β��������
    nxtEdge[idx]=fstEdge[dt1]; fstEdge[dt1]=idx;//��dt1->dt2��ͷ�巨��ͷ����ĳ��߱�
    ++idx;
}
int  DFS(ElemType hdData){//������hdDataΪ���������еĶ�����
    flag[hdData]=true;
    int sum=1;//�����ܶ�����
    int res=0;//ɾ���ø�����ÿ����ͨ��Ķ����������ϸ������յõ����ֵ
    for(int j=fstEdge[hdData];j!=-1;j=nxtEdge[j]){//ѭ����������������β���㣬������������ͨ��Ķ�����
        int tlData=edTails[j];
        if(flag.find(tlData)==flag.end()){
            int tRes=DFS(tlData);//�ݹ�õ���ǰβ�����������ͨ���ϵ��ܶ�������
            // һ������ͨ�顱����β���㿪ʼ��һ������֧·����β����Ϊ������������
            if(tRes>res) res=tRes;//�ص�ͷ����ݹ�㣬�жϣ�����ǰβ����������ͨ��Ķ�����>res�������res
            sum+=tRes;//���������ܶ�����
        }
    }//�õ���β����������ͨ�鶥�����е����ֵ
    int tRes=n-sum;//����ǰ���������ɾ�����䶥�ϵ���ͨ�鶥��������������ȥ��ǰ�����Ĳ��֣�
    if(tRes>res) res=tRes;
    if(res<minRes) minRes=res;//ÿ��ݹ������󶥵����뵱ǰminRes�Ƚϣ�����minResΪ��С����󶥵���
    return sum;
}
