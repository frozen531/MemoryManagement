#include "screen.h"

Screen* Screen::freeStore = nullptr; // 指向空闲空间的首地值，相当于单向链表的首地值
const int Screen::screenChunk = 24; // 一次申请多少个Screen大小的空间

void* Screen::operator new(size_t size)
{
	Screen* p;

	// 如果freeStore是空的，则在内存中挖一大块内存
	if (!freeStore)
	{
		size_t chunk = screenChunk * size; // 要申请的内存大小
		freeStore = p = reinterpret_cast<Screen*>(new char[chunk]); // 相当于调用malloc申请chunk个char类型,freeStore是空闲空间的首地值

		// 分割内存成一片片，并串接起来，p是Screen指针
		for (; p != &freeStore[screenChunk - 1]; ++p)
			p->next = p + 1; // Screen中指针串接
		p->next = nullptr; // 末个元素的指针置空
	}

	// 如果freeStore不为空，freeStore对应的赋值给p，freeStore后移
	p = freeStore;
	freeStore = freeStore->next;
	return p;
}

// 这里的delete并没有free内存，只是将内存块重新放入内存池中，移动首指针即可
void Screen::operator delete(void* p, size_t)
{
	(static_cast<Screen*>(p))->next = freeStore; // 删除的内存接入单向链表首部
	freeStore = static_cast<Screen*>(p); // freeStore向前移动，回到插入后的链表首部
}
