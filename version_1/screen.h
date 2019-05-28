/*
* 先挖一块内存
*/

#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
using namespace std;
class Screen
{
public:
	Screen(int x) :i(x) {};
	int get() { return i; }

	// 类内重载 operator new 函数和 operator delete 函数，用于接管new操作中申请内存的部分
	void* operator new(size_t); // 一定是static，但可以不写，这是c++的贴心服务
	void operator delete(void*, size_t); // 一定是static

private:
	Screen* next; // 这里多耗费了一个指针的存储空间，指向Screen
	static Screen* freeStore; // 内存池的空闲部分的首地值
	static const int screenChunk; // 分配多少内存块

private:
	int i;
};


#endif
