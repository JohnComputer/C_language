#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListHeader.h"

int main() {
	int i = 0;
	int arrayCount = 0;
	LinkedList* pList = NULL;
	ListNode* pNode = NULL;
	ListNode node;

	pList = createLinkedList(); // �׻� ���� ���� ����.

	/*
	node.data = 1;
	addElement(pList, 0, node);
	node.data = 3;
	addElement(pList, 1, node);
	displayLinkedList(pList);
	removeElement(pList, 0);
	displayLinkedList(pList);
	deleteLinkedList(pList);
	���� */ 
}

LinkedList* createLinkedList() {
	LinkedList* pReturn = NULL;
	int i = 0;

	pReturn = (LinkedList*)malloc(sizeof(LinkedList));	//LinkedList �����ŭ �Ҵ� (Type ����)
	if (pReturn == NULL) {
		printf("�޸��Ҵ� �����Դϴ�.");
		return NULL;
	}
	else {
		memset(pReturn, 0, sizeof(LinkedList)); // �޸� ���� 
	}
	return pReturn;
}

int addElement(LinkedList* pList, int position, ListNode element) {
	int ret = FALSE;
	int i = 0;
	ListNode* pPreNode = NULL; // ���� ���
	ListNode* pNewNode = NULL; // �߰��� ���
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementCount) {	// 0~���簹�� �߰��� ��������
			pNewNode = (ListNode*)malloc(sizeof(ListNode));
			if (pNewNode != NULL) {
				*pNewNode = element; // �߰��� ����
				pNewNode->pLink = NULL; // ������ ��ġ �ʱ�ȭ
				pPreNode = &(pList->headerNode);

				for (i = 0; i < position; i++) {
					pPreNode = pPreNode->pLink;
				}
				pNewNode->pLink = pPreNode->pLink;	// ���ο� ��Ʈ ��ũ�� ������ ����Ű�� ��ũ����
				pPreNode->pLink = pNewNode;	//	������ũ�� ���� �߰��Ȱ� ����

				pList->currentElementCount++;	// ī��Ʈ����
				ret = TRUE;
			}
			else {
				printf("�޸� �Ҵ� �����Դϴ�.");
			}
		}
		else {
			printf("�߰��� ��ġ �����Դϴ�.");
		}
	}
}

int removeElement(LinkedList* pList, int position){
	int ret = FALSE;
	int i = 0;
	int arrayCount = 0;	// ���� ����
	ListNode* pNode = NULL;	//���
	ListNode* pDelNode = NULL;	// ��������ϴ� ���

	if (pList != NULL) {
		arrayCount = getLinkedListLength(pList);	// ���� �޾ƿ���
		if (position >= 0 && position < arrayCount)
		{
			pNode = &(pList->headerNode);

			for (i = 0; i < position; i++) {
				pNode = pNode->pLink;	//pNode->pLink�� ������ ���������� for������ ���������� ���ư� 
			}

			pDelNode = pNode->pLink;
			pNode->pLink = pDelNode->pLink;
			free(pDelNode);	// �Ҵ� ����

			pList->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("%d, ��ġ �ε��� �����Դϴ�.", position);
		}
	}
	return ret;
}

ListNode* getElement(LinkedList* pList, int position){

	ListNode* pReturn = NULL;	// ��ȯ�� ����
	int i = 0;
	ListNode* pNode = NULL;	// ���

	if (pList != NULL) {
		if (position >= 0 && position < pList->currentElementCount) {
			pNode = &(pList->headerNode);
			for (i = 0; i <= position; i++) {
				pNode = pNode->pLink;
			}
			pReturn = pNode;
		}
	}

	return pReturn;
}

void displayLinkedList(LinkedList* pList){
	int i = 0;
	if (pList != NULL) {
		printf("���� ����: %d\n", pList->currentElementCount);

		for (i = 0; i < pList->currentElementCount; i++) {
			printf("%d�� = %d\n", i, getElement(pList, i)->data);
		}
	}
	else {
		printf("���Ұ� �����ϴ�.\n");
	}
}
void deleteLinkedList(LinkedList* pList){
	int i = 0;
	if (pList != NULL) {
		clearLinkedList(pList);
		free(pList);
	}
}

void clearLinkedList(LinkedList* pList){
	if (pList != NULL) {
		if (pList->currentElementCount > 0) {
			removeElement(pList, 0);
		}
	}
}

int getLinkedListLength(LinkedList* pList){
	int ret = 0;

	if (pList != NULL) {
		ret = pList->currentElementCount;
	}

	return ret;
}

int isEmpty(LinkedList* pList){
	int ret = FALSE;

	if (pList != NULL) {
		if (pList->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}
