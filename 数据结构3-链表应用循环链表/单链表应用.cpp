//线性表重排序问题

#include<iostream>
#include<string>
using namespace std;
typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node* next;
}Node;
// 打印链表
void printList(Node* head) {
	Node* p = head->next;  // 跳过头节点
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
// 尾插法添加元素（用于给链表添加数据）
void insertTail(Node* head, ElemType val) {
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = nullptr;

	// 找到尾节点
	Node* tail = head;
	while (tail->next != nullptr) {
		tail = tail->next;
	}
	tail->next = newNode;
	head->data++;  // 更新长度
}
Node* initList() {
	Node* head = new Node;
	if (head == nullptr) {  // 检查内存分配是否成功
		printf("内存分配失败\n");
		return nullptr;
	}
	head->data = 0;
	head->next = nullptr;
	return head;
}


//1.找中间节点
Node*midnode(Node* head) {
	Node* fast = head->next;
	Node* slow = head;
	while (fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
//分为两节，并把第二节倒序,将两节交叉相连

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
// 释放链表内存
void freeList(Node* head) {
	Node* temp;
	while (head != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
	}
}
// 交叉合并两个链表
void merge(Node* L1, Node* L2) {
	Node* p = L1->next;  // L1的第一个有效节点
	Node* q = L2;        // L2的第一个有效节点（已反转）
	Node* pNext, * qNext;

	while (p != nullptr && q != nullptr) {
		pNext = p->next;  // 保存L1下一个节点
		qNext = q->next;  // 保存L2下一个节点

		p->next = q;      // L1节点后接L2节点
		if (pNext != nullptr) {
			q->next = pNext;  // L2节点后接L1的下一个节点
		}

		p = pNext;        // 移动到L1下一个节点
		q = qNext;        // 移动到L2下一个节点
	}
}
int main() {
	// 1. 初始化链表并添加数据
	Node* head = initList();
	insertTail(head, 0);   // 添加数据：0->6->2->6
	insertTail(head, 6);
	insertTail(head, 2);
	insertTail(head, 6);

	cout << "原始链表: ";
	printList(head);  // 输出：0 6 2 6

	// 2. 找到中间节点，分割链表
	Node* mid = midnode(head);  // 中间节点前的尾节点
	Node* L2 = mid->next;       // 后半部分：2->6
	mid->next = nullptr;        // 切断前半部分与后半部分

	// 3. 反转后半部分
	L2 = reverseNode(L2);  // 反转后：6->2

	// 4. 交叉合并
	merge(head, L2);

	// 5. 输出结果
	cout << "重排序后: ";
	printList(head);  // 输出：0 6 6 2
	// 6. 释放内存
	freeList(head);
	return 0;
}

















