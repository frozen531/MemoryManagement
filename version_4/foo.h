#pragma once
#ifndef FOO_H
#define FOO_H

#include <string>
#include "allocator.h"

#define DECLARE_POOL_ALLOC()
static Allocator myAlloc;
void* operator new(size_t size) { return myAlloc.allocate(size); }
void operator delete(void* pdead, size_t size) { return myAlloc.deallocate(pdead, size); }

#define IMPLEMENT_POOL_ALLOC(class_name)
Allocator class_name::myAlloc;

class Foo
{
	DECLARE_POOL_ALLOC() // 内存分配与释放

public:
	long L;
	std::string str;

public:
	Foo(long l):L(l){}
};

IMPLEMENT_POOL_ALLOC(Foo)
#endif
