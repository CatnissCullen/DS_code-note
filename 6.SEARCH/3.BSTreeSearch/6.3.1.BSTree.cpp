//注意！！-- 
//①以二叉搜索树的前序遍历为建树序列建树的前序遍历必为原前序遍历； 
//②以二叉搜索树的后序遍历的倒序为建树序列建树的后序遍历必为原后序遍历。 
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
int flg[N];//记录结点是否为空
int idx;
int rt;//记录根结点地址（以防根结点被删除），初始为0
int n;
int Search(ElemType x, Address &p);
void Add(ElemType x);
void Delete(ElemType x);
int main(){
    cin>>n;
    int key;
    for(int i=0; i<n; ++i){
        cin>>key; Add(key);//添加结点（建树）
    }
    int q;
    cin>>q;
    while(q--){//删除q个结点
        cin>>key; Delete(key);
    }
    cin>>q;
    while(q--){//查找q个结点
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
    p=-1;//父结点（根结点父结点设为-1）
    Address i=rt;
    while(1){
        if(!flg[i]) return 0;//未找到，返回0，传回空结点父结点
        else{//flg[i]==1
            if(tree[i].dta==x) return 1;//找到（其中之一），返回1，传回所在结点父结点
            else{//暂未找到
                p=i;
                if(x<tree[p].dta) i=tree[i].l;//在左子树
                else i=tree[i].r;//在右子树
            }
        }
    }
}
void Add(ElemType x){//小于往左，大于等于往右（树的形态与输入的数据大小次序有关；新添加的必是当前树的叶子）
    Address p;//父结点
    flg[idx]=1;
    Search(x,p);//先查找，允许添加重复元素，不区分返回值
    if(-1==p) rt=idx;//在树根，设置根结点地址为idx
    else{//非树根
        if(x<tree[p].dta) tree[p].l=idx;//在左孩子，链接地址idx
        else tree[idx].dta=x;//在右孩子，链接地址idx
    }
    tree[idx++].dta=x;//填入数据
}
void Delete(ElemType x){
    Address p, i;//父结点、被删除结点
    int t=Search(x,p);
    if(!t) return;//无可删除
    if(x<tree[p].dta){ i=tree[p].l; tree[p].l=0; }
    else{ i=tree[p].r; tree[p].r=0; }
    flg[i]=0;
    if(!tree[i].l&&!tree[i].r) return;//①被删除结点是叶子结点
    if((!tree[i].l&&tree[i].r)||(tree[i].l&&!tree[i].r)){//②被删除结点只有单边子树
        if(x<tree[p].dta){
            if(tree[i].l) tree[p].l=tree[i].l;
            else tree[p].l=tree[i].r; }
        else{
            if(tree[i].l) tree[p].r=tree[i].l;
            else tree[p].r=tree[i].r; }
    }
    if(tree[i].l&&tree[i].r){//③被删除结点有双边子树：使右孩子上升为父结点，并将左子树接到右子树左支末端
        if(x<tree[p].dta) tree[p].l=tree[i].r;
        else tree[p].r=tree[i].r;
        Address j=tree[i].r;
        while(tree[j].l) j=tree[j].l;
        tree[j].l=tree[i].l;
    }
}
