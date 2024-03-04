#include "StopWatch.h"



StopWatch::StopWatch()
{
}


StopWatch::~StopWatch()
{
}

std::string StopWatch::GetFuncName()
{
	return m_strFuncName;
}

double StopWatch::GetNanoTime()
{
	chrono::nanoseconds nano = m_EndTime - m_StartTime;
	double dTimeDist = nano.count();
	return dTimeDist;
}

double StopWatch::GetMicroTime()
{
	chrono::microseconds micro = chrono::duration_cast<chrono::microseconds>(m_EndTime - m_StartTime);
	double dTimeDist = micro.count();
	return dTimeDist;
}

double StopWatch::GetMilliTime()
{
	chrono::milliseconds mill = chrono::duration_cast<chrono::milliseconds>(m_EndTime - m_StartTime);
	double dTimeDist = mill.count();
	return dTimeDist;
}

void StopWatch::SetFuncName(std::string strName)
{
	m_strFuncName = strName;
}

void StopWatch::Start()
{
	m_StartTime = chrono::system_clock::now();
}

void StopWatch::End()
{
	m_EndTime = chrono::system_clock::now();
}
