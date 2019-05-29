/*
* 将内存分配工作提取成allocator类
*/
#include "foo.h"
#include <iostream>
using namespace std;

int main()
{
	Foo* p[100];

	cout << "sizeof(long)=" << sizeof(long) << endl;
	cout << "sizeof(string)=" << sizeof(string) << endl;
	cout << "sizeof(Foo)=" << sizeof(Foo) << endl;

	cout << "sizeof(Allocator)=" << sizeof(Allocator) << endl; // *, int
	
	for (int i = 0; i < 23; ++i)
	{
		p[i] = new Foo(i);
		cout << p[i] << " " << p[i]->L << endl;
	}

	for (int i = 0; i < 23; ++i)
	{
		delete p[i];
	}

	system("pause");
	return 0;
}