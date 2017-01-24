#ifndef _CSQUARE_H_
#define _CSQUARE_H_

#include "glm\glm.hpp"

class CSquare
{
public:
	CSquare();
	~CSquare();

	void		SetDimensions(float width, float height);

	glm::vec2	GetDimensions();

	glm::vec2	m_Position;
	float		m_Rotation;
protected:
	glm::vec2	m_Dimensions;

};


#endif