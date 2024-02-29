//1. ����ǰ����������ս�㣩������
//2. ����ǰ���������������������ս�㣩������
//3. ���ݺ����������������������ս�㣩������
//4. ���ݲ����������������������ս�㣩������
//����ǰ�������������������������������������������ȣ�����v�Ƿ���u������
# include <iostream>
# include <algorithm>
using namespace std;
# define ElemType char
typedef struct node{
    ElemType dta;
    struct node* LChild;
    struct node* RChild;
}Node;
string tree1,tree2;
int idx;
Node* Rt;
void BuildBTree_Pre(Node* &rt); void BuildBTree_Pre_In(Node* &rt,int l,int r); void BuildBTree_Post_In(Node* &rt,int l,int r); void BuildBTree_Lev_In(Node* &rt,string levTrv);
void PreTrv(Node* rt); void InTrv(Node* rt); void PostTrv(Node* rt); int Depth(Node* rt); Node* Find(Node* rt,char x);
int main(){
    int op; int n;
    cin>>op;
    switch(op){
        case 1: cin>>tree1; BuildBTree_Pre(Rt); break;
        case 2: cin>>tree1>>tree2; idx=0; BuildBTree_Pre_In(Rt,0,tree2.size()-1); break;
        case 3: cin>>tree1>>tree2; idx=tree1.size()-1; BuildBTree_Post_In(Rt,0,tree2.size()-1); break;
        case 4: cin>>tree1>>tree2; idx=0;BuildBTree_Lev_In(Rt,tree1.c_str()); break;
    }
    PreTrv(Rt); cout<<endl;
    InTrv(Rt); cout<<endl;
    PostTrv(Rt); cout<<endl;
    cout<<Depth(Rt)<<endl;
    char u[2],v[2];
    scanf("%s%s",u,v);
    Node* rt=Find(Rt,u[0]);
    Node* p=Find(rt,v[0]);
    if(p) cout<<"Yes";
    else cout<<"No";
}
void BuildBTree_Pre(Node* &rt){//��#��ʾ�ս��
    char c=tree1[idx++];                                    //��ȡ�Ӹ��������
    if(c!='#'){ rt=new Node[1]; rt->dta=c; }           //����㲻�գ������Ӹ����
    else{ rt=NULL; return; }                               //�����գ�ָ�븳�գ���������һ��������ָ���������ֵ����������
    BuildBTree_Pre(rt->LChild);                     //��������Ϊ�Ӹ���㣬�ݹ�����������
    BuildBTree_Pre(rt->RChild);                     //�����Һ���Ϊ�Ӹ���㣬�ݹ�����������
}//�ݹ��������ң���Ϊǰ�������������ҵ��Ӹ����
void BuildBTree_Pre_In(Node* &rt,int l,int r){//��ǰ��tree1����ȡ����㣬���������򻮷ֳ���������������
    if(l>r){ rt=NULL; return; }                                                    //�������գ�ָ�븳�գ�����
    rt=new Node[1]; rt->dta=tree1[idx++];                                   //�����Ӹ���㣨ǰ���к�һ����
    int i=0;
    while(1){
        if(rt->dta==tree2[i]) break;                                              //���������ҵ����Ӹ���㣬��Ϊ���������ֽ�
        else ++i;
    }
    BuildBTree_Pre_In(rt->LChild,l,i-1);                              //��������Ϊ�Ӹ���㣬�ݹ�����������
    BuildBTree_Pre_In(rt->RChild,i+1,r);                              //�����Һ���Ϊ�Ӹ���㣬�ݹ�����������
}//�ݹ��������ң���Ϊǰ�������������ҵ��Ӹ����
void BuildBTree_Post_In(Node* &rt,int l,int r){//�ú���tree1����ȡ����㣬���������򻮷ֳ���������������
    if(l>r){ rt=NULL; return; }                                                    //�������գ�ָ�븳�գ�����
    rt=new Node[1]; rt->dta=tree1[idx--];                                  //�����Ӹ���㣨������ǰһ����
    int i=0;
    while(1){
        if(rt->dta==tree2[i]) break;                                             //���������ҵ����Ӹ���㣬��Ϊ���������ֽ�
        else ++i;
    }
    BuildBTree_Post_In(rt->RChild,i+1,r);                            //�����Һ���Ϊ�Ӹ���㣬�ݹ�����������
    BuildBTree_Post_In(rt->LChild,l,i-1);                            //��������Ϊ�Ӹ���㣬�ݹ�����������
}//�ݹ�����������Ϊ������������������Ӹ����
void BuildBTree_Lev_In(Node* &rt,string levTrv){//�ò���tree1����ȡ����㣬���������򻮷ֳ���������������
    if(!levTrv.size()){ rt=NULL; return; }                                       //�������գ�ָ�븳�գ�����
    rt=new Node[1]; rt->dta=levTrv[0];                                      //�����Ӹ���㣨�����е�һ����
    int i=0;
    while(1){
        if(rt->dta==tree2[i]) break;                                             //���������ҵ����Ӹ���㣬��Ϊ���������ֽ�
        else ++i;
    }
    string levTrv_L,levTrv_R;                                                     //���������Ӳ���
    for(int j=1;j<levTrv.size();++j){                                               //���Ӹ����Ϊ�磬�������������������Ӳ���
        for(int k=0;k<tree2.size();++k)
            if(tree2[k]==levTrv[j]){
                if(k<i) levTrv_L.push_back(tree2[k]);
                if(k>i) levTrv_R.push_back(tree2[k]);
                break;
            }
    }
    BuildBTree_Lev_In(rt->LChild,levTrv_L);                 //������Ϊ�Ӹ���㣬�ݹ����������������������
    BuildBTree_Lev_In(rt->RChild,levTrv_R);                //���Һ���Ϊ�Ӹ���㣬�ݹ����������������������
}//�ݹ��Ⱥ�˳������
void PreTrv(Node* rt){
    if(!rt) return;
    printf("%c ",rt->dta);
    PreTrv(rt->LChild);
    PreTrv(rt->RChild);
}
void InTrv(Node* rt){
    if(!rt) return;
    InTrv(rt->LChild);
    printf("%c ",rt->dta);
    InTrv(rt->RChild);
}
void PostTrv(Node* rt){
    if(!rt) return;
    PostTrv(rt->LChild);
    PostTrv(rt->RChild);
    printf("%c ",rt->dta);
}
void LevTrv(Node* rt){
    if(!rt) return;
    Node* q[8000]; int f=0,r=0;
    q[r++]=rt;
    do{
        Node* t=q[f++];
        printf(" %c",t->dta);
        if(t->LChild) q[r++]=t->LChild;
        if(t->RChild) q[r++]=t->RChild;
    }while(f<r);
}
int Depth(Node* rt){
    if(!rt) return 0;
    return 1+max(Depth(rt->LChild), Depth(rt->RChild));
}
Node* Find(Node* rt,char x){//��rt����������x��㣨��x�Ƿ���rt����� 
    if(!rt) return NULL;
    else if(x==rt->dta) return rt;
    else if(Find(rt->LChild, x)) return Find(rt->LChild, x);
    else if(Find(rt->RChild, x)) return Find(rt->RChild, x);
    else return NULL;
}

