#include <iostream>
#include "InfixToPostfix.h"
#include <stdlib.h>
#include <ctype.h>
//#include "ListBaseStack.h"
#include "DequeTemplate.h"
using namespace std;

//�������� �켱������ �Ҵ��ϴ� �Լ�
int GetOpPrec(char op)
{
	switch (op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}

	return -1;
}

//�켱���� ���Լ�
int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}



string read_expression(string s )
{
	string str1 = s;
	string str2;
	string str3;
	cout << "���ڿ� �Է�:" << endl;
	cin >> str2;
	str3 = str1 + str2;

	return str3;

}

string convert_to_postfix(string s)
{
	string str1 = s;
	

	//Stack stack;
	//deq������ ����� ����� ���Ḯ��Ʈ ����
	List dbl;
	ListInit(&dbl);

	int expLen = s.length();
	char* convExp = (char*)malloc(expLen + 1);

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1);
	//StackInit(&stack);
	//deq������ �ʿ��� ����� ���Ḯ��Ʈ�� ���ڷ� ����
	ourDeque<Node<Data>> deq(&dbl);

	for (i = 0; i < expLen; i++)
	{
		tok = s[i];
		
		if (isdigit(tok))
		{
			convExp[idx++] = tok;

		}
		else
		{
			switch (tok)
			{
			case'(':
				//SPush(&stack, tok);
				deq.push_back(&deq, tok);
				break;
			case ')':
				while (1)
				{
					//popOp = SPop(&stack);
					popOp = deq.pop_back(&deq);
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;
			case '+': case '-':
			case '*': case '/':
				//while (!SIsEmpty(&stack) &&
				while (!deq.empty(&deq) &&
					WhoPrecOp(deq.back(&deq), tok) >= 0)
					//WhoPrecOp(SPeek(&stack), tok) >= 0)

					//convExp[idx++] = SPop(&stack);
					convExp[idx++] = deq.pop_back(&deq);

				//SPush(&stack, tok);
				deq.push_back(&deq, tok);
				break;
			}
		}
	}
	//while (!SIsEmpty(&stack))
	while (!deq.empty(&deq))
		convExp[idx++] = deq.pop_back(&deq);
		//convExp[idx++] = SPop(&stack);

	str1 = convExp;//string�� char�� ���ڿ� �迭 ���� ����
	free(convExp);

	return str1;
}

//���������� ����ϴ� �Լ�
double evaluate_postfix(string s)
{
	
	//Stack stack;
	//deq������ ����� ����� ���Ḯ��Ʈ ����
	List dbl;
	ListInit(&dbl);

	//deq������ �ʿ��� ����� ���Ḯ��Ʈ�� ���ڷ� ����
	ourDeque<Node<Data>> deq(&dbl);

	int expLen = s.length();
	int i;
	char tok, op1, op2;

	for (i = 0; i < expLen;i++)
	{
		tok = s[i];
		
		if (isdigit(tok))
		{
			//SPush(&stack, tok - '0');
			deq.push_back(&deq, tok - '0');
		}
		else
		{
			//op2 = SPop(&stack);
			//op1 = SPop(&stack);
			op2 = deq.pop_back(&deq);
			op1 = deq.pop_back(&deq);

			switch (tok)
			{
			case '+':
				//SPush(&stack, op1 + op2);
				deq.push_back(&deq, op1 + op2);
				break;
			case '-':
				//SPush(&stack, op1 - op2);
				deq.push_back(&deq, op1 - op2);
				break;
			case '*':
				//SPush(&stack, op1 * op2);
				deq.push_back(&deq, op1 * op2);
				break;
			case '/':
				//SPush(&stack, op1 / op2);
				deq.push_back(&deq, op1 / op2);
				break;
			}

		}
	}
	//printf("%d", SPeek(&stack)); //SPeek�� ��ȯ���� int�̹Ƿ� %d�� ��� ����
	printf("%d", deq.back(&deq));

	//return SPop(&stack);
	return deq.pop_back(&deq);
}