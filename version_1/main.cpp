/*
* С���ڴ�ؽ���
*/

#include"screen.h"

int main()
{
	cout << sizeof(Screen) << endl;

	size_t const N = 100;
	Screen* p[N];

	for (int i = 0; i < N; ++i)
		p[i] = new Screen(i);

	// ��ӡǰ10��ָ�룬�������룬Ӧ�������8(int+*)
	for (int i = 0; i < 10; ++i)
		cout << p[i] << endl;
	
	for (int i = 0; i < N; ++i)
		delete p[i];

	system("pause");
	return 0;
}