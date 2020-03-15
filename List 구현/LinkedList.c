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

	pList = createLinkedList(); // 항상 가장 먼저 실행.

	/*
	node.data = 1;
	addElement(pList, 0, node);
	node.data = 3;
	addElement(pList, 1, node);
	displayLinkedList(pList);
	removeElement(pList, 0);
	displayLinkedList(pList);
	deleteLinkedList(pList);
	예시 */ 
}

LinkedList* createLinkedList() {
	LinkedList* pReturn = NULL;
	int i = 0;

	pReturn = (LinkedList*)malloc(sizeof(LinkedList));	//LinkedList 사이즈만큼 할당 (Type 지정)
	if (pReturn == NULL) {
		printf("메모리할당 오류입니다.");
		return NULL;
	}
	else {
		memset(pReturn, 0, sizeof(LinkedList)); // 메모리 세팅 
	}
	return pReturn;
}

int addElement(LinkedList* pList, int position, ListNode element) {
	int ret = FALSE;
	int i = 0;
	ListNode* pPreNode = NULL; // 이전 노드
	ListNode* pNewNode = NULL; // 추가할 노드
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementCount) {	// 0~현재갯수 추가만 이하적용
			pNewNode = (ListNode*)malloc(sizeof(ListNode));
			if (pNewNode != NULL) {
				*pNewNode = element; // 추가될 원소
				pNewNode->pLink = NULL; // 연결할 위치 초기화
				pPreNode = &(pList->headerNode);

				for (i = 0; i < position; i++) {
					pPreNode = pPreNode->pLink;
				}
				pNewNode->pLink = pPreNode->pLink;	// 새로운 노트 링크에 기존에 가리키턴 링크연결
				pPreNode->pLink = pNewNode;	//	이전링크에 새로 추가된곳 연결

				pList->currentElementCount++;	// 카운트증가
				ret = TRUE;
			}
			else {
				printf("메모리 할당 오류입니다.");
			}
		}
		else {
			printf("추가할 위치 오류입니다.");
		}
	}
}

int removeElement(LinkedList* pList, int position){
	int ret = FALSE;
	int i = 0;
	int arrayCount = 0;	// 연결 길이
	ListNode* pNode = NULL;	//노드
	ListNode* pDelNode = NULL;	// 지우고자하는 노드

	if (pList != NULL) {
		arrayCount = getLinkedListLength(pList);	// 길이 받아오기
		if (position >= 0 && position < arrayCount)
		{
			pNode = &(pList->headerNode);

			for (i = 0; i < position; i++) {
				pNode = pNode->pLink;	//pNode->pLink는 다음을 참조함으로 for구문이 정상적으로 돌아감 
			}

			pDelNode = pNode->pLink;
			pNode->pLink = pDelNode->pLink;
			free(pDelNode);	// 할당 해제

			pList->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("%d, 위치 인덱스 오류입니다.", position);
		}
	}
	return ret;
}

ListNode* getElement(LinkedList* pList, int position){

	ListNode* pReturn = NULL;	// 반환값 저장
	int i = 0;
	ListNode* pNode = NULL;	// 노드

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
		printf("원소 개수: %d\n", pList->currentElementCount);

		for (i = 0; i < pList->currentElementCount; i++) {
			printf("%d번 = %d\n", i, getElement(pList, i)->data);
		}
	}
	else {
		printf("원소가 없습니다.\n");
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
