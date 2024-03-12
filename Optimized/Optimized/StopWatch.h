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
	// 모든 시간에 대한 데이터는 여기 담김
	vector<pair<std::string, __int64>>	m_vtSaveTimer{};	// 랩 타임 함수 저장소
	// 시간 측정에 필요한 데이터
	std::string							m_strFuncName{};	// "Function" 문자열
	chrono::system_clock::time_point	m_StartTime{};		// 랩 타임 (시작 시각)
	chrono::system_clock::time_point	m_EndTime{};		// 랩 타임 (멈춘 시각)
	bool								m_bActive{};		// 랩 타임 작동 여부

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