#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_
#include <glm\glm.hpp>

enum eProjectileType
{
	PROJ_TYPE_TEST_BULLET,
	PROJ_TYPE_TEST_MORTAR,
};

class CBaseEntity;

class CProjectile
{
public:
	CProjectile();
	virtual ~CProjectile() = 0;

	virtual void OnImpact(CBaseEntity* a_target) = 0;

	eProjectileType GetProjectileType();
	const char*		GetName();
	glm::vec2 m_Position;
	glm::vec2 m_Velocity;
protected:
	const char* m_Name;
	eProjectileType m_Type;
	float m_Damage;
	float m_Speed;
	bool m_bDirect;
	CBaseEntity* m_Owner;
};



#endif