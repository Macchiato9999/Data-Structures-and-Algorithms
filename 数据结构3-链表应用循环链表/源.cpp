#include<iostream>
#include<string>
using namespace std;
typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node* next;
}Node;

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
//˫ָ�루����ָ�룩
int fingNodeFS(Node*L,int k) {
	Node* fast = L->next;
	Node* slow = L->next;
	for (int i = 0; i < k; i++) {
		fast = fast->next;
	}
	while (fast != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	cout << slow->data;
	return 0;
}

// ɾ������ֵ��ͬ�Ľڵ�
void removeNode(Node* L, int n) {
	Node* p = L;
	int index;
	int* q = new(int);
	for (int i = 0; i < n + 1; i++) {
		*(q + 1) = 0;
	}
	while (p->next !=NULL) {
		index = abs(p->next->data);
		if (*(q + index) = 0) {
			*(q + index) = 1;
			p = p->next;
		}
		else {
			Node* temp = p->next;
			p->next = temp->next;
			delete temp;
		}
	}
	delete q;
  }

//��ת����
Node* reverseList(Node* head) {
	Node* first = NULL;
	Node* second = head->next;
	Node* third;
	while (second != NULL) {
		third = second->next;
		second->next = first;
		first = second;
		second = third;
	}
	Node* hd = initList();
	hd->next = first;

	return hd;
}























