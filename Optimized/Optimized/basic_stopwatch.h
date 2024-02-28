#pragma once

template <typename T> 
class basic_stopwatch{
	typedef typename T BaseTimer;

public:
	// 생성자. 활동(activity)의 시작 타이밍을 정함 (선택)
	explicit basic_stopwatch(bool bStart);
	explicit basic_stopwatch(char const* activity = "stopwatch", bool start = true);
	basic_stopwatch(std::ostream& log, char const* activity = "stopwatch", bool start = true);

	// 소멸자. 스톱워치 멈추고 파괴
	~basic_stopwatch();

	// 마지막 랩 타임(마지막 멈춘 시간) 을 얻음
	unsigned GetLap() const {
		return m_current_lap;
	}

	// 스톱워치 실행 여부 (실행중 : True )
	bool IsStarted() const {
		return true;
	}

	// 누적된 시간을 보여준다. ( 랩타임은 지속 )
	unsigned Show(char const* event = "show") {
		//m_log.write(event);
		return 1;
	}

	// 스톱워치를 (다시) 시작하고, 랩 타임을 설정/반환
	unsigned Start(char const* event_name = "start") {
		//m_log.write(event_name);
		return 1;
	}

	// 실행 중인 스톱워치를 멈추고, 랩 타임을 설정/반환
	unsigned Stop(char const* event_name = "stop") {
		m_lap = GetLap();
		//m_log.write(event_name);
		return 1;
	}

private:
	char const*		m_activity{}; // "활동" 문자열
	unsigned		m_current_lap{}; // 랩 타임 (현재 돌고 있는 시각)
	unsigned		m_last_lap{}; // 랩 타임 (마지막으로 멈춘 시각)
	std::ostream&	m_log{}; // 이벤트를 기록할 스트림
};