#ifndef _CBASEBUILDING_H_
#define _CBASEBUILDING_H_

#include "glm\glm.hpp"

class CBaseBuilding
{
public:
	CBaseBuilding();
	virtual ~CBaseBuilding() = 0;

	glm::vec2		m_Position;
	
protected:
	
};


#endif