#pragma once
#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstdlib>

class Allocator
{
private:
	struct obj
	{
		struct obj* next; // embedded pointer
	};
public:
	void* allocate(size_t);
	void deallocate(void*, size_t);
private:
	obj* freeStore = nullptr;
	const int CHUNK = 5;
};

#endif