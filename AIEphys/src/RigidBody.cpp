#include "RigidBody.h"
#include <iostream>
RigidBody::RigidBody()
{
	m_Position = glm::vec2(0);
	m_Velocity = glm::vec2(0);
	m_Rotation2D = 0.0f;
	m_Mass = 0.0f;
	m_ObjectType = SHAPE_UNDEFINED;
}
RigidBody::RigidBody(glm::vec2 a_position, glm::vec2 a_velocity, float a_rotation, float a_mass, unsigned int a_id)
{
	m_Position = a_position;
	m_Velocity = a_velocity;
	m_Rotation2D = a_rotation;
	m_Mass = a_mass;
}

void RigidBody::Update(float a_delta)
{
	//glm::vec2 grav = (glm::vec2(0, 1) * m_Gravity) * a_delta;
	//m_Velocity += grav;
	m_Position += (m_Velocity * a_delta);
	m_Momentum = m_Velocity * m_Mass;

}

void RigidBody::Debug()
{

}

void RigidBody::ApplyForce(glm::vec2 a_force)
{
	m_Velocity += a_force;
}

void RigidBody::ApplyForceToActor(PhysicsObject *a_actor, glm::vec2 a_force)
{
	//std::cout << "TODO: RigidBody::ApplyForceToActor(RigidBody *a_actor, glm::vec2 a_force)" << std::endl;
	a_actor->ApplyForce(a_force / a_actor->GetMass());
	ApplyForce(-a_force / GetMass());
}

void RigidBody::SetPosition(glm::vec2 &a_position)
{
	m_Position = a_position;
}

void RigidBody::SetVelocity(glm::vec2 &a_velocity)
{
	m_Velocity = a_velocity;
}

void RigidBody::SetMass(float a_mass)
{
	m_Mass = a_mass;
}

void RigidBody::SetRotation2D(float &a_rotation)
{
	m_Rotation2D = a_rotation;
}

glm::vec2 RigidBody::GetVelocity() const
{
	return m_Velocity;
}

glm::vec2 RigidBody::GetPosition()
{
	return m_Position;
}

float RigidBody::GetMass()
{
	return m_Mass;
}


glm::vec2 RigidBody::GetMomentum()
{
	return m_Momentum;
}


float RigidBody::GetRotation2D()
{
	return m_Rotation2D;
}
