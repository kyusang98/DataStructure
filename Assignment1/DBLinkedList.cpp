#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

//Node 객체의 메서드
void Node::set_data(Data new_data)//노드 데이터 입력
{
	data = new_data;
}

void Node::set_Rlink(Node* new_link)//오른쪽 노드 연결
{
	next = new_link;
}

void Node::set_Llink(Node* new_link)//왼쪽 노드 연결
{
	prev = new_link;
}

Data Node::data_show() //노드 데이터값 반환
{
	return data;
}

Node* Node::Rlink_show()//오른쪽 노드 주소값 반환
{
	return next;
}

Node* Node::Llink_show()//왼쪽 노드 주소값 반환
{
	return prev;
}

//DBLinkList객체의 메서드
void OurSet::set_link(Node* new_link)// 현재 가리키는 노드 세팅
{
	cur = new_link;
}

//c에서는 구조체의 모든 멤버에 자유롭게 접근할 수 있으나
//c++에서는 클래스의 멤버는 지정하지 않으면 private이 되므로
//접근 권한을 public으로 바꿔줘야만 클래스의 멤버에 접근 가능하다.

void ListInit(List* plist)
{
	plist -> head = NULL;
	plist->numOfData = 0;
}

//머리 부분에 데이터 삽입
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
		printf("%d는 이미 존재하는 요소입니다.\n", entry);
}

//previous_ptr바로 다음에 삽입
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
		printf("%d는 이미 존재하는 요소입니다.\n", entry);
}

 Node* list_search(List* plist, const Data& target) //특정값을 찾는다.
{
	Node* cursor;

	for (cursor = plist->head; cursor != NULL;cursor = cursor->Rlink_show())
	{
		if (target == cursor->data_show())
			return cursor;
	}
	return NULL;
}

 Node* list_locate(List*plist, Node* head_ptr, Data position) //특정위치를 찾는다.
 {
	 Node* cursor = head_ptr;
	 Data i;
	 for (i = 1;(cursor != NULL && i < position); ++i)
		 cursor = cursor->Rlink_show();
	 return cursor;
 }

 void list_head_remove(List* plist, Node* head_ptr) //헤드부분 노드를 삭제
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

//리스트의 첫번째 데이터 조회
//인자로 주는 pdata는 main함수에 선언된 int형 변수의 주소값
int LFirst(List* plist, Data* pdata)
{
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;
	*pdata = plist->cur->data;

	return TRUE;

}

//오른쪽 노드로 이동하며 데이터 조회
int LNext(List* plist, Data* pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

//왼쪽 노드로 이동하며 데이터 조회
int LPrevious(List* plist, Data* pdata)
{
	if (plist->cur->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return TRUE;
}

//연결리스트에 저장된 노드의 개수
int list_length(List* plist)//LCount
{
	return plist->numOfData;
}

void list_remove(List* plist, Node* previous_ptr) //previous_ptr바로 다음 노드를 삭제
{
	Node* remove_ptr;

	remove_ptr = previous_ptr->Rlink_show();
	plist->cur = remove_ptr->Rlink_show();
	plist->cur->set_Llink(previous_ptr);
	previous_ptr->set_Rlink(plist->cur);
	delete remove_ptr;
	(plist->numOfData)--;

}

//C에서는 1줄만 중괄호 안쓰고 반복 혹은 조건문에서 실행가능하다.
//list.head와 head_ptr은 처음에는 같은 곳을 가리키고 있다.
//list.head가 가리키는 곳이 바뀌었다고 head_ptr이 가리키는 곳이 바뀌지는 않는다.
//그러므로, list.head가 바뀌어서 head_ptr도 그곳을 가리키게 만들고 싶다면
//따로 다시 한번 head_ptr=list.head가 가리키는 곳 으로 할당을 해줘야한다.
void list_clear(List* plist, Node* head_ptr)
{
	while (plist->head != NULL)
	{   
		if (plist->head->Rlink_show() != NULL)
			printf("%d %d", plist->head->data, plist->head->Rlink_show()->data);
		else
			printf("\n");
		//이 부분이 중요하다.
		head_ptr = plist->head;
		list_head_remove(plist, head_ptr);
	}
}

//첫번째 인자는 복사해서 만들 리스트, 두번째인자 복사할 대상
void list_copy(List* plist, Node* source_ptr, Node* head_ptr, Node* tail_ptr)
{
	head_ptr = NULL; 
	tail_ptr = NULL;
	if (source_ptr == NULL) 
		return;
	list_insert(plist, plist->head ,source_ptr->data_show());//두번째 인자로 source_ptr이 아니라 지금 제작중인 리스트의 머리부분 넣어야지!
	head_ptr = plist->head;
	tail_ptr = head_ptr;
	source_ptr = source_ptr->Rlink_show();
	while (source_ptr != NULL) 
	{
		list_insert(plist, tail_ptr, source_ptr->data_show());//두번째 인자로 source_ptr이 아니라 지금 제작중인 리스트의 tail_ptr를 넣어야지!
		tail_ptr = tail_ptr->Rlink_show();
		source_ptr = source_ptr->Rlink_show();
	}
	
}

void show_contents(List* plist, int* value)
{
	if (LFirst(plist, value))
	{

		//오른쪽 노드로 이동하며 데이터 조회
		printf("리스트를 오른쪽으로 조회합니다.\n");
		printf("%d", *value);
		while (LNext(plist, value))
			printf("%d", *value);
		printf("\n");

		//왼쪽 노드로 이동하며 데이터 조회
		printf("리스트를 왼쪽으로 조회합니다.\n");
		printf("%d", *value);
		while (LPrevious(plist, value))
			printf("%d", *value);

		printf("\n\n");
	}
}
