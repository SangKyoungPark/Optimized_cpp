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
	std::string									m_strFuncName{};	// "Function" πÆ¿⁄ø≠
	chrono::system_clock::time_point			m_StartTime{};		// ∑¶ ≈∏¿” (Ω√¿€ Ω√∞¢)
	chrono::system_clock::time_point			m_EndTime{};		// ∑¶ ≈∏¿” (∏ÿ√· Ω√∞¢)
	double										m_ActiveTime{};	// ∑¶ ≈∏¿” (∏ÿ√· Ω√∞¢ - Ω√¿€ Ω√∞¢)

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