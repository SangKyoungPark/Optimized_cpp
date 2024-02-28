#pragma once

template <typename T> 
class basic_stopwatch{
	typedef typename T BaseTimer;

public:
	// ������. Ȱ��(activity)�� ���� Ÿ�̹��� ���� (����)
	explicit basic_stopwatch(bool bStart);
	explicit basic_stopwatch(char const* activity = "stopwatch", bool start = true);
	basic_stopwatch(std::ostream& log, char const* activity = "stopwatch", bool start = true);

	// �Ҹ���. �����ġ ���߰� �ı�
	~basic_stopwatch();

	// ������ �� Ÿ��(������ ���� �ð�) �� ����
	unsigned GetLap() const {
		return m_current_lap;
	}

	// �����ġ ���� ���� (������ : True )
	bool IsStarted() const {
		return true;
	}

	// ������ �ð��� �����ش�. ( ��Ÿ���� ���� )
	unsigned Show(char const* event = "show") {
		//m_log.write(event);
		return 1;
	}

	// �����ġ�� (�ٽ�) �����ϰ�, �� Ÿ���� ����/��ȯ
	unsigned Start(char const* event_name = "start") {
		//m_log.write(event_name);
		return 1;
	}

	// ���� ���� �����ġ�� ���߰�, �� Ÿ���� ����/��ȯ
	unsigned Stop(char const* event_name = "stop") {
		m_lap = GetLap();
		//m_log.write(event_name);
		return 1;
	}

private:
	char const*		m_activity{}; // "Ȱ��" ���ڿ�
	unsigned		m_current_lap{}; // �� Ÿ�� (���� ���� �ִ� �ð�)
	unsigned		m_last_lap{}; // �� Ÿ�� (���������� ���� �ð�)
	std::ostream&	m_log{}; // �̺�Ʈ�� ����� ��Ʈ��
};