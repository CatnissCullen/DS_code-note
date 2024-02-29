//1. 根据前序遍历（含空结点）建树；
//2. 根据前序遍历和中序遍历（不含空结点）建树；
//3. 根据后序遍历和中序遍历（不含空结点）建树；
//4. 根据层序遍历和中序遍历（不含空结点）建树；
//生成前序遍历、中序遍历、后序遍历、层序遍历并求层数（深度）、求v是否是u的子孙
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
void BuildBTree_Pre(Node* &rt){//用#表示空结点
    char c=tree1[idx++];                                    //获取子根结点数据
    if(c!='#'){ rt=new Node[1]; rt->dta=c; }           //若结点不空，生成子根结点
    else{ rt=NULL; return; }                               //若结点空，指针赋空（必须有这一步，否则指针会是任意值！），回溯
    BuildBTree_Pre(rt->LChild);                     //先以左孩子为子根结点，递归生成左子树
    BuildBTree_Pre(rt->RChild);                     //再以右孩子为子根结点，递归生成右子树
}//递归先左再右，因为前序中是先左再右的子根结点
void BuildBTree_Pre_In(Node* &rt,int l,int r){//用前序（tree1）获取根结点，用来将中序划分成左子树与右子树
    if(l>r){ rt=NULL; return; }                                                    //若子树空，指针赋空，回溯
    rt=new Node[1]; rt->dta=tree1[idx++];                                   //生成子根结点（前序中后一个）
    int i=0;
    while(1){
        if(rt->dta==tree2[i]) break;                                              //在中序中找到该子根结点，作为左右子树分界
        else ++i;
    }
    BuildBTree_Pre_In(rt->LChild,l,i-1);                              //先以左孩子为子根结点，递归生成左子树
    BuildBTree_Pre_In(rt->RChild,i+1,r);                              //再以右孩子为子根结点，递归生成右子树
}//递归先左再右，因为前序中是先左再右的子根结点
void BuildBTree_Post_In(Node* &rt,int l,int r){//用后序（tree1）获取根结点，用来将中序划分成左子树与右子树
    if(l>r){ rt=NULL; return; }                                                    //若子树空，指针赋空，回溯
    rt=new Node[1]; rt->dta=tree1[idx--];                                  //生成子根结点（后序中前一个）
    int i=0;
    while(1){
        if(rt->dta==tree2[i]) break;                                             //在中序中找到该子根结点，作为左右子树分界
        else ++i;
    }
    BuildBTree_Post_In(rt->RChild,i+1,r);                            //先以右孩子为子根结点，递归生成右子树
    BuildBTree_Post_In(rt->LChild,l,i-1);                            //再以左孩子为子根结点，递归生成左子树
}//递归先右再左，因为后序中是先右再左的子根结点
void BuildBTree_Lev_In(Node* &rt,string levTrv){//用层序（tree1）获取根结点，用来将中序划分成左子树和右子树
    if(!levTrv.size()){ rt=NULL; return; }                                       //若子树空，指针赋空，回溯
    rt=new Node[1]; rt->dta=levTrv[0];                                      //生成子根结点（层序中第一个）
    int i=0;
    while(1){
        if(rt->dta==tree2[i]) break;                                             //在中序中找到该子根结点，作为左右子树分界
        else ++i;
    }
    string levTrv_L,levTrv_R;                                                     //开辟左右子层序
    for(int j=1;j<levTrv.size();++j){                                               //以子根结点为界，据中序分配层序至左右子层序
        for(int k=0;k<tree2.size();++k)
            if(tree2[k]==levTrv[j]){
                if(k<i) levTrv_L.push_back(tree2[k]);
                if(k>i) levTrv_R.push_back(tree2[k]);
                break;
            }
    }
    BuildBTree_Lev_In(rt->LChild,levTrv_L);                 //以左孩子为子根结点，递归生成左子树（传入左层序）
    BuildBTree_Lev_In(rt->RChild,levTrv_R);                //以右孩子为子根结点，递归生成左子树（传入左层序）
}//递归先后顺序任意
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
Node* Find(Node* rt,char x){//在rt的子树中找x结点（求x是否是rt的子孙） 
    if(!rt) return NULL;
    else if(x==rt->dta) return rt;
    else if(Find(rt->LChild, x)) return Find(rt->LChild, x);
    else if(Find(rt->RChild, x)) return Find(rt->RChild, x);
    else return NULL;
}

