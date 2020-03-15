#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayStackH.h"

int main(int argc, char* argv[])
{
	ArrayStack* pStack = NULL;
	ArrayStackNode* pNode = NULL;

	char value[5] = { 0 };
	int create = 5, i = 0;

	ArrayStackNode node[5] = { 0 };

	pStack = createArrayStack(create);

	if (pStack != NULL) {

		for (i = 0; i < create; i++) {	// 0~4 하고 하나 비워둬본다.
			printf("%d. 데이터 입력 :", i + 1);
			scanf("%c", &value[i]);
			getchar();		// enter 키 처리
			fflush(stdin);	// 버퍼 비우기
		}
		ArrayStackNode node[5] = { 0 };	// node 배열로 선언

		for (i = 0; i < create; i++) {
			node[i].data = value[i];
			pushAS(pStack, node[i]);
		}
	
		displayArrayStack(pStack);

		pNode = popAS(pStack);
		if (pNode != NULL) {
			printf("Pop 값-[%c]\n", pNode->data);
			free(pNode);		// 반환후 할당 해제
		}
		else {
			printf("공백(Empty) 스택\n");
		}
		displayArrayStack(pStack);

		pNode = peekAS(pStack);
		if (pNode != NULL) {
			printf("Peek 값-[%c]\n", pNode->data);
		}
		else {
			printf("공백(Empty) 스택\n");	// ArrayStack 이여서 Empty 설정
		}
		displayArrayStack(pStack);

		deleteArrayStack(pStack);
	}
	return 0;
}

ArrayStack* createArrayStack(int size){
	ArrayStack* pReturn = NULL;
	int i = 0;

	if (size > 0) {
		pReturn = (ArrayStack*)malloc(sizeof(ArrayStack));
		if (pReturn != NULL) {
			memset(pReturn, 0, sizeof(ArrayStack));
			pReturn->maxElementCount = size;
		}
		else {
			printf("메모리 할당 오류! pReturn");
			return NULL;
		}

		pReturn->pElement = (ArrayStackNode*)malloc(sizeof(ArrayStackNode) * size);
		if (pReturn->pElement != NULL) {
			memset(pReturn->pElement, 0, sizeof(ArrayStackNode) * size);	// 사이즈만큼 Set
		}
		else {
			printf("메모리 할당 오류! pElement");
			free(pReturn); 
			return NULL;
		}
	}
	else {
		printf("스택의 크기가 정해지지 않았습니다.");	// 0 보다는 커야 할당 가능
		return NULL;
	}
	return pReturn;
}

void pushAS(ArrayStack* pStack, ArrayStackNode element)
{
	int i = 0;

	if (pStack != NULL) {
		if (isArrayStackFull(pStack) == FALSE) {		// Array라서 크기 정해짐
			pStack->pElement[pStack->currentElementCount] = element;
			pStack->currentElementCount++;
		}
		else {
			printf("스택 용량 초과");
		}
	}
}

ArrayStackNode* popAS(ArrayStack* pStack)	// 노드 제거 반환
{
	ArrayStackNode* pReturn = NULL;
	if (pStack != NULL) {
		if (isArrayStackEmpty(pStack) == FALSE) {
			pReturn = (ArrayStackNode*)malloc(sizeof(ArrayStackNode));
			if (pReturn != NULL) {
				*pReturn = pStack->pElement[pStack->currentElementCount - 1];
				pStack->currentElementCount--;	//할당해제 카운드 -1
			}
			else {
				printf("메모리 할당오류 popAs");
			}
		}
	}
	return pReturn;
}

ArrayStackNode* peekAS(ArrayStack* pStack)	// 노드 반환
{
	ArrayStackNode* pReturn = NULL;
	if (pStack != NULL) {
		if (isArrayStackEmpty(pStack) == FALSE) {
			pReturn = &(pStack->pElement[pStack->currentElementCount - 1]);	
		}
	}
	return pReturn;
}

void deleteArrayStack(ArrayStack* pStack){
	if (pStack != NULL) {
		if (pStack->pElement != NULL) {
			free(pStack->pElement);
		}
		free(pStack);
	}
}

int isArrayStackFull(ArrayStack* pStack){	// Array에서 중요! Linked 와 큰 차이점
	int ret = FALSE;

	if (pStack != NULL) {
		if (pStack->currentElementCount == pStack->maxElementCount) {
			ret = TRUE;
		}
	}
	return ret;
}

int isArrayStackEmpty(ArrayStack* pStack)
{
	int ret = FALSE;

	if (pStack != NULL) {
		if (pStack->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}

void displayArrayStack(ArrayStack* pStack)
{
	int i = 0;
	if (pStack != NULL) {
		int size = pStack->maxElementCount;
		int top = pStack->currentElementCount;

		printf("스택 크기: %d ||  노드 개수: %d\n", pStack->maxElementCount, pStack->currentElementCount);

		for (i = size - 1; i >= top; i--) {
			printf("%d : Empty \n", i);
		}

		for (i = top - 1; i >= 0; i--) {
			printf("%d : %c\n", i, pStack->pElement[i].data);
		}
	}
}