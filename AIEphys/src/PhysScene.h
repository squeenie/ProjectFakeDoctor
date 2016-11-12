#ifndef _PHYSSCENE_H_
#define _PHYSSCENE_H_

#include <vector>
#include "glm\glm.hpp"

class PhysicsObject;
namespace aie
{
	class Renderer2D;
}


typedef std::vector<glm::vec2> CollisionList;
typedef std::vector<PhysicsObject*> ActorList;

class PhysScene
{
public:
	PhysScene(float a_gravity, float a_timestep);
	~PhysScene();

	void				AddActor(PhysicsObject* a_actor);
	void				RemoveActor(PhysicsObject* a_actor);
	void				DeleteAllActors();
	ActorList			GetActors() const;
	unsigned int		GetNumberOfActors();
	void				Update(float a_delta);
	void				DebugScene();
	void				Draw(aie::Renderer2D *a_renderer, float a_delta);
	void				SetSceneGravity(float a_gravity);
	bool				CheckCollision(PhysicsObject *a_actor1, PhysicsObject *a_actor2, float a_delta);
	float				GetSceneGravity() const;
	void				SetTimeStep(float a_timeStep);
	float				GetTimeStep() const;
	glm::vec2			GetCollisionPoint(PhysicsObject *a_actor1, PhysicsObject *a_actor2);
	CollisionList		GetCollisionList();
	void				ClearCollisionList();
private:
	ActorList			m_Actors;
	float				m_Gravity;
	float				m_TimeStep;
	unsigned int		m_ActorCount;
	CollisionList		m_CollisionList;
};

#endif
