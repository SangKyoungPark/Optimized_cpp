
#include <iostream>
#include <windows.h>

using namespace std;

void main() 
{
	int nCnt = 10;
	DWORD avgTime = 0;
	for (int j = 0; j < nCnt; j++) {
		DWORD start = GetTickCount(); // 해당 함수는 1ms 해상도의 틱 카운트를 부호없는 32비트(4Byte) 정수로 변환함 
		for (int i = 0; i < 5000000; i++); 
		DWORD end = GetTickCount();
		cout << "Startup Took " << end - start << " ms" << endl;
		avgTime += (end - start);
	}
	avgTime /= nCnt;

	cout << "Startup Avg Time : " << avgTime << " ms" << endl;// 5백만 기준 평균 3ms
	system("pause");
}