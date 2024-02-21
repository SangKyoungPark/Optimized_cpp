
#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

#define MAX_COUNT 100000

void Do_Action() 
{
	for (int i = 0; i < MAX_COUNT; i++);
}

void main()
{
	// �ش� �Լ��� 1ms �ػ��� ƽ ī��Ʈ�� ��ȣ���� 32��Ʈ(4Byte) ������ ��ȯ�� 
	DWORD dwStart = GetTickCount64();
	Do_Action();
	DWORD dwEnd = GetTickCount64();
	cout << "Startup Took " << dwEnd - dwStart << " ms" << endl;

	/* Windows Ÿ�̹� �Լ� �����ð� [��������] : �ð��� ª������ ƽ�� ����*/ 
	GetSystemTimeAsFileTime(NULL); // 2.8 ������
	GetTickCount(); //3.8 ������
	GetTickCount64(); // 6.7 ������
	QueryPerformanceCounter(nullptr); // 8.0 ������
	clock(); // 13 ������
	time(nullptr); // 15 ������
	timeGetTime(); // 17 ������
	GetSystemTimePreciseAsFileTime(nullptr); // 22 ������

	system("pause");
}