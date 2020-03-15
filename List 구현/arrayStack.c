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

		for (i = 0; i < create; i++) {	// 0~4 �ϰ� �ϳ� ����ֺ���.
			printf("%d. ������ �Է� :", i + 1);
			scanf("%c", &value[i]);
			getchar();		// enter Ű ó��
			fflush(stdin);	// ���� ����
		}
		ArrayStackNode node[5] = { 0 };	// node �迭�� ����

		for (i = 0; i < create; i++) {
			node[i].data = value[i];
			pushAS(pStack, node[i]);
		}
	
		displayArrayStack(pStack);

		pNode = popAS(pStack);
		if (pNode != NULL) {
			printf("Pop ��-[%c]\n", pNode->data);
			free(pNode);		// ��ȯ�� �Ҵ� ����
		}
		else {
			printf("����(Empty) ����\n");
		}
		displayArrayStack(pStack);

		pNode = peekAS(pStack);
		if (pNode != NULL) {
			printf("Peek ��-[%c]\n", pNode->data);
		}
		else {
			printf("����(Empty) ����\n");	// ArrayStack �̿��� Empty ����
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
			printf("�޸� �Ҵ� ����! pReturn");
			return NULL;
		}

		pReturn->pElement = (ArrayStackNode*)malloc(sizeof(ArrayStackNode) * size);
		if (pReturn->pElement != NULL) {
			memset(pReturn->pElement, 0, sizeof(ArrayStackNode) * size);	// �����ŭ Set
		}
		else {
			printf("�޸� �Ҵ� ����! pElement");
			free(pReturn); 
			return NULL;
		}
	}
	else {
		printf("������ ũ�Ⱑ �������� �ʾҽ��ϴ�.");	// 0 ���ٴ� Ŀ�� �Ҵ� ����
		return NULL;
	}
	return pReturn;
}

void pushAS(ArrayStack* pStack, ArrayStackNode element)
{
	int i = 0;

	if (pStack != NULL) {
		if (isArrayStackFull(pStack) == FALSE) {		// Array�� ũ�� ������
			pStack->pElement[pStack->currentElementCount] = element;
			pStack->currentElementCount++;
		}
		else {
			printf("���� �뷮 �ʰ�");
		}
	}
}

ArrayStackNode* popAS(ArrayStack* pStack)	// ��� ���� ��ȯ
{
	ArrayStackNode* pReturn = NULL;
	if (pStack != NULL) {
		if (isArrayStackEmpty(pStack) == FALSE) {
			pReturn = (ArrayStackNode*)malloc(sizeof(ArrayStackNode));
			if (pReturn != NULL) {
				*pReturn = pStack->pElement[pStack->currentElementCount - 1];
				pStack->currentElementCount--;	//�Ҵ����� ī��� -1
			}
			else {
				printf("�޸� �Ҵ���� popAs");
			}
		}
	}
	return pReturn;
}

ArrayStackNode* peekAS(ArrayStack* pStack)	// ��� ��ȯ
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

int isArrayStackFull(ArrayStack* pStack){	// Array���� �߿�! Linked �� ū ������
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

		printf("���� ũ��: %d ||  ��� ����: %d\n", pStack->maxElementCount, pStack->currentElementCount);

		for (i = size - 1; i >= top; i--) {
			printf("%d : Empty \n", i);
		}

		for (i = top - 1; i >= 0; i--) {
			printf("%d : %c\n", i, pStack->pElement[i].data);
		}
	}
}