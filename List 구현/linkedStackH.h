#pragma once
#define TRUE		1
#define FALSE		0

typedef struct StackNodeType
{
	char data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// 현재 원소의 개수
	StackNode* pTopElement;		// Top 노드의 포인터
} LinkedStack;

LinkedStack* createLinkedStack(); // LinkedStack 만들기
void pushLS(LinkedStack* pStack, StackNode element); // 노드 값 넣기
StackNode* popLS(LinkedStack* pStack); // POP 방식
StackNode* peekLS(LinkedStack* pStack); // Peek 방식
void deleteLinkedStack(LinkedStack* pStack); // 지우기
int isLinkedStackEmpty(LinkedStack* pStack); // 빈 상태 확인
void displayLinkedStack(LinkedStack* pStack);

