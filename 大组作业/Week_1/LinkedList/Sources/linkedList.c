#include<stdio.h>
#include"linkedList.h"
#include<stdlib.h>

Status InitList(LinkedList* L)
{
	*L = (LinkedList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	return SUCCESS;
}
void DestroyList(LinkedList* L)
{
	LinkedList p, q;
	p = (*L)->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	free(L);
}
Status insertList(LinkedList* L, int i, ElemType e)
{
	LinkedList p, s;
	p = (*L);
	int cnt = 1;
	while (p && cnt < i) {
		cnt++;
		p = p->next;
	}
	if (!p)
		return ERROR;
	s = (LinkedList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return SUCCESS;
}

Status deleteList(LinkedList* L, int i, ElemType* e)
{
	int cnt = 1;
	LinkedList q, p;
	p = (*L);
	while (p->next && cnt < i) {
		p = p->next;
		cnt++;
	}
	if (!(p->next))
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return SUCCESS;
	
}
void visit(ElemType e)
{
	printf("该节点的值为%d\n",e);
}
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	LinkedList p;
	p = L->next;
	if (L=NULL)  
	{
		printf("链表为空%d\n");
	}

	while (p)
	{
		visit(p->data);
		p = p->next;
	}
}
Status SearchList(LinkedList L, ElemType e)
{
	int i = 0;
	LinkedList p = L->next;

	while (p) {
		i++;
		if (p->data == e)
			return i;

		p = p->next;
	}
	return 0;
}
int main()
{
	LNode* PList = NULL;
	ElemType e;
	InitList(&PList);
	int chioce;
	int j;
	int Data;
	while (1) {
		printf("请输入要实现的功能\n");
		printf("1.清空链表\n");
		printf("2.插入节点\n");
		printf("3.删除指定节点\n");
		printf("4.遍历链表并访问\n");
		printf("5.搜索指定链表\n");
		scanf_s("%d", &chioce);
		switch (chioce)
		{
		case 1:
			DestroyList(&PList);
			break;
		case 2:
			printf("请输入要插入的节点位置\n");
			scanf_s("%d", &j);
			printf("请输入要插入的节点数据\n");

			scanf_s("%d", &Data);
			insertList(&PList, j, Data);
			break;
		case 3:

			printf("请输入要删除的节点数据\n");
			scanf_s("%d", &j);
			deleteList(&PList, j, &e);
			break;
		case 4:
			TraverseList(PList, visit);
			break;
		case 5:
			printf("请输入要搜寻的节点数据\n");
			scanf_s("%d", &Data);
			SearchList(PList, Data);
			printf("搜索的节点位置在%d\n", SearchList(PList, Data));
			break;
		}

	}
}