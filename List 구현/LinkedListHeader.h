#pragma once
#define TRUE 1
#define FALSE 0
typedef struct ListNodeType {
	int data;	// ������ ������
	struct ListNodeType* pLink; // ����� ��� 
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// ���� ����� ������ ����
	ListNode headerNode;		// ��� ���
} LinkedList;


LinkedList* createLinkedList();	// LinkedList �ʱ�ȭ
int addElement(LinkedList* pList, int position, ListNode element);	// ���� �߰�
int removeElement(LinkedList* pList, int position);	// ���� ����
ListNode* getElement(LinkedList* pList, int position); // ���� ��������
void clearLinkedList(LinkedList* pList);	// ����Ʈ ����
int getLinkedListLength(LinkedList* pList);	// ����Ʈ ������������
void deleteLinkedList(LinkedList* pList);	// ����Ʈ ����
void displayLinkedList(LinkedList* pList);