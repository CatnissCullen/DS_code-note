# include <iostream>
using namespace std;
# define N 100010
int heap[N],heapSize;//С���ѣ�heap����ֵ�Ĳ������ 
void down(int k);//��֪k��Ԫ�ر��Ϸ�Ԫ�ض��󣬽����³���λ 
int main(){
    int n,m;
    cin>>n>>m; heapSize=n;
    for(int i=1;i<=n;++i) scanf("%d",&heap[i]);//��1���� 
    //С�������� �������ʣ��������ϣ��������һ�㣬������Ԫ��С���·�Ԫ�أ�������Ϊ����ֵ������0x3f3f3f3f����
	//�Ժ�ÿ��һ��� down()һ�㣬��ǰ������Ԫ�ؾ������Ϸ�Ԫ�أ�������Ϊ��Сֵ������-0x3f3f3f3f�� �� 
	//Ϊ����ݲ���ȡ�������ӵ����ڶ���ĩ�˿�ʼ�ص���������� down()��㣬ʱ�临�Ӷ� O(n)
	//���Ҷ����򻯣�Ҳ�������ն������ò����㷽�����ѡ� 
    for(int i=n/2;i>0;--i) down(i); 
    while(m--){//�����С����Ķ���������
        printf("%d ",heap[1]);//�ȴ�ӡ�Ѷ�
        heap[1]=heap[heapSize]; --heapSize; down(1);//��ɾ���Ѷ������µ����� ��ά���ѣ���ָ������ѵ�ά������ 
    }
}
void Swap(int &a,int &b){
    a^=b; b^=a; a^=b;
}
void down(int k){//��֪k��Ԫ�ر��Ϸ�Ԫ�ض��󣬽����³���λ 
    int t=k;
    //�ҵ���kΪ��������С�Ӷ��У�������㣩ֵ��С�Ľ�㣨t�ţ� 
    if(2*k<=heapSize&&heap[2*k]<heap[t]) t=2*k;
    if(2*k+1<=heapSize&&heap[2*k+1]<heap[t]) t=2*k+1;
    if(t!=k){ 
        Swap(k,t);//������ǰ����k�Ž�㣩��t�Ž��Ԫ�� 
        down(t);//t��λԪ���иĶ����������µ�������Ϊ�����Ӷ�
    }
}

