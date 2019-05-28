#include "airplane.h"

Airplane* Airplane::headOfFreeList = nullptr;
const int Airplane::BLOCK_SIZE = 512;

void* Airplane::operator new(size_t size)
{
	// 判断传入的大小是否与Airplane真实大小一致，若不一致，交给::operator new()
	// 当继承发生时就会出现不一致问题
	if (size != sizeof(Airplane)) 
		return ::operator new(size);

	Airplane* p = headOfFreeList;
	if (p) // 如果p有效，就把list下移一个元素
		headOfFreeList = p->next;
	else
	{
		// 申请一大块内存
		Airplane* newBlock = static_cast<Airplane*>(::operator new(BLOCK_SIZE * sizeof(Airplane)));

		// 内存块间串接指针
		for (int i = 1; i < BLOCK_SIZE - 1; ++i)
			newBlock[i].next = &newBlock[i + 1];
		newBlock[BLOCK_SIZE - 1].next = nullptr;

		p = newBlock;
		headOfFreeList = &newBlock[1];
	}
	return p;
}

void Airplane::operator delete(void* deadObject, size_t size)
{
	if (deadObject == nullptr)return;

	// 判断要回收的内存大小是否正确
	if (size != sizeof(Airplane)) { 
		::operator delete(deadObject);
		return;
	}

	// 回收的指针放入单向链表的头
	Airplane* carcess = static_cast<Airplane*>(deadObject);

	carcess->next = headOfFreeList;
	headOfFreeList = carcess;
}
