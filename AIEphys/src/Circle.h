#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "RigidBody.h"

class CircleBody : public RigidBody
{
public:
	CircleBody(glm::vec2 &a_position, glm::vec2 &a_velocity, float &a_mass, float &a_radius, glm::vec4 a_colour);
	void Draw(aie::Renderer2D*) override;
	glm::vec2 GetDimensions();
	
	//Gets'n'Sets
	void SetRadius(float a_Radius);

	float GetRadius();
protected:
	float m_Radius;
};



#endif // !_CIRCLE_H_

