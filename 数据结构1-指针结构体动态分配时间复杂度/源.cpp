#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
struct point {
	int x;
	int y;
};
int main() {
	point p;
	p.x = 10;
	p.y = 6;

	return 0;
}

//ָ����ṹ��
struct point* pp;
//(*pp).x= 10;     �ȼ���pp->x = 10;
//(*pp).y = 5;     �ȼ���pp->y = 5;

//��̬�ڴ����
//c���԰棺
int main() {
	int* p;
	p = (int*)malloc(sizeof(int));
	*p = 100;
	free(p);
	p = NULL;
	return 0;
}
//c++��
int main() {
	int* q;
	q = new int;
	*q = 100;
	delete q;
	q = nullptr;
	return 0;
}

// ����Ƶ��
//һ�����ʱ�临�Ӷ�
//����Ϊo1��
//log��Ҫ��i�仯��ʽ
//����Ҫ������ѧ����







