#pragma once
#ifndef AIRPLANE_H
#define AIRPLANE_H

class Airplane
{
private:
	struct AirplaneRep // 长度为4+1=5，但是会对齐到8
	{
		unsigned long miles;
		char type;
	};
private:
	union // 所以大小为8,两个member，表示同一个东西，两种不同的表现形式
	{
		AirplaneRep rep; // 对象
		Airplane* next; // 大小为4，对象指针 embedded pointer
	};
public:
	unsigned long getMiles() { return rep.miles; }
	char getType() { return rep.type; }
	void set(unsigned long m, char t) { rep.miles = m; rep.type = t; }

public:
	static void* operator new(size_t size);
	static void operator delete(void* deadObject, size_t size);

private:
	static const int BLOCK_SIZE;
	static Airplane* headOfFreeList;
};

#endif
