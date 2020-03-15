#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedStackH.h"

//-------- linked �� ����� ����
int main(int argc, char* argv[]) {
	LinkedStack* pStack = NULL;
	StackNode* pNode = NULL;

	pStack = createLinkedStack();

	if (pStack != NULL) {
		StackNode node[5] = { 0 };
		char value[5] = { 0 };
		int create = 5, i = 0;

		// ���� ���� ���� -> ������ ��ŭ �Ҵ�

		for (i = 0; i < create; i++) {	// 0~4 �ϰ� �ϳ� ����ֺ���.
			printf("%d. ������ �Է� :", i + 1);
			scanf("%c", &value[i]);		// Visual ���� scanf, getchar _CRT ����
			getchar();		// enter Ű ó��
			fflush(stdin);	// ���� ����
		}

		for (i = 0; i < create; i++) {	// node�� ����Ÿ ����
			node[i].data = value[i];
			pushLS(pStack, node[i]);
		}

		displayLinkedStack(pStack);	// display

		pNode = popLS(pStack);
		if (pNode != NULL)
		{
			printf("Pop-[%c]\n", pNode->data);
			free(pNode);	// POP ��� ����
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

//-------------- LinkedStack ���� -------------------
LinkedStack* createLinkedStack() {
	LinkedStack* pReturn = NULL;
	int i = 0;
	pReturn = (LinkedStack*)malloc(sizeof(LinkedStack));	// �Ҵ�
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedStack));		// 0 set
	}
	else {
		printf("�޸� �Ҵ� ���� createLinkedStack()\n");
		return NULL;
	}
	return pReturn;
}

void pushLS(LinkedStack* pStack, StackNode element) {
	StackNode* pNode = NULL;

	if (pStack != NULL) {
		pNode = (StackNode*)malloc(sizeof(StackNode));	// �Ҵ�
		if (pNode != NULL) {
			memset(pNode, 0, sizeof(StackNode));	// 0 Set
			*pNode = element;
			pNode->pLink = pStack->pTopElement;
			pStack->pTopElement = pNode;
			pStack->currentElementCount++;	// Count++ ��尹��
		}
		else {
			printf("�޸� �Ҵ� ���� pushLS()\n");
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

StackNode* peekLS(LinkedStack* pStack) {	// Void ���� ���� Return�� X / pReturn -> pPeekData  
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
	// free �� ��� �Ҵ� ����
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
		printf("��� ����: %d\n",
			pStack->currentElementCount);
		pNode = pStack->pTopElement;
		while (pNode != NULL) {
			printf("%d : %c\n", pStack->currentElementCount - i, pNode->data);
			i++;
			pNode = pNode->pLink;
		}
	}
}
