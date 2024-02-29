//用中序遍历判断是否是二叉搜索树 
BinTree pre = NULL;//申请前驱指针 
bool IsBST(BinTree T)
{
	if (!T) return 1;//空根返回1！ 
	//左
	if (!IsBST(T->Left)) return 0;
	//根
	if (pre&&pre->Data > T->Data) return 0;//pre得判断是不是空，不是空再继续执行
	pre = T;//更新pre为当前根 
	//右
	if (!IsBST(T->Right)) return 0;
	return 1;//最后返回1（左孩子、自身、右孩子都正确）！ 
}
//用左右子树最值判断是否是二叉搜索树 
bool IsBST(BinTree T)
{
	if (!T) return 1;//空根返回1！ 
	if (!IsBST(T->Left) || !IsBST(T->Right)) return 0;//找最值与遍历顺序无关，可以先一起递归左右子树 
	//找左子树的最大值，判断和根的大小
	BinTree p = T->Left;//先往左一步 
	while (p&&p->Right) p = p->Right;//再走到右尽头 
	if (p&&T->Data < p->Data) return 0;
	//找右子树的最小值，判断和根的大小
	BinTree p1 = T->Right;//先往右一步 
	while (p1&&p1->Left) p1 = p1->Left;//再走到左尽头 
	if (p1&&T->Data > p1->Data) return 0;
	return 1;//最后返回1（左孩子、自身、右孩子都正确）！ 
} 
