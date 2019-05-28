/*
* ����һ���ڴ�
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

	// �������� operator new ������ operator delete ���������ڽӹ�new�����������ڴ�Ĳ���
	void* operator new(size_t); // һ����static�������Բ�д������c++�����ķ���
	void operator delete(void*, size_t); // һ����static

private:
	Screen* next; // �����ķ���һ��ָ��Ĵ洢�ռ䣬ָ��Screen
	static Screen* freeStore; // �ڴ�صĿ��в��ֵ��׵�ֵ
	static const int screenChunk; // ��������ڴ��

private:
	int i;
};


#endif
