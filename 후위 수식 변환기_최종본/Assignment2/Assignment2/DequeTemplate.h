#ifndef __DEQUE_TEMPLATE_H_
#define __DEQUE_TEMPLATE_H_
#include "DBLinkedList.h"
#include <cstddef>
#include <iostream>

using namespace std;
template <typename T>
class ourDeque
{
public:
	List* dbl;
	T* head;//Node
	T* tail;//Node
	int count;


	ourDeque(List* dblist)//������
	{
		dbl = dblist;
		head = NULL;
		tail = NULL;
		count = 0;
		cout << " �� ��ü�� �����Ǿ����ϴ�" << endl;
	}


	//ourDeque(ourDeque& copy)//���� ������
	

	~ourDeque()//�Ҹ���
	{
		list_clear(dbl, head);
		cout << "�� ��ü�� �Ҹ�Ǿ����ϴ�" << endl;
	}

	void push_back(ourDeque* pdeq, Data data);
	void push_front(ourDeque* pdeq, Data data);
	Data pop_back(ourDeque* pdeq);
	Data pop_front(ourDeque* pdeq);
	int empty(ourDeque* pdeq);
	int size(ourDeque* pdeq);
	//Deque operator=(const Deque& ref);
	Data front(ourDeque* pdeq);
	Data back(ourDeque* pdeq);
};





#endif

