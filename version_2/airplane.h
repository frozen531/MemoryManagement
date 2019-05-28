#pragma once
#ifndef AIRPLANE_H
#define AIRPLANE_H

class Airplane
{
private:
	struct AirplaneRep // ����Ϊ4+1=5�����ǻ���뵽8
	{
		unsigned long miles;
		char type;
	};
private:
	union // ���Դ�СΪ8,����member����ʾͬһ�����������ֲ�ͬ�ı�����ʽ
	{
		AirplaneRep rep; // ����
		Airplane* next; // ��СΪ4������ָ�� embedded pointer
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
