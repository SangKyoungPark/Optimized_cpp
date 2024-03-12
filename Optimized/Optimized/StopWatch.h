#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

typedef enum E_TIME_TYPE {
	_NANO_,
	_MICRO_,
	_Milli_
}TIME_TYPE;

class StopWatch
{
private:
	// ��� �ð��� ���� �����ʹ� ���� ���
	vector<pair<std::string, __int64>>	m_vtSaveTimer{};	// �� Ÿ�� �Լ� �����
	// �ð� ������ �ʿ��� ������
	std::string							m_strFuncName{};	// "Function" ���ڿ�
	chrono::system_clock::time_point	m_StartTime{};		// �� Ÿ�� (���� �ð�)
	chrono::system_clock::time_point	m_EndTime{};		// �� Ÿ�� (���� �ð�)
	bool								m_bActive{};		// �� Ÿ�� �۵� ����

public:
	StopWatch();
	~StopWatch();

	// Get
	pair<std::string, __int64> GetTimerRepo(int nIdx);
	std::string GetFuncName();
	std::string GetFuncName(int nIdx);
	
	__int64 GetNanoTime(); // nano
	__int64 GetMicroTime(); // micro
	__int64 GetMilliTime(); // ms
	__int64 GetTIme(E_TIME_TYPE eOption);

	// Set
	void SetFuncName(std::string strName);

	// Func
	void Start();
	void ReStart();
	void End(E_TIME_TYPE eOption);
};