
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
	// 해당 함수는 1ms 해상도의 틱 카운트를 부호없는 32비트(4Byte) 정수로 변환함 
	DWORD dwStart = GetTickCount64();
	Do_Action();
	DWORD dwEnd = GetTickCount64();
	cout << "Startup Took " << dwEnd - dwStart << " ms" << endl;

	/* Windows 타이밍 함수 지연시간 [오름차순] : 시간이 짧을수록 틱이 빠름*/ 
	GetSystemTimeAsFileTime(NULL); // 2.8 나노초
	GetTickCount(); //3.8 나노초
	GetTickCount64(); // 6.7 나노초
	QueryPerformanceCounter(nullptr); // 8.0 나노초
	clock(); // 13 나노초
	time(nullptr); // 15 나노초
	timeGetTime(); // 17 나노초
	GetSystemTimePreciseAsFileTime(nullptr); // 22 나노초

	system("pause");
}