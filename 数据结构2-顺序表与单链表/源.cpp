//顺序表

//初始化
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
//尾部添加元素
void appendElem(SeqList* L, ElemType e) {
	if (L->length >= MAXSIZE) {
		cout << "顺序表已满";
	}
	else {
		L->data[L->length] = e;
		L->length++;
	}
}
//遍历
void listElem(SeqList* L) {
	for (int i = 0; i < L->length; i++) {
		cout << L->data[i] << " ";
	}
	cout << endl;
}
//插入元素
void insertElem(SeqList* L, int n, ElemType e) {
	if (n > L->length) {
		cout << "超长了";
	}
	else {
		for (int i = L->length - 1; i >= n - 1; i--) {
			L->data[i + 1] = L->data[i];
		}
		L->data[n - 1] = e;
	}
	L->length++;
}
//删除元素
void deleteElem(SeqList* L, int m) {
	if (m > L->length) {
		cout << "不存在该位置元素";
	}
	else {
		for (int i = m; i < L->length; i++) {
			L->data[i - 1] = L->data[i];
		}
	}
	L->length--;
}
//主操作
//int main(int argc, char const* argv[]) {
//	SeqList list;
//	initList(&list);
//	printf("初始化成功，长度占用%d\n", list.length);
//	printf("目前占用内存%zu字节\n", sizeof(list.data));
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

//！！！动态分配内存未写


//单链表

//初始化
typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node* next;
}Node;

Node* initList() {
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL) {  // 检查内存分配是否成功
		printf("内存分配失败\n");
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

//头插法
void insertHead(Node* L, ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	L->next = p;
}
// 遍历
void listNode(Node* L) {
	Node* p = L->next;
	while (p != NULL) {
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}
//尾插法
//获取尾结点的地址
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

//在指定位置插入
int insertNode(Node* L, int pos, ElemType e) {
	//用来保留插入的前驱节点
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

//删除节点
int deleteNode(Node* L, ElemType pos) {
	Node* p = L;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
		if (p== NULL) {
			cout << "删除错误";
			return 1;
		}
	}
	if (p->next== NULL) {
		cout << "删除错误";
		return 1;
	}
	Node* q = p->next;
	p->next = q->next;
	free(q);
	return 0;
}

//释放链表（最重要！！）
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










































