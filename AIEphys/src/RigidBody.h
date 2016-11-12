#ifndef _RIGIDBODY_H_
#define _RIGIDBODY_H_

#include "PhysicsObject.h"
class PhysicsObject;


class RigidBody : public PhysicsObject
{
public:
	RigidBody();
	RigidBody(glm::vec2 a_position, glm::vec2 a_velocity, float a_rotation, float a_mass, unsigned int a_id);

	//General
	virtual void	Update(float a_delta);
	virtual void	Debug();
	void			ApplyForce(glm::vec2 a_force) override;
	void			ApplyForceToActor(PhysicsObject *a_actor, glm::vec2 a_force) override;
	
	//Gets'n'Sets
	void			SetPosition(glm::vec2 &a_position);
	void			SetVelocity(glm::vec2 &a_velocity);
	void			SetMass(float a_mass);
	void			SetRotation2D(float &a_rotation);

	glm::vec2		GetVelocity() const;
	float			GetMass() override ;
	float			GetRotation2D();
	glm::vec2		GetPosition() override;
	glm::vec2		GetMomentum();

protected:
	glm::vec2 m_Position;
	glm::vec2 m_Velocity;
	glm::vec2 m_Acceleration;
	glm::vec2 m_Momentum;
	float m_Mass;
	float m_Rotation2D;

};


#endif
