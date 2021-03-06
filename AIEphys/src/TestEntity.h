#ifndef _TESTENTITY_H_
#define _TESTENTITY_H_

#include "BaseEntity.h"

class CTimer;
class CAnimation;
class Weapon;
class TestEntity : public CBaseEntity
{
public:
	TestEntity();
	~TestEntity();

	void		Update(float &a_delta) override;
	void		Draw(aie::Renderer2D* a_renderer/*, float &a_delta*/) override;
	void		Move(float &a_delta) override;
	void		Attack(float &a_delta) override;
	void		Spawn(glm::vec2 &a_spawnPoint) override;
	void		Init(const char* a_texturePath, glm::vec2 a_position, glm::vec2 a_velocity, float a_rotation, float a_width, float a_height, unsigned int a_newID) override;
	void		Seek(glm::vec2 &a_target, float &a_delta) override;
	void		Flee(glm::vec2 &a_target, float &a_delta) override;
	void		Reload(float &a_delta) override;

	void		DrawHealth(aie::Renderer2D* a_renderer);
	void		DrawMuzzle(aie::Renderer2D* a_renderer);

private:
	CTimer*		m_CooldownTimer;
	CAnimation*	m_CurrentAnimation;
	CAnimation*	m_RunAnim;
	CAnimation*	m_DieAnim;
	CAnimation*	m_IdleAnim;
	CAnimation*	m_WalkAnim;
	//Weapon*		m_PrimaryWeapon;
	//Weapon*		m_SecondaryWeapon;
};




#endif