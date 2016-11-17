#include "Timer.h"

CTimer::CTimer()
{
	Reset();
}

CTimer::~CTimer()
{

}

void CTimer::Start(double duration)
{
	m_bActive = true;
	m_StartTime = clock();
	m_Duration = duration;
}

void CTimer::Update()
{
	if (m_bActive)
	{
		m_PercentComplete = (std::clock() - m_StartTime) / (m_Duration * CLOCKS_PER_SEC);
		if ((m_Duration * CLOCKS_PER_SEC) < std::clock() - m_StartTime)
		{
			//std::cout << "DING DING DING DING DING DING DING" << std::endl;
			m_PercentComplete = 1.0;
			m_bFinished = true;
		}
	}
}

void CTimer::Reset()
{
	m_CurrentTime = 0;
	m_PrevTime = 0;
	m_Duration = 0;
	m_StartTime = 0;
	m_bActive = false;
	m_bFinished = false;
}

void CTimer::Restart()
{
	m_bActive = true;
	m_StartTime = clock();
}
