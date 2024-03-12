#include "StopWatch.h"



StopWatch::StopWatch()
{
}

StopWatch::~StopWatch()
{
}

pair<std::string, __int64> StopWatch::GetTimerRepo(int nIdx)
{
	int nSize = m_vtSaveTimer.size();

	pair<std::string, __int64> pairRet{};

	if (nSize == 0) {
		return pairRet;
	}
	else {
		if (nIdx <= nSize) {
			return m_vtSaveTimer.at(nIdx);
		}
		else {
			return pairRet;
		}
	}
}

std::string StopWatch::GetFuncName()
{
	return m_strFuncName;
}

__int64 StopWatch::GetNanoTime()
{
	chrono::nanoseconds nano = m_EndTime - m_StartTime;
	__int64 dTimeDist = nano.count();
	return dTimeDist;
}

__int64 StopWatch::GetMicroTime()
{
	chrono::microseconds micro = chrono::duration_cast<chrono::microseconds>(m_EndTime - m_StartTime);
	__int64 dTimeDist = micro.count();
	return dTimeDist;
}

__int64 StopWatch::GetMilliTime()
{
	chrono::milliseconds mill = chrono::duration_cast<chrono::milliseconds>(m_EndTime - m_StartTime);
	__int64 dTimeDist = mill.count();
	return dTimeDist;
}

__int64 StopWatch::GetTIme(E_TIME_TYPE eOption)
{
	__int64 nRetTime{};

	switch (eOption)
	{
	case E_TIME_TYPE::_NANO_:
		nRetTime = GetNanoTime();
		break;

	case E_TIME_TYPE::_MICRO_:
		nRetTime = GetMicroTime();
		break;

	case E_TIME_TYPE::_Milli_:
		nRetTime = GetMilliTime();
		break;

	default:
		nRetTime = GetMilliTime();
		break;
	}

	return nRetTime;
}

std::string StopWatch::GetFuncName(int nIdx)
{
	int nSize = m_vtSaveTimer.size();

	if (nSize == 0) {
		return nullptr;
	}
	else {
		if (nIdx <= nSize) {
			return m_vtSaveTimer.at(nIdx).first;
		}
		else {
			return nullptr;
		}
	}
}

void StopWatch::SetFuncName(std::string strName)
{
	m_strFuncName = strName;
}

void StopWatch::Start()
{
	if (m_bActive) {
		std::cout << "Already active timer" << endl;
	}
	else {
		m_StartTime= chrono::system_clock::now();
		m_bActive = true;
	}
}

void StopWatch::ReStart()
{
	if (m_bActive) {
		Start();
	}
	else {
		std::cout << "No Start Timer" << endl;
	}
}

void StopWatch::End(E_TIME_TYPE eOption)
{
	if (m_bActive) {
		m_EndTime = chrono::system_clock::now();
		
		__int64 nTactTime{};
		nTactTime = GetTIme(eOption);

		// Save Data
		std::string strFuncName{};
		strFuncName = GetFuncName();
		m_vtSaveTimer.push_back(make_pair(strFuncName, nTactTime));

		// init
		m_bActive = false;
	}
	else {
		std::cout << "No Start Timer" << endl;
	}
}


