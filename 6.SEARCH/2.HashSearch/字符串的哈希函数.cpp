/*���ַ��������֣��Ĺ�ϣ����������*/
//MAXSIZE�ǹ�ϣ�������Ч�洢���ȣ���1�� 
int GetHashIndex(char* FName){
    unsigned long long index=0;
    unsigned long long a=12345,b=67891;
    //������ֵ
    while(*FName){
        index=(index*a+*FName)%MAXSIZE;
        FName++; a*=b;
    }
    return index+1;
}
//����������һ�������¼��Ч��ϣ����ֵ 
