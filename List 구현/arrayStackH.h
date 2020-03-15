#pragma once

#define TRUE		1
#define FALSE		0

typedef struct ArrayStackNodeType {
	char data;		//�ٸ� ������ �߰� ����
} ArrayStackNode;

typedef struct ArrayStackType {
	int maxElementCount;		// �ִ� ���� ����
	int currentElementCount;	// ���� ������ ����
	ArrayStackNode* pElement;	// ��� ������ ���� 1���� array
} ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);		// ArrayStack �����
void pushAS(ArrayStack* pStack, ArrayStackNode element);	// ��� �� �ֱ�
ArrayStackNode* popAS(ArrayStack* pStack);	// POP ���
ArrayStackNode* peekAS(ArrayStack* pStack);	// Peek ���
void deleteArrayStack(ArrayStack* pStack);	// �����
int isArrayStackFull(ArrayStack* pStack);	// ������ ���� Ȯ��
int isArrayStackEmpty(ArrayStack* pStack);	// �� ���� Ȯ��
void displayArrayStack(ArrayStack* pStack); // ȭ�� ���


