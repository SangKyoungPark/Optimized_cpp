#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

class StopWatch
{
private:
	std::string									m_strFuncName{};	// "Function" ���ڿ�
	chrono::system_clock::time_point			m_StartTime{};		// �� Ÿ�� (���� �ð�)
	chrono::system_clock::time_point			m_EndTime{};		// �� Ÿ�� (���� �ð�)
	double										m_ActiveTime{};	// �� Ÿ�� (���� �ð� - ���� �ð�)

public:
	StopWatch();
	~StopWatch();

	// Get
	std::string GetFuncName();
	double GetNanoTime(); // nano
	double GetMicroTime(); // micro
	double GetMilliTime(); // ms
	
	// Set
	void SetFuncName(std::string strName);

	// Func
	void Start();
	void End();
};