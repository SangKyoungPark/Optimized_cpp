#include <iostream>
#include <windows.h>

using namespace std;

void main()
{	
	/* [ Program or Thread -> Start ] */
	// 프로세서의 우선순위 조작 (운영체제에 강제로 우선순위 높임)
	SetPriorityClass(GetCurrentProcess(), ABOVE_NORMAL_PRIORITY_CLASS);
	// Thread 우선순위 조작
	SetPriorityClass(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);

	/* [ Program or Thread -> END ] */
	// 프로세서의 우선순위 조작 (운영체제에 강제로 우선순위 되돌림)
	SetPriorityClass(GetCurrentProcess(), NORMAL_PRIORITY_CLASS);
	// Thread 우선순위 조작
	SetPriorityClass(GetCurrentThread(), THREAD_PRIORITY_NORMAL);

	system("pause");
}