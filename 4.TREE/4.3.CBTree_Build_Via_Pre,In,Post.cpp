#include <stdio.h>
#include <stdlib.h>
//ע�⣡�����ж�ĳ���Ƿ���ȫ�����������в�������������ս��Ҳ��ӣ������ս����зǿս������˳�ѭ������Ϊ����ȫ 
int n, CBTree_lev[31];  // ���ĸ���������洢��ȫ������������

void Build(int i){//��ǰ��/����/�������ò����ʾ����ȫ���������飨�������е�һ������±�Ϊ1��������㣩 
    if (i > n)
        return;
    // scanf("%d",&CBTree_lev[i]); //ǰ�򴴽�
    Build(2 * i);
    // scanf("%d",&CBTree_lev[i]); //���򴴽�
    Build(2 * i + 1);
    scanf("%d",&CBTree_lev[i]); //�ı������λ�ã�����ʵ��ǰ�������������еĴ�����ȫ������
}

int main(){
    scanf("%d",&n);  
    Build(1);
    for (int i = 1; i <= n; i++)//������� 
    {
        if(i == 1)
            printf("%d",CBTree_lev[i]);
        if (i > 1)
            printf(" %d",CBTree_lev[i]);
    }
    return 0;
}
