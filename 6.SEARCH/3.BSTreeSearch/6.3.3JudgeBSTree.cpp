//����������ж��Ƿ��Ƕ��������� 
BinTree pre = NULL;//����ǰ��ָ�� 
bool IsBST(BinTree T)
{
	if (!T) return 1;//�ո�����1�� 
	//��
	if (!IsBST(T->Left)) return 0;
	//��
	if (pre&&pre->Data > T->Data) return 0;//pre���ж��ǲ��ǿգ����ǿ��ټ���ִ��
	pre = T;//����preΪ��ǰ�� 
	//��
	if (!IsBST(T->Right)) return 0;
	return 1;//��󷵻�1�����ӡ������Һ��Ӷ���ȷ���� 
}
//������������ֵ�ж��Ƿ��Ƕ��������� 
bool IsBST(BinTree T)
{
	if (!T) return 1;//�ո�����1�� 
	if (!IsBST(T->Left) || !IsBST(T->Right)) return 0;//����ֵ�����˳���޹أ�������һ��ݹ��������� 
	//�������������ֵ���жϺ͸��Ĵ�С
	BinTree p = T->Left;//������һ�� 
	while (p&&p->Right) p = p->Right;//���ߵ��Ҿ�ͷ 
	if (p&&T->Data < p->Data) return 0;
	//������������Сֵ���жϺ͸��Ĵ�С
	BinTree p1 = T->Right;//������һ�� 
	while (p1&&p1->Left) p1 = p1->Left;//���ߵ���ͷ 
	if (p1&&T->Data > p1->Data) return 0;
	return 1;//��󷵻�1�����ӡ������Һ��Ӷ���ȷ���� 
} 
