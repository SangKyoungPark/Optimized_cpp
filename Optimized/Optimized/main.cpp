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
	timer.End(E_TIME_TYPE::_NANO_);

	cout << "Func Name : " << timer.GetTimerRepo(0).first << endl;
	cout << "Tact Time : " << timer.GetTimerRepo(0).second << "seconds" << endl;

	system("pause");
}