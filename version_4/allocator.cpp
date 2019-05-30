#include "allocator.h"

void* Allocator::allocate(size_t size)
{
	obj* p;

	// ���ˣ�����ռ�
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

	// û�գ�����
	p = freeStore;
	freeStore = freeStore->next;
	return p;
}

// ��*p������listǰ��
void Allocator::deallocate(void* p, size_t)
{
	((obj*)p)->next = freeStore;
	freeStore = (obj*)p;
}

