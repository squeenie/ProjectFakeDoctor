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

float CBaseEntity::GetWidth()
{
	return m_Width;
}

float CBaseEntity::GetHeight()
{
	return m_Height;
}

void CBaseEntity::SetWidth(float a_width)
{
	m_Width = a_width;
}

void CBaseEntity::SetHeight(float a_height)
{
	m_Height = a_height;
}

void CBaseEntity::SetWayPointTolerance(float a_tolerance)
{
	m_WayPointTolerance = a_tolerance;
}

void CBaseEntity::AddForce(glm::vec2 &a_force)
{
	m_Velocity += a_force;
}

void CBaseEntity::AddWayPoint(glm::vec2 a_waypoint)
{
	m_WayPoints.push_back(a_waypoint);
}

void CBaseEntity::SetCurrentWaypoint(glm::vec2 a_waypoint)
{
	if (m_WayPoints.size() < 1)
	{
		m_WayPoints.push_back(a_waypoint);
	}
	else
	{
		m_WayPoints.at(0) = a_waypoint;
	}
}

aie::Texture* CBaseEntity::GetTexturePtr()
{
	return m_Texture;
}

glm::vec2 CBaseEntity::GetCurrectWaypoint()
{
	if (m_WayPoints.size() > 0)
	{
		return m_WayPoints.at(0);
	}
	else
	{
		return glm::vec2(0);
	}
}

float CBaseEntity::GetCurrentSpeed()
{
	return m_CurrentSpeed;
}

float CBaseEntity::GetWayPointTolerance()
{
	return m_WayPointTolerance;
}

bool CBaseEntity::IsAlive()
{
	return m_bAlive;
}

bool CBaseEntity::ShouldUpdate()
{
	return m_bUpdate;
}
void CBaseEntity::SetCurrentSpeed(float a_speed)
{
	m_CurrentSpeed = a_speed;
}

void CBaseEntity::SetMaxSpeed(float &a_maxSpeed)
{
	m_MaxSpeed = a_maxSpeed;
}

void CBaseEntity::SetHealth(float &a_health)
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

