#pragma once

#include <iostream>
#include <cstdio>
#include <ctime>

enum eTimerType
{
	COUNTDOWN,
	COUNTUP
};

class CTimer
{
public:
	CTimer();
	~CTimer();

	void Start(double duration);
	void Update();
	void Reset();

	bool m_bActive;
	bool m_bFinished;

	double m_StartTime;
	double m_CurrentTime;
	double m_PrevTime;
	double m_Duration;

	float m_PercentComplete;
private:
};