#ifndef _PHYSSCENE_H_
#define _PHYSSCENE_H_

#include <vector>

class PhysicsObject;

class PhysScene
{
public:
	void AddActor(PhysicsObject* a_actor);
	void RemoveActor(PhysicsObject* a_actor);
	void GetActors() const;
	void Update();
	void DebugScene();
	void Draw();
	void SetGravity(float a_gravity);
	float GetGravity() const;
	void SetTimeStep(float a_timeStep);
	float GetTimeStep() const;
private:
	std::vector<PhysicsObject*> m_actors;
	float m_gravity;
	float m_timeStep;

};

#endif
