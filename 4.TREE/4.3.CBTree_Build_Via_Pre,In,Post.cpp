#include <stdio.h>
#include <stdlib.h>
//注意！——判断某树是否完全二叉树：进行层序遍历，遇到空结点也入队，遇到空结点后还有非空结点则可退出循环并判为非完全 
int n, CBTree_lev[31];  // 结点的个数；层序存储完全二叉树的数组

void Build(int i){//据前序/中序/后序建立用层序表示的完全二叉树数组（层序序列第一个结点下标为1，即根结点） 
    if (i > n)
        return;
    // scanf("%d",&CBTree_lev[i]); //前序创建
    Build(2 * i);
    // scanf("%d",&CBTree_lev[i]); //中序创建
    Build(2 * i + 1);
    scanf("%d",&CBTree_lev[i]); //改变输入的位置，可以实现前序、中序或后序序列的创建完全二叉树
}

int main(){
    scanf("%d",&n);  
    Build(1);
    for (int i = 1; i <= n; i++)//输出层序 
    {
        if(i == 1)
            printf("%d",CBTree_lev[i]);
        if (i > 1)
            printf(" %d",CBTree_lev[i]);
    }
    return 0;
}
