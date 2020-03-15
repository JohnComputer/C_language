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
	int currentElementCount;	// ���� ������ ����
	StackNode* pTopElement;		// Top ����� ������
} LinkedStack;

LinkedStack* createLinkedStack(); // LinkedStack �����
void pushLS(LinkedStack* pStack, StackNode element); // ��� �� �ֱ�
StackNode* popLS(LinkedStack* pStack); // POP ���
StackNode* peekLS(LinkedStack* pStack); // Peek ���
void deleteLinkedStack(LinkedStack* pStack); // �����
int isLinkedStackEmpty(LinkedStack* pStack); // �� ���� Ȯ��
void displayLinkedStack(LinkedStack* pStack);

