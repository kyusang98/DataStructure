#include <iostream>
#include <stdio.h>
#include "InfixToPostfix.h"
#include "DequeTemplate.h"

///*
int main()
{
    int state = 1;

  
    //char exp1[] = "1+2*3";
    //char exp2[] = "(1+2)*3";
    //char exp3[] = "((1-2)+3)*(5-2)";
    
    //char postExp1[] = "42*8+";
    //char postExp2[] = "123+*4/";
    
    //string str1 = convert_to_postfix(exp1);
    //string str2 = convert_to_postfix(exp2);
    //string str3 = convert_to_postfix(exp3);

    //printf("%s = %f \n", exp1, evaluate_postfix(str1));
    //printf("%s = %f \n", exp2, evaluate_postfix(str2));
    //printf("%s = %f \n", exp3, evaluate_postfix(str3));


    //printf("%s = %f \n", postExp1, evaluate_postfix(postExp1));//evaluate_postfix는 반환형이 double이므로 %f를 이용해야만 출력가능
    //printf("%s = %f \n", postExp2, evaluate_postfix(postExp2));


    
    while (1)
    {
            string str = "";
            cout << "수식을 입력하시오:";
            getline(cin, str);    // 문자열 입력받기
            cout << str << endl;

            string poststr = convert_to_postfix(str);

            cout << "입력받은 문자열은:" << str << endl;
            cout << "후위수식 문자열은:" << poststr << endl;
            printf("문자열의 계산결과는:%f\n", evaluate_postfix(poststr));

    }
    

    return 0;

}
//*/


/*
//Deque 시험을 위한 메인함수
int main()
{
    //deq생성시 사용할 양방향 연결리스트 생성
    List dbl;
    ListInit(&dbl);

    //deq생성시 필요한 양방향 연결리스트를 인자로 전달
    ourDeque deq(&dbl);

    //데이터넣기
    deq.push_front(&deq,3);
    deq.push_front(&deq, 2);
    deq.push_front(&deq, 1);

    deq.push_back(&deq, 4);
    deq.push_back(&deq, 5);
    deq.push_back(&deq, 6);

    //데이터 꺼내기
    while (!deq.empty(&deq))
        printf("%d", deq.pop_front(&deq));

    printf("\n");
    

    //데이터 넣기 2차
    deq.push_front(&deq, 3);
    deq.push_front(&deq, 2);
    deq.push_front(&deq, 1);

    deq.push_back(&deq, 4);
    deq.push_back(&deq, 5);
    deq.push_back(&deq, 6);

    //데이터 꺼내기 2차
    while (!deq.empty(&deq))
        printf("%d", deq.pop_back(&deq));

    
    return 0;
}
*/

