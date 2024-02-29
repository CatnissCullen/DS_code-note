# include <iostream>
# include <string.h>
# include <algorithm>
using namespace std;
# define N 100010
int heap[N],heapSize;//С���ѣ�heap����ֵ�Ĳ������ 
int nodeNums[N];//��Ų������Ϊi��Ԫ�صĲ������nodeNums[i]
int nodeIndexes[N];//��ŵ�j�������Ԫ���ڶ��е�����nodeIndexes[j]
void down(int k);//��֪k��Ԫ�ر��Ϸ�Ԫ�ض��󣬽����³���λ 
void up(int k);//��֪k��Ԫ�ر��·�Ԫ�ض�С�������ϸ���λ 
void Swap(int a_index,int b_index);
int main(){
    int n,cnt=0;//cnt��¼�������
    cin>>n;
    while(n--){
        char op[5];
        int j,x;
        scanf("%s",op);
        if(strcmp(op,"I")==0){
		//�����������ԭ��Ϊ�նѣ����н��ֵΪ����ֵ������0x3f3f3f3f�� 
		//��������ѣ���ͬ�ڶ����򣡣��������Ƕ��Ҷѵĵ������� 
            scanf("%d",&x); ++heapSize; ++cnt;
            heap[heapSize]=x;//�ȷŵ���β
            nodeIndexes[cnt]=heapSize; nodeNums[heapSize]=cnt;
            up(heapSize);//���ϸ�
        }
        else if(strcmp(op,"PM")==0) printf("%d\n",heap[1]);//�����Сֵ����
        else if(strcmp(op,"DM")==0){//ɾ����Сֵ������ά���ѣ���ָ������ѵ�ά������ 
            Swap(1,heapSize);//�Ƚ�����β�ͶѶ�����Сֵ��
            --heapSize;//ɾ����β
            down(1);//���µ�����
        }
        else if(strcmp(op,"D")==0){//ɾ����j������Ľ�������ά���ѣ���ָ������ѵ�ά������ 
            scanf("%d",&j);
            int i=nodeIndexes[j];
            Swap(i,heapSize);//�Ƚ�����β��i
            --heapSize;//ɾ����β
            down(i); up(i);//i��Ϊԭ��βԪ�أ����µ�����Ϊi�Ž����Ӷ�
        }
        else{//�޸ĵ�j������Ľ�������ά���ѣ���ָ������ѵ�ά������ 
            scanf("%d%d",&j,&x);
            int i=nodeIndexes[j];
            heap[i]=x;
            down(i); up(i);//���µ���λ��i
        }
    }
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
void up(int k){//��֪k��Ԫ�ر��·�Ԫ�ض�С�������ϸ���λ 
    if(k/2>0&&b[k]<b[k/2]){
        Swap(k,k/2);
        up(k/2);
    }
}
void Swap(int a_Index,int b_Index){//���������������н���������������ݵ��������������������ݽ��� 
    swap(heap[a_Index],heap[b_Index]);
    swap(nodeIndexes[nodeNums[a_Index]],nodeIndexes[nodeNums[b_Index]]);
    swap(nodeNums[a_Index],nodeNums[b_Index]);
}
