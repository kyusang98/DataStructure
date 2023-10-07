#pragma once
#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;


class Node //��� ��ü
{
public:
	Data data;
	Node* next;
	Node* prev;
	void set_data(Data new_data);
	void set_Rlink(Node* new_link);
	void set_Llink(Node* new_link);
	Data data_show();
	Node* Rlink_show();
	Node* Llink_show();
	
};


class DBLinkedList //����� ���Ḯ��Ʈ ��ü
{
public:
	Node* head;
	Node* cur;
	int numOfData;
	void set_link(Node* new_link);
};


typedef DBLinkedList List;

void ListInit(List* plist); //����� ���Ḯ��Ʈ �ʱ�ȭ

int list_length(List* plist);// ���Ḯ��Ʈ�� ���� ��ȯ
//void list_head_insert(List* plist, Data data); //��忡 ����
void list_head_insert(List* plist, Data entry);
void list_insert(List* plist,Node* previous_ptr, Data entry); // ���� ��ġ�� ���� ��ġ�� ����
Node* list_search(List* plist, const Data& target);
Node* list_locate(List* plist, Node* head_ptr, Data position);
void list_head_remove(List* plist, Node* head_ptr);

int LFirst(List* plist, Data* pdata);//���Ḯ��Ʈ ù��°��� 
int LNext(List* plist, Data* pdata); //���������� Ž����
int LPrevious(List* plist, Data* pdata); //�������� Ž����

void list_remove(List* plist, Node* previous_ptr);
void list_clear(List* plist, Node* head_ptr);
void list_copy(List* plist, Node* source_ptr, Node* head_ptr, Node* tail_ptr);
//list_length, list_search, list_locate, list_head_insert, list_insert, list_head_remove,
//list_remove, list_clear, and list_copy


#endif


