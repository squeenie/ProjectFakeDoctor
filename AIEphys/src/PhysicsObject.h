#ifndef _PHYSICSOBJECT_H_
#define _PHYSICSOBJECT_H_

#include "glm\glm.hpp"

namespace aie
{
	class Renderer2D;
}


class RigidBody;

enum eShapeType
{
	SHAPE_TYPE_CIRCLE,
	SHAPE_TYPE_PLANE,
	SHAPE_TYPE_BOX,
	SHAPE_UNDEFINED
};

class PhysicsObject
{
public:
	PhysicsObject();
	virtual ~PhysicsObject() = 0;

	virtual void		Update(float a_delta);
	virtual void		Debug() = 0;
	virtual void		Draw(aie::Renderer2D*) = 0;
	virtual void		ResetPosition();
	virtual void		ApplyForce(glm::vec2 a_force) = 0;
	virtual void		ApplyForceToActor(PhysicsObject *a_actor, glm::vec2 a_force) = 0;
	virtual glm::vec2	GetMomentum() = 0;
	virtual glm::vec2	GetPosition() = 0;
	virtual glm::vec2	GetDimensions() = 0;
	virtual float		GetMass() = 0;

	float				GetGravity() const;
	
	void				SetGravity(float &a_gravity);
	eShapeType			GetObjectType();
	void				SetObjectType(eShapeType a_shapeType);
	void				SetObjectID(unsigned int &a_id);
	unsigned int		GetID();
protected:
	eShapeType m_ObjectType;
	float m_Gravity;
	float m_TimeStep;
	unsigned int m_ID;
private:
};



#endif
