/*
* 小型内存池建立
*/

#include"screen.h"

int main()
{
	cout << sizeof(Screen) << endl;

	size_t const N = 100;
	Screen* p[N];

	for (int i = 0; i < N; ++i)
		p[i] = new Screen(i);

	// 打印前10个指针，看相差距离，应该是相差8(int+*)
	for (int i = 0; i < 10; ++i)
		cout << p[i] << endl;
	
	for (int i = 0; i < N; ++i)
		delete p[i];

	system("pause");
	return 0;
}