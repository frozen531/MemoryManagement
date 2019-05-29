#pragma once
#ifndef FOO_H
#define FOO_H

#include <string>
#include "allocator.h"

class Foo
{
public:
	long L;
	std::string str;
	static Allocator myAlloc;

public:
	Foo(long l):L(l){}
	static void* operator new(size_t size) { return myAlloc.allocate(size); }
	static void operator delete(void* pdead, size_t size) { return myAlloc.deallocate(pdead, size); }
};

Allocator Foo::myAlloc;
#endif
