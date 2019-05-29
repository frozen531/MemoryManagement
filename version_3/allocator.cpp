#include "allocator.h"

void* Allocator::allocate(size_t size)
{
	obj* p;

	// 空了，申请空间
	if (!freeStore) 
	{
		size_t chunk = CHUNK*size;
		freeStore = p = (obj*)malloc(chunk);

		for (int i = 0; i < (CHUNK - 1); ++i)
		{
			p->next = (obj*)((char*)p + size);
			p = p->next;
		}
		p->next = nullptr;
	}

	// 没空，后移
	p = freeStore;
	freeStore = freeStore->next;
	return p;
}

// 将*p回收入list前端
void Allocator::deallocate(void* p, size_t)
{
	((obj*)p)->next = freeStore;
	freeStore = (obj*)p;
}

