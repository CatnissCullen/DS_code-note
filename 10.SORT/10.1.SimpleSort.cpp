# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <math.h>
# define LENGTH 100000
/*˳���ṹ�����ݶ������飩*/
typedef struct{
    int* A;//A[0]���û��������ÿռ�
    int length;
}SqList;
FILE* fp=fopen("intfile.dat","r+");
long long int cnt1=0;//��¼�������ƶ��ܴ���
long long int cnt2=0;//��¼�Ƚϴ���
SqList list;
/*��ʼ��˳���*/
void InitializeList(){
    list.A=(int*)calloc(LENGTH+1,sizeof(int));
    list.length=LENGTH;
}
void CreateFile(){
    if(fp==NULL){
        printf("error-fail to open this file");
        exit(-1);
    }
    int x;
    srand((unsigned)time(0));
    for(int i=1;i<=list.length;++i){
        x=rand()%(LENGTH+1);
        fprintf(fp,"%d ",x);
    }
}
void FileToArray(){
    rewind(fp);
    for(int i=1;i<=list.length;++i){
        fscanf(fp,"%d",&list.A[i]);
    }
}
void ReverseArray(){
    int t;
    for(int i=1;i<=list.length/2;++i){
        t=list.A[i]; list.A[i]=list.A[list.length-i+1]; list.A[list.length-i+1]=t;
    }
}
void Swap(int &a,int &b,int t){
    t=a; a=b; b=t;
}
void OutPut(double duration,long long int times1,long long int times2){
    printf("Duration: %4.4f seconds.\n",duration);
    printf("Times of comparisons: %lld in total.\n", times2);
    printf("Times of swaps & moves: %lld in total.\n\n", times1);
}
/*ð�������ȶ���ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)����A[0]����������Ԫ�����ٻ��������*/
void BubbleSort(){
    clock_t startT,endT;
    double duration;
    FileToArray();
    cnt1=0; cnt2=0;
    startT=clock();//��ȡ������ʼʱ��
    for(int i=1;i<=list.length;++i){//iΪ����������ÿ������ʼʱflagΪ1������ѭ��
        for(int j=1;j<=list.length-i;++j){//jΪÿ��������ÿ�αȽ�ʱǰ��Ԫ�ص��±�
            if(list.A[j]>list.A[j+1]) {//��ǰ��Ԫ�ش��ں���Ԫ��
                Swap(list.A[j],list.A[j+1],list.A[0]);//����Ԫ��
                cnt1++;
            }
            cnt2++;
        }
    }
    endT=clock();//��ȡ��������ʱ��
    duration=(double)(endT-startT)/CLOCKS_PER_SEC;//����ʱ��
    printf("BUBBLE SORT\n");
    OutPut(duration,cnt1,cnt2);
}
/*��ѡ�����򣺲��ȶ���ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)����A[0]����������Ԫ�����ٻ�������ȫ����ֻ���ҵ���˳��ĵ�n��Ԫ�أ�*/
void SelectionSort(){
    clock_t startT,endT;
    double duration;
    FileToArray();
    cnt1=0; cnt2=0;
    startT=clock();//��ȡ������ʼʱ��
    int min;//��ǰ��Сֵ���±�
    for(int i=1;i<=list.length;++i){//iΪ��Ԫ��λ���±꣬��λ��1��ʼ����ѡ��������Ӧ�÷��ڸ�λ��i��Ԫ��
        min=i;//ѡ��λ��i��Ԫ��ʱ��min��ʼ��Ϊ��ǰi
        for(int j=i+1;j<=list.length;++j){
            if(list.A[j]<list.A[min])//��������ҵ��˱ȵ�ǰi��Ԫ��С��ֵ
                min=j;//��min��¼��Ԫ�ص��±꣬���������Ҹ�СԪ�ص��±�
            cnt2++;
        }
        if(min!=i){//ȫ������꣬����min��ֵ��ΪӦ�÷����±�iλ�õ�Ԫ���±�
            Swap(list.A[min],list.A[i],list.A[0]);//��min������ʼ��iֵ�����˸ı䣬�򽻻�Ԫ��
            cnt1++;
        }
    }
    endT=clock();//��ȡ��������ʱ��
    duration=(double)(endT-startT)/CLOCKS_PER_SEC;//����ʱ��
    printf("SELECTION SORT\n");
    OutPut(duration,cnt1,cnt2);
}
/*ֱ�Ӳ��������ȶ���ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)����A[0]����������Ԫ�����ٻ��������*/
void StraightInsertionSort(){
    clock_t startT,endT;
    double duration;
    FileToArray();
    cnt1=0; cnt2=0;
    startT=clock();//��ȡ������ʼʱ��
    for(int i=2;i<=list.length-1;i++){//iΪ��Ԫ��λ���±꣬��λ��2��ʼ�������Ƿ��ǰһλԪ��������ȷ
        if(list.A[i-1]>list.A[i]){//��ǰһλԪ�ظ���˵����Ҫ��i��Ԫ����ǰ�壨i-1����ǰ���ܻ��б�i�����Ԫ�أ�
            list.A[0]=list.A[i]; cnt1++;//���õ�0λΪA[i]�����ڱ��������������A[i]ԭ����ֵ������飨��Ϊ��λ��ʱ��ı�i����ֵ��
            int j;
            for(j=i;list.A[j-1]>list.A[0];j--){
                cnt2++;
                //��λ�ã�j��i��λ�ÿ�ʼ��ǰ��ǰһλԪ���Ƶ���ǰλ�ã�ֱ��ǰһλ��Ԫ�رȡ��ڱ���С
                list.A[j]=list.A[j-1]; cnt1++;
            }
            cnt2++;
            list.A[j]=list.A[0]; cnt1++;//�����ڱ�����������ڳ���λ�ã���j�������λ�ã�
        }
        cnt2++;
    }
    endT=clock();//��ȡ��������ʱ��
    duration=(double)(endT-startT)/CLOCKS_PER_SEC;//����ʱ��
    printf("STRAIGHT INSERTION SORT\n");
    OutPut(duration,cnt1,cnt2);
}
int main() {
	printf("For %d random numbers: \n",LENGTH);
    InitializeList();
    CreateFile();
    BubbleSort();
    SelectionSort();
    StraightInsertionSort();
    fclose(fp);
}
