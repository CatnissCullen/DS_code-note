//二叉查找树中求解数据项uv的最近公共祖先，返回祖先数据项的值 
int SearchLCA(BSTree p,int u,int v){//充分利用二叉排序树的特点，用比大小找最近公共祖先
    while(1){
        if(p->data>u&&p->data>v) p=p->LChild;
        else if(p->data<u&&p->data<v) p=p->RChild;
        else break;
    }
    return p->data;
}
