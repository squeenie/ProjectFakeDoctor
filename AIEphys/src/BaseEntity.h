#ifndef _BASEENTITY_H_
#define _BASEENTITY_H_

#include "glm\glm.hpp"
#include <vector>

class CItem;

namespace aie
{
	class Texture;
	class Renderer2D;
}

class CBaseEntity
{
public:
	CBaseEntity();
	~CBaseEntity();

	virtual void		Update(float &a_delta) = 0;
	virtual void		Draw(aie::Renderer2D* a_renderer, float &a_delta) = 0;
	virtual void		Move(float &a_delta) = 0;
	virtual void		Attack() = 0;

	float				GetHealth();
	float				GetMaxHealth();
	float				GetMaxSpeed();
	float				GetRotation();
	aie::Texture*		GetTexturePtr();

	void				SetMaxSpeed(float &a_maxSpeed);
	void				Sethealth(float &a_health);
	void				SetMaxHealth(float &a_maxHealth);
	void				SetRotation(float &a_rotation);

	glm::vec2			m_Position;
	glm::vec2			m_Velocity;

protected:
	float				m_CurrentHP;
	float				m_MaxHP;
	float				m_CurrentSpeed;
	float				m_MaxSpeed;
	float				m_Rotation;
	aie::Texture*		m_Texture;
	std::vector<CItem*> m_Inventory;
};



#endif
