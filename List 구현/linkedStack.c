#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedStackH.h"

//-------- linked 는 빈공간 없다
int main(int argc, char* argv[]) {
	LinkedStack* pStack = NULL;
	StackNode* pNode = NULL;

	pStack = createLinkedStack();

	if (pStack != NULL) {
		StackNode node[5] = { 0 };
		char value[5] = { 0 };
		int create = 5, i = 0;

		// 추후 수정 가능 -> 들어오는 만큼 할당

		for (i = 0; i < create; i++) {	// 0~4 하고 하나 비워둬본다.
			printf("%d. 데이터 입력 :", i + 1);
			scanf("%c", &value[i]);		// Visual 버전 scanf, getchar _CRT 선언
			getchar();		// enter 키 처리
			fflush(stdin);	// 버퍼 비우기
		}

		for (i = 0; i < create; i++) {	// node에 데이타 삽입
			node[i].data = value[i];
			pushLS(pStack, node[i]);
		}

		displayLinkedStack(pStack);	// display

		pNode = popLS(pStack);
		if (pNode != NULL)
		{
			printf("Pop-[%c]\n", pNode->data);
			free(pNode);	// POP 노드 제거
		}
		else {
			printf("Pop-NULL\n");
		}
		displayLinkedStack(pStack);

		pNode = peekLS(pStack);
		if (pNode != NULL) {
			printf("Peek-[%c]\n", pNode->data);
		}
		else {
			printf("Peek-NULL\n");
		}
		displayLinkedStack(pStack);

		deleteLinkedStack(pStack);
	}
	return 0;
}

//-------------- LinkedStack 생성 -------------------
LinkedStack* createLinkedStack() {
	LinkedStack* pReturn = NULL;
	int i = 0;
	pReturn = (LinkedStack*)malloc(sizeof(LinkedStack));	// 할당
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedStack));		// 0 set
	}
	else {
		printf("메모리 할당 오류 createLinkedStack()\n");
		return NULL;
	}
	return pReturn;
}

void pushLS(LinkedStack* pStack, StackNode element) {
	StackNode* pNode = NULL;

	if (pStack != NULL) {
		pNode = (StackNode*)malloc(sizeof(StackNode));	// 할당
		if (pNode != NULL) {
			memset(pNode, 0, sizeof(StackNode));	// 0 Set
			*pNode = element;
			pNode->pLink = pStack->pTopElement;
			pStack->pTopElement = pNode;
			pStack->currentElementCount++;	// Count++ 노드갯수
		}
		else {
			printf("메모리 할당 오류 pushLS()\n");
		}
	}
}

StackNode* popLS(LinkedStack* pStack) {
	StackNode* pReturn = NULL;
	if (pStack != NULL) {
		if (isLinkedStackEmpty(pStack) == FALSE) {
			pReturn = pStack->pTopElement;
			pStack->pTopElement = pReturn->pLink;
			pReturn->pLink = NULL;
			pStack->currentElementCount--;
		}
	}

	return pReturn;
}

StackNode* peekLS(LinkedStack* pStack) {	// Void 수정 가능 Return값 X / pReturn -> pPeekData  
	StackNode* pReturn = NULL;
	if (pStack != NULL) {
		if (isLinkedStackEmpty(pStack) == FALSE) {
			pReturn = pStack->pTopElement;
		}
	}
	return pReturn;
}

void deleteLinkedStack(LinkedStack* pStack){
	StackNode* pNode = NULL;
	StackNode* pDelNode = NULL;

	if (pStack != NULL) {
		pNode = pStack->pTopElement;
		while (pNode != NULL) {
			pDelNode = pNode;
			pNode = pNode->pLink;
			free(pDelNode);
		}
		free(pStack);		
	}
	// free 로 모두 할당 해제
}

int isLinkedStackEmpty(LinkedStack* pStack) {
	int ret = FALSE;

	if (pStack != NULL) {
		if (pStack->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}

void displayLinkedStack(LinkedStack* pStack) {
	StackNode* pNode = NULL;
	int i = 1;
	if (pStack != NULL) {
		printf("노드 개수: %d\n",
			pStack->currentElementCount);
		pNode = pStack->pTopElement;
		while (pNode != NULL) {
			printf("%d : %c\n", pStack->currentElementCount - i, pNode->data);
			i++;
			pNode = pNode->pLink;
		}
	}
}
