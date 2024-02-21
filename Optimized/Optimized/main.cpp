#include <iostream>
#include <windows.h>

using namespace std;

void main()
{	
	/* [ Program or Thread -> Start ] */
	// ���μ����� �켱���� ���� (�ü���� ������ �켱���� ����)
	SetPriorityClass(GetCurrentProcess(), ABOVE_NORMAL_PRIORITY_CLASS);
	// Thread �켱���� ����
	SetPriorityClass(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);

	/* [ Program or Thread -> END ] */
	// ���μ����� �켱���� ���� (�ü���� ������ �켱���� �ǵ���)
	SetPriorityClass(GetCurrentProcess(), NORMAL_PRIORITY_CLASS);
	// Thread �켱���� ����
	SetPriorityClass(GetCurrentThread(), THREAD_PRIORITY_NORMAL);

	system("pause");
}