#ifndef _FORCE_H_
#define _FORCE_H_

#include "glm\glm.hpp"
#include "Timer.h"

class CTimer;

enum FORCE_TYPE
{
	FORCE_TYPE_CONTINUOUS,
	FORCE_TYPE_SINGLE_FRAME,
	FORCE_TYPE_FADE
};

class Force
{
public:
	Force();
	~Force();

	void SetForce(glm::vec2 a_force);
	glm::vec2 GetForce();
private:
	glm::vec2 m_Force;
	float m_ForceDuration;
	CTimer m_Timer;
};

#endif
