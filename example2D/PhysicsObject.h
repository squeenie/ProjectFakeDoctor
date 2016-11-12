#ifndef _PHYSICSOBJECT_H_
#define _PHYSICSOBJECT_H_

namespace aie
{
	class Renderer2D;
}
namespace glm
{
	class vec2;
	class vec3;
}

class RigidBody;

enum eShapeType
{
	SHAPE_TYPE_CIRCLE,
	SHAPE_TYPE_PLANE,
	SHAPE_TYPE_BOX
};

class PhysicsObject
{
public:
	PhysicsObject();
	virtual ~PhysicsObject() = 0;

	virtual void Update();
	virtual void Debug() = 0;
	virtual void Draw(aie::Renderer2D*, float a_delta) = 0;
	virtual void ResetPosition();
	virtual void ApplyForce(glm::vec2 a_force);
	virtual void ApplyForceToActor(RigidBody *a_actor, glm::vec2 a_force);

	float GetGravity() const;
	float SetGravity(float &a_gravity);
	eShapeType GetObjectType();
	void SetObjectType(eShapeType a_shapeType);
protected:
	eShapeType m_ObjectType;
	float m_Gravity;
	float m_TimeStep;
private:
};

#endif
