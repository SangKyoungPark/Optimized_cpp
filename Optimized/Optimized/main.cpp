#include <iostream>
#include <windows.h>
#include "StopWatch.h"

using namespace std;

StopWatch timer;

void main()
{
	timer.SetFuncName("main()");
	timer.Start();
	for (int i = 0; i < 100; i++);
	timer.End();

	cout << timer.GetNanoTime() << endl;
	cout << timer.GetMicroTime() << endl;
	cout << timer.GetMilliTime() << endl;

	system("pause");
}