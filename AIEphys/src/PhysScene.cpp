#include "PhysScene.h"
#include "PhysicsObject.h"
#include <iostream>

PhysScene::PhysScene(float a_gravity, float a_timestep)
{
	m_ActorCount = 0;
	m_Gravity = a_gravity;
	m_TimeStep = a_timestep;
}

PhysScene::~PhysScene()
{
	//Delete actors
	/*for (int i = 0; i < m_Actors.size(); ++i)
	{
		delete m_Actors.at(i);
		m_Actors.erase(m_Actors.begin() + i);
	}*/
}

void PhysScene::AddActor(PhysicsObject* a_actor)
{
	m_ActorCount++;
	a_actor->SetObjectID(m_ActorCount);
	a_actor->SetGravity(m_Gravity);
	m_Actors.push_back(a_actor);
}

void PhysScene::RemoveActor(PhysicsObject* a_actor)
{
	for (int i = 0; i < m_Actors.size(); ++i)
	{
		if (m_Actors.at(i) == a_actor)
		{
			delete a_actor;
			m_Actors.erase(m_Actors.begin() + i);
			return;
		}
	}
}

void PhysScene::DeleteAllActors()
{
	for (int i = 0; i < m_Actors.size(); ++i)
	{
		delete m_Actors.at(i);
		m_Actors.erase(m_Actors.begin() + i);
	}
}

ActorList PhysScene::GetActors() const
{
	return m_Actors;
}

unsigned int PhysScene::GetNumberOfActors()
{
	return m_Actors.size();
}

void PhysScene::Update(float a_delta)
{
	//Update
	for (int i = 0; i < m_Actors.size(); ++i)
	{
		m_Actors.at(i)->Update(a_delta);
	}
	//Check collision
	for (int i = 0; i < m_Actors.size(); ++i)
	{
		for (int j = 0; j < m_Actors.size(); ++j)
		{
			if (i == j)
			{
				continue;
			}
			if (CheckCollision(m_Actors.at(i), m_Actors.at(j), a_delta))
			{
				//std::cout << "Collision detected" << std::endl;
				m_CollisionList.push_back(GetCollisionPoint(m_Actors.at(i), m_Actors.at(j)));
			}
		}
	}
}

void PhysScene::DebugScene()
{

}

void PhysScene::Draw(aie::Renderer2D *a_renderer, float a_delta)
{
	for (int i = 0; i < m_Actors.size(); ++i)
	{
		m_Actors.at(i)->Draw(a_renderer);
	}
}

void PhysScene::SetSceneGravity(float a_gravity)
{
	m_Gravity = a_gravity;
	for (int i = 0; i < m_Actors.size(); ++i)
	{
		m_Actors.at(i)->SetGravity(m_Gravity);
	}
}

bool PhysScene::CheckCollision(PhysicsObject * a_actor1, PhysicsObject * a_actor2, float a_delta)
{
	//Circle on circle collision
	if (a_actor1->GetObjectType() == SHAPE_TYPE_CIRCLE && a_actor2->GetObjectType() == SHAPE_TYPE_CIRCLE)
	{
		float radius_sum = a_actor1->GetDimensions().x + a_actor2->GetDimensions().x;
		glm::vec2 p1 = a_actor1->GetPosition();
		glm::vec2 p2 = a_actor2->GetPosition();
		float distance = glm::distance(p1, p2);
		if (distance < radius_sum)
		{
			a_actor1->ApplyForceToActor(a_actor2, a_actor1->GetMomentum());
			return true;
		}
	}
	return false;
}

float PhysScene::GetSceneGravity() const
{
	return m_Gravity;
}

void PhysScene::SetTimeStep(float a_timeStep)
{
	m_TimeStep = a_timeStep;
}

float PhysScene::GetTimeStep() const
{
	return m_TimeStep;
}

glm::vec2 PhysScene::GetCollisionPoint(PhysicsObject * a_actor1, PhysicsObject * a_actor2)
{

	/*
	collisionPointX = 
 ((firstBall.x * secondBall.radius) + (secondBall.x * firstBall.radius)) 
 / (firstBall.radius + secondBall.radius);
 
collisionPointY = 
 ((firstBall.y * secondBall.radius) + (secondBall.y * firstBall.radius)) 
 / (firstBall.radius + secondBall.radius);
	*/
	if (a_actor1->GetObjectType() == SHAPE_TYPE_CIRCLE && a_actor2->GetObjectType() == SHAPE_TYPE_CIRCLE)
	{
		glm::vec2 Collision;
		Collision.x = ((a_actor1->GetPosition().x * a_actor2->GetDimensions().x) + (a_actor2->GetPosition().x * a_actor1->GetDimensions().x)) /
			(a_actor1->GetDimensions().x + a_actor2->GetDimensions().x);
		Collision.y = ((a_actor1->GetPosition().y * a_actor2->GetDimensions().y) + (a_actor2->GetPosition().y * a_actor1->GetDimensions().y)) /
			(a_actor1->GetDimensions().y + a_actor2->GetDimensions().y);
		return Collision;
	}
	else
	{
		return glm::vec2(0, 0);
	}
}

CollisionList PhysScene::GetCollisionList()
{
	return m_CollisionList;
}
void PhysScene::ClearCollisionList()
{
	m_CollisionList.clear();
}
