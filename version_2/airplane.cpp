#include "airplane.h"

Airplane* Airplane::headOfFreeList = nullptr;
const int Airplane::BLOCK_SIZE = 512;

void* Airplane::operator new(size_t size)
{
	// �жϴ���Ĵ�С�Ƿ���Airplane��ʵ��Сһ�£�����һ�£�����::operator new()
	// ���̳з���ʱ�ͻ���ֲ�һ������
	if (size != sizeof(Airplane)) 
		return ::operator new(size);

	Airplane* p = headOfFreeList;
	if (p) // ���p��Ч���Ͱ�list����һ��Ԫ��
		headOfFreeList = p->next;
	else
	{
		// ����һ����ڴ�
		Airplane* newBlock = static_cast<Airplane*>(::operator new(BLOCK_SIZE * sizeof(Airplane)));

		// �ڴ��䴮��ָ��
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

	// �ж�Ҫ���յ��ڴ��С�Ƿ���ȷ
	if (size != sizeof(Airplane)) { 
		::operator delete(deadObject);
		return;
	}

	// ���յ�ָ����뵥�������ͷ
	Airplane* carcess = static_cast<Airplane*>(deadObject);

	carcess->next = headOfFreeList;
	headOfFreeList = carcess;
}
