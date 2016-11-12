#include "Circle.h"
#include "Renderer2D.h"

CircleBody::CircleBody(glm::vec2 &a_position, glm::vec2 &a_velocity, float &a_mass, float &a_radius, glm::vec4 a_colour)
{
	m_Position = a_position;
	m_Velocity = a_velocity;
	m_Mass = a_mass;
	m_Radius = a_radius;
	m_ObjectType = SHAPE_TYPE_CIRCLE;
}

void CircleBody::Draw(aie::Renderer2D* a_renderer)
{
	a_renderer->drawCircle(m_Position.x, m_Position.y, m_Radius);
}

glm::vec2 CircleBody::GetDimensions()
{
	return glm::vec2(m_Radius, m_Radius);
}

void CircleBody::SetRadius(float a_Radius)
{
	m_Radius = a_Radius;
}

float CircleBody::GetRadius()
{
	return m_Radius;
}