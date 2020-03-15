#pragma once
#define TRUE 1
#define FALSE 0
typedef struct ListNodeType {
	int data;	// 저장할 데이터
	struct ListNodeType* pLink; // 연결된 노드 
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode headerNode;		// 헤더 노드
} LinkedList;


LinkedList* createLinkedList();	// LinkedList 초기화
int addElement(LinkedList* pList, int position, ListNode element);	// 원소 추가
int removeElement(LinkedList* pList, int position);	// 원소 제거
ListNode* getElement(LinkedList* pList, int position); // 원소 가져오기
void clearLinkedList(LinkedList* pList);	// 리스트 정리
int getLinkedListLength(LinkedList* pList);	// 리스트 갯수가져오기
void deleteLinkedList(LinkedList* pList);	// 리스트 삭제
void displayLinkedList(LinkedList* pList);