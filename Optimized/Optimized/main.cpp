
#include <iostream>
#include <windows.h>

using namespace std;

void main() 
{
	int nCnt = 10;
	DWORD avgTime = 0;
	for (int j = 0; j < nCnt; j++) {
		DWORD start = GetTickCount(); // �ش� �Լ��� 1ms �ػ��� ƽ ī��Ʈ�� ��ȣ���� 32��Ʈ(4Byte) ������ ��ȯ�� 
		for (int i = 0; i < 5000000; i++); 
		DWORD end = GetTickCount();
		cout << "Startup Took " << end - start << " ms" << endl;
		avgTime += (end - start);
	}
	avgTime /= nCnt;

	cout << "Startup Avg Time : " << avgTime << " ms" << endl;// 5�鸸 ���� ��� 3ms
	system("pause");
}