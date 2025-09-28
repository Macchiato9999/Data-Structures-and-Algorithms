//���Ա�����������

#include<iostream>
#include<string>
using namespace std;
typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node* next;
}Node;
// ��ӡ����
void printList(Node* head) {
	Node* p = head->next;  // ����ͷ�ڵ�
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
// β�巨���Ԫ�أ����ڸ�����������ݣ�
void insertTail(Node* head, ElemType val) {
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = nullptr;

	// �ҵ�β�ڵ�
	Node* tail = head;
	while (tail->next != nullptr) {
		tail = tail->next;
	}
	tail->next = newNode;
	head->data++;  // ���³���
}
Node* initList() {
	Node* head = new Node;
	if (head == nullptr) {  // ����ڴ�����Ƿ�ɹ�
		printf("�ڴ����ʧ��\n");
		return nullptr;
	}
	head->data = 0;
	head->next = nullptr;
	return head;
}


//1.���м�ڵ�
Node*midnode(Node* head) {
	Node* fast = head->next;
	Node* slow = head;
	while (fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
//��Ϊ���ڣ����ѵڶ��ڵ���,�����ڽ�������

Node* reverseNode(Node* L) {
	Node* first = nullptr;
	Node* second = L;
	Node* third = nullptr;
	while(second != nullptr) {
		third = second->next;
		second->next = first;
		first = second;
		second = third;
	}
	return first;
}
// �ͷ������ڴ�
void freeList(Node* head) {
	Node* temp;
	while (head != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
	}
}
// ����ϲ���������
void merge(Node* L1, Node* L2) {
	Node* p = L1->next;  // L1�ĵ�һ����Ч�ڵ�
	Node* q = L2;        // L2�ĵ�һ����Ч�ڵ㣨�ѷ�ת��
	Node* pNext, * qNext;

	while (p != nullptr && q != nullptr) {
		pNext = p->next;  // ����L1��һ���ڵ�
		qNext = q->next;  // ����L2��һ���ڵ�

		p->next = q;      // L1�ڵ���L2�ڵ�
		if (pNext != nullptr) {
			q->next = pNext;  // L2�ڵ���L1����һ���ڵ�
		}

		p = pNext;        // �ƶ���L1��һ���ڵ�
		q = qNext;        // �ƶ���L2��һ���ڵ�
	}
}
int main() {
	// 1. ��ʼ�������������
	Node* head = initList();
	insertTail(head, 0);   // ������ݣ�0->6->2->6
	insertTail(head, 6);
	insertTail(head, 2);
	insertTail(head, 6);

	cout << "ԭʼ����: ";
	printList(head);  // �����0 6 2 6

	// 2. �ҵ��м�ڵ㣬�ָ�����
	Node* mid = midnode(head);  // �м�ڵ�ǰ��β�ڵ�
	Node* L2 = mid->next;       // ��벿�֣�2->6
	mid->next = nullptr;        // �ж�ǰ�벿�����벿��

	// 3. ��ת��벿��
	L2 = reverseNode(L2);  // ��ת��6->2

	// 4. ����ϲ�
	merge(head, L2);

	// 5. ������
	cout << "�������: ";
	printList(head);  // �����0 6 6 2
	// 6. �ͷ��ڴ�
	freeList(head);
	return 0;
}

















