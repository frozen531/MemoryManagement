/*
* С���ڴ�ع�����v2,����embedded pointer
*/

#include "airplane.h"
#include <iostream>
using namespace std;

int main()
{
	cout << sizeof(Airplane) << endl;
	size_t const N = 100;
	Airplane* p[N];

	for (int i = 0; i < N; ++i)
		p[i] = new Airplane;

	// �����Ƿ�����
	p[1]->set(1000, 'A');
	p[5]->set(2000, 'B');
	p[9]->set(500000, 'C');

	// ���ǰ10�����鿴���
	for (int i = 0; i < 10; ++i)
		cout << p[i] << endl;

	for (int i = 0; i < N; ++i)
		delete p[i];

	system("pause");
	return 0;
}