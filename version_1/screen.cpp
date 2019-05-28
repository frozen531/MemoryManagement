#include "screen.h"

Screen* Screen::freeStore = nullptr; // ָ����пռ���׵�ֵ���൱�ڵ���������׵�ֵ
const int Screen::screenChunk = 24; // һ��������ٸ�Screen��С�Ŀռ�

void* Screen::operator new(size_t size)
{
	Screen* p;

	// ���freeStore�ǿյģ������ڴ�����һ����ڴ�
	if (!freeStore)
	{
		size_t chunk = screenChunk * size; // Ҫ������ڴ��С
		freeStore = p = reinterpret_cast<Screen*>(new char[chunk]); // �൱�ڵ���malloc����chunk��char����,freeStore�ǿ��пռ���׵�ֵ

		// �ָ��ڴ��һƬƬ��������������p��Screenָ��
		for (; p != &freeStore[screenChunk - 1]; ++p)
			p->next = p + 1; // Screen��ָ�봮��
		p->next = nullptr; // ĩ��Ԫ�ص�ָ���ÿ�
	}

	// ���freeStore��Ϊ�գ�freeStore��Ӧ�ĸ�ֵ��p��freeStore����
	p = freeStore;
	freeStore = freeStore->next;
	return p;
}

// �����delete��û��free�ڴ棬ֻ�ǽ��ڴ�����·����ڴ���У��ƶ���ָ�뼴��
void Screen::operator delete(void* p, size_t)
{
	(static_cast<Screen*>(p))->next = freeStore; // ɾ�����ڴ���뵥�������ײ�
	freeStore = static_cast<Screen*>(p); // freeStore��ǰ�ƶ����ص������������ײ�
}
