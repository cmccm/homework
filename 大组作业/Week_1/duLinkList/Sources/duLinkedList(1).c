#include<stdio.h>
#include"duLinkedList.h"
#include<stdlib.h>

DuLNode* PList = NULL;

Status InitList_DuL(DuLinkedList* L)
{
	*L = (DuLinkedList)malloc(sizeof(DuLNode));
	(*L)->next = NULL;
	return SUCCESS;
}
void DestroyList_DuL(DuLinkedList* L)
{
	DuLinkedList p, q;
	p = (*L)->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	
	free(L);
}
Status InsertBeforeList_DuL(DuLinkedList* L, int i, ElemType e)
{
	DuLinkedList p, s;
	s = (DuLinkedList)malloc(sizeof(DuLNode));
	p = (*L);
	int cnt = 1;
	while (p && cnt < i) {
		cnt++;
		p = p->next;
	}
	if (!p)
		return ERROR;
	s->data = e;
	p->prior->next = s;
	s->prior = p->prior;
	p->prior = s;
	s->next = p;
	return SUCCESS;
}
Status InsertAfterList_DuL(DuLinkedList* L, int i, ElemType e)
{
	DuLinkedList p, s;
	s = (DuLinkedList)malloc(sizeof(DuLNode));
	p = (*L);
	int cnt = 1;
	while (p && cnt < i) {
		cnt++;
		p = p->next;
	}
	if (!p)
		return ERROR;
	
	s->data = e;
	s->next = p->next;
	p->next->prior = s;
	p->next = s;
	s->prior = p;
	return SUCCESS;
}
void Boa()
{
	int j;
	int Data;
	int k;
	printf("��ѡ�����ķ���\n");
	printf("1.������ѡ����ǰ��\n");
	printf("2.������ѡ���ĺ���\n");
	scanf_s("%d", &k);
	switch (k)
	{
	case 1:
		printf("������Ҫ����Ľ��λ��\n");
		scanf_s("%d", &j);
		printf("������Ҫ����Ľ������\n");
		scanf_s("%d", &Data);
		InsertBeforeList_DuL(&PList, j, Data);
		break;
	case 2:
		printf("������Ҫ����Ľ��λ��\n");
		scanf_s("%d", &j);
		printf("������Ҫ����Ľ������\n");
		scanf_s("%d", &Data);
		InsertAfterList_DuL(&PList, j, Data);
	}
}
Status DeleteList_DuL(DuLinkedList* L, int i, ElemType* e)
{
	int cnt = 1;
	DuLinkedList q, p;
	p = (*L);
	while (p->next && cnt < i) {
		p = p->next;
		cnt++;
	}
	if (!(p->next))
		return ERROR;
	q = p->next;
	p->next = q->next;
	q->next->prior = p;
	*e = q->data;
	free(q);
	return SUCCESS;
}
void visit(ElemType e)
{
	printf("�ý���ֵΪ%d\n", e);
}
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	DuLinkedList p;
	p = L->next;
	if (L = NULL)
	{
		printf("����Ϊ��\n");
	}

	while (p)
	{
		visit(p->data);
		p = p->next;
	}
}
int main()
{
	
	ElemType e;
	int chioce;
	int j;
	InitList_DuL(&PList);
	while(1)
	{
	printf("������Ҫʵ�ֵĹ���\n");
	printf("1.�������\n");
	printf("2.������\n");
	printf("3.ɾ��ָ�����\n");
	printf("4.������������\n");
	scanf_s("%d", &chioce);
	switch (chioce)
	{
	case 1:
		DestroyList_DuL(&PList);
		break;
	case 2:
		Boa();
		break;
	case 3:
		printf("������Ҫɾ���Ľ��λ��\n");
		scanf_s("%d", &j);
		DeleteList_DuL(&PList, j, &e);
		break;
	case 4:
		TraverseList_DuL(PList, visit);
		break;
	}

}
}