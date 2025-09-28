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

//指针与结构体
struct point* pp;
//(*pp).x= 10;     等价于pp->x = 10;
//(*pp).y = 5;     等价于pp->y = 5;

//动态内存分配
//c语言版：
int main() {
	int* p;
	p = (int*)malloc(sizeof(int));
	*p = 100;
	free(p);
	p = NULL;
	return 0;
}
//c++版
int main() {
	int* q;
	q = new int;
	*q = 100;
	delete q;
	q = nullptr;
	return 0;
}

// 计算频度
//一般算最坏时间复杂度
//常数为o1；
//log的要看i变化方式
//具体要进行数学运算







