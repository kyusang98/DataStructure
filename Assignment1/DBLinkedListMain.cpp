// Assignment1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include "DBLinkedList.h"

int main()
{
    //양방향 연결리스트 생성 및 초기화
    List list;
    int data;
    ListInit(&list);

    //8개의 데이터 저장
    list_head_insert(&list,1);list_head_insert(&list,2);
    list_head_insert(&list,3);list_head_insert(&list,4);
    list_head_insert(&list,5);list_head_insert(&list,6);
    list_head_insert(&list,7);list_head_insert(&list,8);
    list_head_insert(&list, 9);list_head_insert(&list, 10);
    printf("연결 리스트의 원소는 %d개 입니다.\n", list.numOfData);

    //머리 부분 데이터 삭제
    list_head_remove(&list, list.head);

    //머리 부분 다음 데이터 삭제
    list_remove(&list, list.head);

    //저장된 데이터의 조회
    if (LFirst(&list, &data))
    {
        
        //printf("%d\n", list.head->data);
        //printf("%d\n", list.cur->data);
        //printf("%d\n", list.head->next->data);
        //printf("%d\n", list.cur->next->data);

        //오른쪽 노드로 이동하며 데이터 조회
        printf("리스트를 오른쪽으로 조회합니다.\n");
        printf("%d", data);
        while (LNext(&list, &data))
            printf("%d", data);
        printf("\n");

        //왼쪽 노드로 이동하며 데이터 조회
        printf("리스트를 왼쪽으로 조회합니다.\n");
        printf("%d", data);
        while (LPrevious(&list, &data))
            printf("%d", data);

        printf("\n\n");
    }

    //연결리스트 길이 구하기
    printf("연결리스트의 길이는 %d입니다.\n", list_length(&list));

    //특정값과 특정위치 찾기
    int target;
    int position;
    printf("찾고 싶은 값을 입력해주세요:");
    scanf_s("%d", &target);
    printf("찾고 싶은 위치를 입력해주세요:");
    scanf_s("%d", &position);

    Node* addr_target = list_search(&list, target);
    Node* addr_position = list_locate(&list, list.head, position);
    target = addr_target->data;
    int position_data = addr_position->data;
    printf("찾고 있는 값의 주소값은 %d 이고 저장된 값은 %d 입니다.\n",addr_target,target);
    printf("%d 위치의 주소값은 %d 이고 저장된 값은 %d 입니다.\n", position, addr_target, position_data);
   
    printf("\n\n");

    //연결리스트 copy하기
    List list_copied;
    ListInit(&list_copied);// 객체 생성 후 초기화까지 시켜줘야지!
  
    list_copy(&list_copied, list.head, NULL, NULL);
   
    printf("복사한 리스트의 원소는 %d개 입니다.\n", list_copied.numOfData);

    
    if (LFirst(&list_copied, &data))
    {

        //오른쪽 노드로 이동하며 데이터 조회
        printf("리스트를 오른쪽으로 조회합니다.\n");
        printf("%d", data);
        while (LNext(&list_copied, &data))
            printf("%d", data);
        printf("\n");

        //왼쪽 노드로 이동하며 데이터 조회
        printf("리스트를 왼쪽으로 조회합니다.\n");
        printf("%d", data);
        while (LPrevious(&list_copied, &data))
            printf("%d", data);

        printf("\n\n");
    }

    list_clear(&list_copied, list_copied.head);
    printf("삭제된 리스트의 길이는 %d입니다.", list_copied.numOfData);

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
