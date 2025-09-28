//˳���

//��ʼ��
#include<iostream>
#include <string>
using namespace std;

#define MAXSIZE 100
typedef int ElemType;

typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SeqList;

void initList(SeqList* L) {
	L->length = 0;
}
//β�����Ԫ��
void appendElem(SeqList* L, ElemType e) {
	if (L->length >= MAXSIZE) {
		cout << "˳�������";
	}
	else {
		L->data[L->length] = e;
		L->length++;
	}
}
//����
void listElem(SeqList* L) {
	for (int i = 0; i < L->length; i++) {
		cout << L->data[i] << " ";
	}
	cout << endl;
}
//����Ԫ��
void insertElem(SeqList* L, int n, ElemType e) {
	if (n > L->length) {
		cout << "������";
	}
	else {
		for (int i = L->length - 1; i >= n - 1; i--) {
			L->data[i + 1] = L->data[i];
		}
		L->data[n - 1] = e;
	}
	L->length++;
}
//ɾ��Ԫ��
void deleteElem(SeqList* L, int m) {
	if (m > L->length) {
		cout << "�����ڸ�λ��Ԫ��";
	}
	else {
		for (int i = m; i < L->length; i++) {
			L->data[i - 1] = L->data[i];
		}
	}
	L->length--;
}
//������
//int main(int argc, char const* argv[]) {
//	SeqList list;
//	initList(&list);
//	printf("��ʼ���ɹ�������ռ��%d\n", list.length);
//	printf("Ŀǰռ���ڴ�%zu�ֽ�\n", sizeof(list.data));
//	appendElem(&list, 0);
//	appendElem(&list, 6);
//	appendElem(&list, 0);
//	appendElem(&list, 2);
//	appendElem(&list, 7);
//	appendElem(&list, 6);
//	listElem(&list);
//	deleteElem(&list, 5);
//	listElem(&list);
//	insertElem(&list, 4, 6);
//	listElem(&list);
//	return 0;
//}

//��������̬�����ڴ�δд


//������

//��ʼ��
typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node* next;
}Node;

Node* initList() {
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL) {  // ����ڴ�����Ƿ�ɹ�
		printf("�ڴ����ʧ��\n");
		return NULL;
	}
	head->data = 0;
	head->next = NULL;
	return head;
}
//int main() {
//	Node *list = initList();
//	return 0;
//}

//ͷ�巨
void insertHead(Node* L, ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	L->next = p;
}
// ����
void listNode(Node* L) {
	Node* p = L->next;
	while (p != NULL) {
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}
//β�巨
//��ȡβ���ĵ�ַ
Node* get_tail(Node* L) {
	Node* p = L;
	while (p->next != NULL) {
		p = p->next;
	}
	return p;
}

Node* insertTail(Node* tail, ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	tail->next = p;
	p->next = NULL;
	return p;
}

//��ָ��λ�ò���
int insertNode(Node* L, int pos, ElemType e) {
	//�������������ǰ���ڵ�
	Node* p = L;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
		if (p == NULL) {
			return 0;
		}
	}
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}

//ɾ���ڵ�
int deleteNode(Node* L, ElemType pos) {
	Node* p = L;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
		if (p== NULL) {
			cout << "ɾ������";
			return 1;
		}
	}
	if (p->next== NULL) {
		cout << "ɾ������";
		return 1;
	}
	Node* q = p->next;
	p->next = q->next;
	free(q);
	return 0;
}

//�ͷ���������Ҫ������
void freeList(Node* L) {
	Node* p = L->next;
	Node* q;
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}

int main() {
	Node* list = initList();
	insertHead(list, 2);
	insertHead(list, 0);
	insertHead(list, 2);
	insertHead(list, 4);
	deleteNode(list, 1);
	Node* tail = get_tail(list);
	tail = insertTail(tail, 5);
	listNode(list);
	freeList(list);
	return 0;

}










































