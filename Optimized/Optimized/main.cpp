#include <iostream>
#include <windows.h>
#include "basic_stopwatch.h"

using namespace std;

basic_stopwatch<int> m_stopwatch{};

void main()
{	
	m_stopwatch.Start();

	bool nRet = m_stopwatch.IsStarted();
	cout << nRet << endl;

	m_stopwatch.Show();

	system("pause");
}