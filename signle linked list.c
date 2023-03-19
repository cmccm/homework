#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkedList;
typedef enum Status{
    error,
    success
} Status;

//����������
Status InitList(LinkedList *L);
void DestroyList(LinkedList *L);
Status InsertList(LNode *p, ElemType data);
Status DeleteList(LNode *p, ElemType e);
void TraverseList(LinkedList L);
Status SearchList(LinkedList L, ElemType e);
Status ReverseList(LinkedList *L);
Status IsLoopList(LinkedList L);
LNode* FindMidNode(LinkedList L);
void show(void);
int judge_int(void);

Status InitList(LinkedList *L) {
    LinkedList list;

    list = (LinkedList)malloc(sizeof(LNode));
    if(list == NULL)
    {
    	printf("�ڴ����ʧ��\n");
        return error;
    }
    list->next = NULL;
    *L = list;

    return success;
}

void DestroyList(LinkedList *L) {
    LinkedList temp;

    while(*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

Status InsertList(LNode *p, ElemType data) {
    LinkedList current = p;
    LinkedList newNode = (LinkedList)malloc(sizeof(LNode));

    if(newNode == NULL)
    {
        printf("�ڴ����ʧ��\n");
        return error;
    }
    newNode->data = data;
    newNode->next = NULL;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return success;
}



Status ReverseList(LinkedList *L) {
    LNode *newHead;		//����ÿ�η�ת��ĵ�һ���ڵ� 
    LNode *p1;			//ÿ�ζ�ָ��ǰһ���ڵ�	
    LNode *p2;			// ����δ��תǰ����һ���ڵ� 
    p1=(*L)->next;
    p2=p1->next;
    p1->next=NULL;
    newHead=p1;
    while (p2!= NULL) {
        p1=p2;
        p2=p1->next;
        p1->next=newHead;
        newHead=p1;
    }
    (*L)->next=newHead;
}

Status IsLoopList(LinkedList L) {
    LinkedList fast = L, slow = L;
    while(fast->next != NULL && slow->next != NULL)
    {
        slow = slow->next;
        if((fast = fast->next->next) == NULL)
        return error;
        if(fast == slow)
        return success;
    }
    return error;
}

void show(void)
{
    printf("\n\n\n\n������ADT\n\n");
    printf("1.����������\n");   
    printf("2.������\n");   
    printf("3.��������\n");  
    printf("4.�ж������Ƿ�ɻ�\n");   
    printf("5.�����м���\n");
    printf("6.�˳�\n");
    printf("\n�������Ӧ������(1-6)��");
}

int judge_int(void)  //��ֹ�û��������������ַ�
{
    int len, num = 0, arg = 1;
    char word[10];  
    int m, j= 1, k;
    while(j)
    {
        scanf("%s", word);
        len = strlen(word);
        for(m = 0;m<len;m++)
        {
            if(word[m]<'0' || word[m]>'9')  //�����Ƿ��������������ַ�
            {
                printf("������������");
                break;
            }
            else 
            {
                if(m == len-1)
                    j = 0;
            }
        }
    }
    j = len-1;
    for(m=0;m<len;m++)  // ���ַ�����ת��Ϊ����
    {
        for(k=0;k<j;k++)
            arg *= 10;
        num += (word[m]-'0')*arg;
        arg = 1;
        j--;
    }
    return num;
} 

int main(void)
{    
	int choice, num = 0;
    LinkedList head = NULL;

    do
{
        show();
        choice = judge_int();
        system("cls");
        switch(choice)
        {
            case 1://����������
            {
                if(InitList(&head))
                {
                    printf("���������ɹ�\n");
                }
                else
                {
                    printf("��������ʧ��\n");
                }
                break;
            }
        
            case 2://��������
            {
                if(head == NULL)
                {
                    printf("����Ϊ�գ� ���ȴ�������\n");
                }
                else
                {
                    printf("���������ݣ�");
                    scanf("%d", &num);
                    if(InsertList(head, num))
                    {
                        printf("���ݲ���ɹ�\n");
                    }
                    else
                    {
                        printf("���ݲ���ʧ��\n");
                    }
                }
                break;
            }
           
            
            case 3://��������
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("�������ڻ���ֻ����һ���յ�ͷ���\n");
                }
                else
                {
                    TraverseList(head);
                }
                break;
            }
   
            case 4://�ж������Ƿ�ɻ�
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("����Ϊ��\n");
                }
                else
                {
                    if(IsLoopList(head))
                    {
                        printf("����ɻ�\n");
                    }
                    else
                    {
                        printf("����û�гɻ�\n");
                    }
                }
                break;
            }
          
            case 5://�����м���
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("���ǿ�����\n");
                }
                else
                {
                    printf("�����м䴢���ֵΪ%d\n", (FindMidNode(head))->data);
                }
                break;
            }  
    }}while();
	return 0;

   }


