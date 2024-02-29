//ע�⣡��-- 
//���Զ�����������ǰ�����Ϊ�������н�����ǰ�������Ϊԭǰ������� 
//���Զ����������ĺ�������ĵ���Ϊ�������н����ĺ��������Ϊԭ��������� 
# include <iostream>
using namespace std;
# define N 100100
# define ElemType int
# define Address int
typedef struct{
    ElemType dta;
    Address l, r;
}BSTNode;
BSTNode tree[N];
int flg[N];//��¼����Ƿ�Ϊ��
int idx;
int rt;//��¼������ַ���Է�����㱻ɾ��������ʼΪ0
int n;
int Search(ElemType x, Address &p);
void Add(ElemType x);
void Delete(ElemType x);
int main(){
    cin>>n;
    int key;
    for(int i=0; i<n; ++i){
        cin>>key; Add(key);//��ӽ�㣨������
    }
    int q;
    cin>>q;
    while(q--){//ɾ��q�����
        cin>>key; Delete(key);
    }
    cin>>q;
    while(q--){//����q�����
        int p,t;
        cin>>key; t=Search(key,p);
        if(!t) cout<<"Not found"<<endl;
        else{
            if(key<tree[p].dta) cout<<tree[p].l;
            else cout<<tree[p].r;
        }
    }
}
int Search(ElemType x, Address &p) {
    p=-1;//����㣨����㸸�����Ϊ-1��
    Address i=rt;
    while(1){
        if(!flg[i]) return 0;//δ�ҵ�������0�����ؿս�㸸���
        else{//flg[i]==1
            if(tree[i].dta==x) return 1;//�ҵ�������֮һ��������1���������ڽ�㸸���
            else{//��δ�ҵ�
                p=i;
                if(x<tree[p].dta) i=tree[i].l;//��������
                else i=tree[i].r;//��������
            }
        }
    }
}
void Add(ElemType x){//С�����󣬴��ڵ������ң�������̬����������ݴ�С�����йأ�����ӵı��ǵ�ǰ����Ҷ�ӣ�
    Address p;//�����
    flg[idx]=1;
    Search(x,p);//�Ȳ��ң���������ظ�Ԫ�أ������ַ���ֵ
    if(-1==p) rt=idx;//�����������ø�����ַΪidx
    else{//������
        if(x<tree[p].dta) tree[p].l=idx;//�����ӣ����ӵ�ַidx
        else tree[idx].dta=x;//���Һ��ӣ����ӵ�ַidx
    }
    tree[idx++].dta=x;//��������
}
void Delete(ElemType x){
    Address p, i;//����㡢��ɾ�����
    int t=Search(x,p);
    if(!t) return;//�޿�ɾ��
    if(x<tree[p].dta){ i=tree[p].l; tree[p].l=0; }
    else{ i=tree[p].r; tree[p].r=0; }
    flg[i]=0;
    if(!tree[i].l&&!tree[i].r) return;//�ٱ�ɾ�������Ҷ�ӽ��
    if((!tree[i].l&&tree[i].r)||(tree[i].l&&!tree[i].r)){//�ڱ�ɾ�����ֻ�е�������
        if(x<tree[p].dta){
            if(tree[i].l) tree[p].l=tree[i].l;
            else tree[p].l=tree[i].r; }
        else{
            if(tree[i].l) tree[p].r=tree[i].l;
            else tree[p].r=tree[i].r; }
    }
    if(tree[i].l&&tree[i].r){//�۱�ɾ�������˫��������ʹ�Һ�������Ϊ����㣬�����������ӵ���������֧ĩ��
        if(x<tree[p].dta) tree[p].l=tree[i].r;
        else tree[p].r=tree[i].r;
        Address j=tree[i].r;
        while(tree[j].l) j=tree[j].l;
        tree[j].l=tree[i].l;
    }
}
