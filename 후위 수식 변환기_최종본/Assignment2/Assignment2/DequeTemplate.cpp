#include "DequeTemplate.h"
#include "DBLinkedList.h"
#include <iostream>



/* //���� ���� ������ ���� �����Ͽ����ϴ�.
ourDeque(ourDeque& copy)//���� ������
	:count(copy.count)
{
	List* new_dbl = (List*)malloc(sizeof(List));
	list_copy(new_dbl, copy.dbl, NULL, NULL);
	dbl = new_dbl;


	cout << "�� ��ü�� ����Ǿ����ϴ�" << endl;
}
*/


void ourDeque<Node<Data>>::push_back(ourDeque<Node<Data>>* pdeq, Data data)
{
	Node<Data>* newNode = (Node<Data>*)malloc(sizeof(Node<Data>));
	newNode->data = data;
	newNode->prev = pdeq->tail;

	if (ourDeque<Node<Data>>::empty(pdeq))
		pdeq->head = newNode;
	else
		pdeq->tail->next = newNode;

	newNode->next = NULL;
	pdeq->tail = newNode;

	pdeq->count++;
	//printf("���� ����:%d\n", pdeq->count);

}


void ourDeque<Node<Data>>::push_front(ourDeque<Node<Data>>* pdeq, Data data)
{
	Node<Data>* newNode = (Node<Data>*)malloc(sizeof(Node<Data>));
	newNode->data = data;

	newNode->next = pdeq->head;

	if (ourDeque<Node<Data>>::empty(pdeq))
		pdeq->tail = newNode;
	else
		pdeq->head->prev = newNode;

	newNode->prev = NULL;
	pdeq->head = newNode;

	pdeq->count++;
	//printf("���� ����:%d\n", pdeq->count);
	
}

Data ourDeque<Node<Data>>::pop_back(ourDeque<Node<Data>>* pdeq)
{
	Node<Data>* rnode = pdeq->tail;
	Data rdata;
	if (ourDeque<Node<Data>>::empty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}
	rdata = pdeq->tail->data;

	pdeq->tail = pdeq->tail->prev;
	free(rnode);

	if (pdeq->tail == NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;

	pdeq->count--;
	//printf("���� ����:%d\n", pdeq->count);

	return rdata;
}

Data ourDeque<Node<Data>>::pop_front(ourDeque<Node<Data>>* pdeq)
{
	Node<Data>* rnode = pdeq->head;
	Data rdata;
	if (ourDeque<Node<Data>>::empty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}
	rdata = pdeq->head->data;

	pdeq->head = pdeq->head->next;
	free(rnode);

	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;

	pdeq->count--;
	//printf("���� ����:%d\n", pdeq->count);

	return rdata;
}

//����� Ư��ȭ ���� ������ �Լ��տ� 'template<>'�� �ٿ���µ� �ֱ׷����ϴ����� �𸥴�.  
template <> int ourDeque<Node<Data>>::empty(ourDeque<Node<Data>>* pdeq)
{
	if (pdeq->head == NULL)
		return TRUE;
	else
		return FALSE;
}

int ourDeque<Node<Data>>::size(ourDeque<Node<Data>>* pdeq)
{
	return pdeq->count;
}

/*
Deque ourDeque::operator=(const Deque& ref)
{

}
*/

Data ourDeque<Node<Data>>::front(ourDeque<Node<Data>>* pdeq)
{
	if (ourDeque<Node<Data>>::empty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	return pdeq->head->data;
}

Data ourDeque<Node<Data>>::back(ourDeque<Node<Data>>* pdeq)
{
	if (ourDeque<Node<Data>>::empty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	return pdeq->tail->data;
}


