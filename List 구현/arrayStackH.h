#pragma once

#define TRUE		1
#define FALSE		0

typedef struct ArrayStackNodeType {
	char data;		//다른 데이터 추가 가능
} ArrayStackNode;

typedef struct ArrayStackType {
	int maxElementCount;		// 최대 원소 개수
	int currentElementCount;	// 현재 원소의 개수
	ArrayStackNode* pElement;	// 노드 저장을 위한 1차원 array
} ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);		// ArrayStack 만들기
void pushAS(ArrayStack* pStack, ArrayStackNode element);	// 노드 값 넣기
ArrayStackNode* popAS(ArrayStack* pStack);	// POP 방식
ArrayStackNode* peekAS(ArrayStack* pStack);	// Peek 방식
void deleteArrayStack(ArrayStack* pStack);	// 지우기
int isArrayStackFull(ArrayStack* pStack);	// 가득찬 상태 확인
int isArrayStackEmpty(ArrayStack* pStack);	// 빈 상태 확인
void displayArrayStack(ArrayStack* pStack); // 화면 출력


