#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

//Node ��ü�� �޼���
void Node::set_data(Data new_data)//��� ������ �Է�
{
	data = new_data;
}

void Node::set_Rlink(Node* new_link)//������ ��� ����
{
	next = new_link;
}

void Node::set_Llink(Node* new_link)//���� ��� ����
{
	prev = new_link;
}

Data Node::data_show() //��� �����Ͱ� ��ȯ
{
	return data;
}

Node* Node::Rlink_show()//������ ��� �ּҰ� ��ȯ
{
	return next;
}

Node* Node::Llink_show()//���� ��� �ּҰ� ��ȯ
{
	return prev;
}

//DBLinkList��ü�� �޼���
void OurSet::set_link(Node* new_link)// ���� ����Ű�� ��� ����
{
	cur = new_link;
}

//c������ ����ü�� ��� ����� �����Ӱ� ������ �� ������
//c++������ Ŭ������ ����� �������� ������ private�� �ǹǷ�
//���� ������ public���� �ٲ���߸� Ŭ������ ����� ���� �����ϴ�.

void ListInit(List* plist)
{
	plist -> head = NULL;
	plist->numOfData = 0;
}

//�Ӹ� �κп� ������ ����
void list_head_insert(List* plist, Data entry)
{
	if (list_search(plist, entry) == NULL)
	{
		if (plist->head == NULL)
		{
			Node* head_ptr;
			head_ptr = new Node;
			head_ptr->set_data(entry);
			head_ptr->set_Rlink(NULL);
			head_ptr->set_Llink(NULL);
			plist->head = head_ptr;
			plist->cur = head_ptr;
			(plist->numOfData)++;
		}
		else
		{
			Node* head_ptr;
			head_ptr = new Node;
			head_ptr->set_data(entry);
			head_ptr->set_Rlink(plist->head);
			head_ptr->set_Llink(NULL);
			plist->head->prev = head_ptr;
			plist->head = head_ptr;
			plist->cur = head_ptr;
			(plist->numOfData)++;
		}
	}
	else
		printf("%d�� �̹� �����ϴ� ����Դϴ�.\n", entry);
}

//previous_ptr�ٷ� ������ ����
void list_insert(List* plist,Node *previous_ptr, Data entry)
{
	if (list_search(plist, entry)==NULL)
	{
		if (plist->head != NULL)
		{
			plist->cur = previous_ptr;
			Node* insert_ptr;
			insert_ptr = new Node;
			insert_ptr->set_data(entry);
			insert_ptr->set_Llink(plist->cur);
			if (plist->cur->next != NULL)
			{
				insert_ptr->set_Rlink(plist->cur->next);
				plist->cur->next->set_Llink(insert_ptr);
			}
			else
			{
				insert_ptr->set_Rlink(NULL);
			}
			plist->cur->set_Rlink(insert_ptr);
			(plist->numOfData)++;
		}
		else
		{
			list_head_insert(plist, entry);
		}
	}
	else
		printf("%d�� �̹� �����ϴ� ����Դϴ�.\n", entry);
}

 Node* list_search(List* plist, const Data& target) //Ư������ ã�´�.
{
	Node* cursor;

	for (cursor = plist->head; cursor != NULL;cursor = cursor->Rlink_show())
	{
		if (target == cursor->data_show())
			return cursor;
	}
	return NULL;
}

 Node* list_locate(List*plist, Node* head_ptr, Data position) //Ư����ġ�� ã�´�.
 {
	 Node* cursor = head_ptr;
	 Data i;
	 for (i = 1;(cursor != NULL && i < position); ++i)
		 cursor = cursor->Rlink_show();
	 return cursor;
 }

 void list_head_remove(List* plist, Node* head_ptr) //���κ� ��带 ����
 {
	 Node* remove_ptr;

	 remove_ptr = head_ptr; 
	 if (head_ptr->Rlink_show() != NULL) 
	 {
		 plist->head = head_ptr->Rlink_show();
		 plist->cur = plist->head;
		 plist->head->set_Llink(NULL);
		 delete remove_ptr;
		 (plist->numOfData)--;
	 }
	 else
	 {
		 plist->head = NULL;
		 plist->cur = plist->head;
		 delete remove_ptr;
		 (plist->numOfData)--;
	 }
 }

//����Ʈ�� ù��° ������ ��ȸ
//���ڷ� �ִ� pdata�� main�Լ��� ����� int�� ������ �ּҰ�
int LFirst(List* plist, Data* pdata)
{
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;
	*pdata = plist->cur->data;

	return TRUE;

}

//������ ���� �̵��ϸ� ������ ��ȸ
int LNext(List* plist, Data* pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

//���� ���� �̵��ϸ� ������ ��ȸ
int LPrevious(List* plist, Data* pdata)
{
	if (plist->cur->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return TRUE;
}

//���Ḯ��Ʈ�� ����� ����� ����
int list_length(List* plist)//LCount
{
	return plist->numOfData;
}

void list_remove(List* plist, Node* previous_ptr) //previous_ptr�ٷ� ���� ��带 ����
{
	Node* remove_ptr;

	remove_ptr = previous_ptr->Rlink_show();
	plist->cur = remove_ptr->Rlink_show();
	plist->cur->set_Llink(previous_ptr);
	previous_ptr->set_Rlink(plist->cur);
	delete remove_ptr;
	(plist->numOfData)--;

}

//C������ 1�ٸ� �߰�ȣ �Ⱦ��� �ݺ� Ȥ�� ���ǹ����� ���డ���ϴ�.
//list.head�� head_ptr�� ó������ ���� ���� ����Ű�� �ִ�.
//list.head�� ����Ű�� ���� �ٲ���ٰ� head_ptr�� ����Ű�� ���� �ٲ����� �ʴ´�.
//�׷��Ƿ�, list.head�� �ٲ� head_ptr�� �װ��� ����Ű�� ����� �ʹٸ�
//���� �ٽ� �ѹ� head_ptr=list.head�� ����Ű�� �� ���� �Ҵ��� ������Ѵ�.
void list_clear(List* plist, Node* head_ptr)
{
	while (plist->head != NULL)
	{   
		if (plist->head->Rlink_show() != NULL)
			printf("%d %d", plist->head->data, plist->head->Rlink_show()->data);
		else
			printf("\n");
		//�� �κ��� �߿��ϴ�.
		head_ptr = plist->head;
		list_head_remove(plist, head_ptr);
	}
}

//ù��° ���ڴ� �����ؼ� ���� ����Ʈ, �ι�°���� ������ ���
void list_copy(List* plist, Node* source_ptr, Node* head_ptr, Node* tail_ptr)
{
	head_ptr = NULL; 
	tail_ptr = NULL;
	if (source_ptr == NULL) 
		return;
	list_insert(plist, plist->head ,source_ptr->data_show());//�ι�° ���ڷ� source_ptr�� �ƴ϶� ���� �������� ����Ʈ�� �Ӹ��κ� �־����!
	head_ptr = plist->head;
	tail_ptr = head_ptr;
	source_ptr = source_ptr->Rlink_show();
	while (source_ptr != NULL) 
	{
		list_insert(plist, tail_ptr, source_ptr->data_show());//�ι�° ���ڷ� source_ptr�� �ƴ϶� ���� �������� ����Ʈ�� tail_ptr�� �־����!
		tail_ptr = tail_ptr->Rlink_show();
		source_ptr = source_ptr->Rlink_show();
	}
	
}

void show_contents(List* plist, int* value)
{
	if (LFirst(plist, value))
	{

		//������ ���� �̵��ϸ� ������ ��ȸ
		printf("����Ʈ�� ���������� ��ȸ�մϴ�.\n");
		printf("%d", *value);
		while (LNext(plist, value))
			printf("%d", *value);
		printf("\n");

		//���� ���� �̵��ϸ� ������ ��ȸ
		printf("����Ʈ�� �������� ��ȸ�մϴ�.\n");
		printf("%d", *value);
		while (LPrevious(plist, value))
			printf("%d", *value);

		printf("\n\n");
	}
}
