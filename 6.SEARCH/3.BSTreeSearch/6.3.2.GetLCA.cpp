//��������������������uv������������ȣ����������������ֵ 
int SearchLCA(BSTree p,int u,int v){//������ö������������ص㣬�ñȴ�С�������������
    while(1){
        if(p->data>u&&p->data>v) p=p->LChild;
        else if(p->data<u&&p->data<v) p=p->RChild;
        else break;
    }
    return p->data;
}
