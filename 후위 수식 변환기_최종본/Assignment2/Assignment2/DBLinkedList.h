#pragma once
#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

template <typename T>
class Node //노드 객체
{
public:
	T data;
	Node* next;
	Node* prev;
	void set_data(Data new_data);
	void set_Rlink(Node* new_link);
	void set_Llink(Node* new_link);
	T data_show();
	Node* Rlink_show();
	Node* Llink_show();
	
};


class OurSet //양방향 연결리스트 객체
{
public:
	Node<Data>* head;
	Node<Data>* cur;
	int numOfData;
	void set_link(Node<Data>* new_link);
};


typedef OurSet List;

void ListInit(List* plist); //양방향 연결리스트 초기화

int list_length(List* plist);// 연결리스트의 길이 반환
//void list_head_insert(List* plist, Data data); //헤드에 삽입
void list_head_insert(List* plist, Data entry);
void list_insert(List* plist,Node<Data>* previous_ptr, Data entry); // 현재 위치의 다음 위치에 삽입
Node<Data>* list_search(List* plist, const Data& target);
Node<Data>* list_locate(List* plist, Node<Data>* head_ptr, Data position);
void list_head_remove(List* plist, Node<Data>* head_ptr);

int LFirst(List* plist, Data* pdata);//연결리스트 첫번째요소 
int LNext(List* plist, Data* pdata); //오른쪽으로 탐색용
int LPrevious(List* plist, Data* pdata); //왼쪽으로 탐색용

void list_remove(List* plist, Node<Data>* previous_ptr);
void list_clear(List* plist, Node<Data>* head_ptr);
void list_copy(List* plist, Node<Data>* source_ptr, Node<Data>* head_ptr, Node<Data>* tail_ptr);
//list_length, list_search, list_locate, list_head_insert, list_insert, list_head_remove,
//list_remove, list_clear, and list_copy

void show_contents(List* plist, int* value);

#endif


