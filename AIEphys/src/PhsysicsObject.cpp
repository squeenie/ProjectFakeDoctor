#include "PhysicsObject.h"

PhysicsObject::PhysicsObject()
{
	m_Gravity = 0.0f;
	m_TimeStep = 0.0f;
	m_ObjectType = SHAPE_UNDEFINED;
}

PhysicsObject::~PhysicsObject()
{

}

void PhysicsObject::Update(float a_delta)
{

}

void PhysicsObject::Debug()
{

}


void PhysicsObject::ResetPosition()
{

}



float PhysicsObject::GetGravity() const
{
	return m_Gravity;
}



void PhysicsObject::SetGravity(float &a_gravity)
{
	m_Gravity = a_gravity;
}

eShapeType PhysicsObject::GetObjectType()
{
	return m_ObjectType;
}

void PhysicsObject::SetObjectType(eShapeType a_shapeType)
{
	m_ObjectType = a_shapeType;
}

void PhysicsObject::SetObjectID(unsigned int &a_id)
{
	m_ID = a_id;
}

unsigned int PhysicsObject::GetID()
{
	return m_ID;
}
