# include <iostream>
# include <map>
using namespace std;
# define N 5000000//��������һ�㣡��������ֻ�������ʽ��󳤶ȣ���Ϊ������ֵ���������ڱ��ʽ���� �� 
char post[N];//���У���׺���ʽ�����ַ���ÿ����ֵ���á�\0��������
int tmp[N];//ջ���ݴ���ţ����׺���ʽʱ����ASCII�룩����ֵ������ʽ��ֵʱ����������
int r=-1, top=-1;;//��βָ�롢ջ��ָ��
map<char,int> pri={{'(',-1},{'+',0},{'-',0},{'*',1},{'/',1}};//���ȼ����˳�>�Ӽ�>������
int Calculation(char op,int x,int y);//��������
int main(){//���ʽ��ֵ���ٽ���׺���ʽת��Ϊ��׺���ʽ���ھݺ�׺���ʽ��ֵ
    string rpt;//���ַ���������ʽ
    cin>>rpt;
    int i=0, j;
    while(rpt[i]){//�� �Ƚ�ԭ��ѧ���ʽ����׺��ת��Ϊ��׺���ʽ�������post
        if(rpt[i]<='9'&&rpt[i]>='0'){//���֣��ҵ�������ֵ��λ������ӣ���'\0'����
            j=i;
            while(rpt[j]<='9'&&rpt[j]>='0')
                post[++r]=rpt[j++];
            post[++r]='\0'; i=j;//i���µ�j
        }
        else if('('==rpt[i]) tmp[++top]=rpt[i++]; //�����ţ�ֱ����ջ���ȴ�������ƥ��
        else if(')'==rpt[i]){//�����ţ�ջ����ջ�����ֱ�������ų�ջ�������Ų����
            while('('!=tmp[top]) post[++r]=tmp[top--];  --top;//�����ų�ջ
            ++i;
        }
        else{ //�������ջ����ջ�����ֱ��ջ�����ȼ�С�ڵ�ǰ���ţ�Ȼ��ǰ������ջ
            while(top>=0&&pri[rpt[i]]<=pri[tmp[top]]) post[++r]=tmp[top--];
            tmp[++top]=rpt[i++];//��ǰ������ջ
        }
    }
    while(top>=0) post[++r]=tmp[top--];//ջ�в����ķ���ȫ�����
    int x,y;
    i=0;
    while(i<=r){//�� �ݺ�׺���ʽ����ʽ��ֵ����ʼ״̬������Ϊ��׺���ʽ��ջ�գ�
        if(post[i]<='9'&&post[i]>='0'){//���֣�ȡ������ֵ��ֱ����ջ
                x=post[i]-'0'; j=i+1;
                while(post[j]) x=x*10+(post[j++]-'0');//��������ֵ������'\0'������
                tmp[++top]=x;//��ֵ��ջ
                i=j+1;//i���µ�'\0'��һλ
        }
        else{//�������ջ����ջ�����������㣬����������ջ
            y=tmp[top--]; x=tmp[top--];
            tmp[++top]=Calculation(post[i], x, y);
            ++i;
        }
    }//���������ջ��ֻ��һ�����������ս��
    cout<<tmp[top];
}
int Calculation(char op,int x,int y){
    switch (op) {
        case '+': return x+y;
        case '-': return x-y;
        case '/': return x/y;
        case '*': return x*y;
    }
}
