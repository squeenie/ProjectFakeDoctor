#include "BaseEntity.h"

CBaseEntity::CBaseEntity()
{

}

CBaseEntity::~CBaseEntity()
{

}

float CBaseEntity::GetHealth()
{
	return m_CurrentHP;
}

float CBaseEntity::GetMaxHealth()
{
	return m_MaxHP;
}

float CBaseEntity::GetMaxSpeed()
{
	return m_MaxSpeed;
}

float CBaseEntity::GetRotation()
{
	return m_Rotation;
}

aie::Texture* CBaseEntity::GetTexturePtr()
{
	return m_Texture;
}

void CBaseEntity::SetMaxSpeed(float &a_maxSpeed)
{
	m_MaxSpeed = a_maxSpeed;
}

void CBaseEntity::Sethealth(float &a_health)
{
	m_CurrentHP = a_health;
}

void CBaseEntity::SetMaxHealth(float &a_maxHealth)
{
	m_MaxHP = a_maxHealth;
}

void CBaseEntity::SetRotation(float &a_rotation)
{
	m_Rotation = a_rotation;
}

