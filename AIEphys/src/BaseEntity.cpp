#include "BaseEntity.h"
#include <iostream>

CBaseEntity::CBaseEntity()
{
	m_CurrentHP = 0;
	m_CurrentSpeed = 0;
	m_MaxHP = 0;
	m_MaxSpeed = 0;
	m_Rotation = 0;
	m_bAlive = false;
	m_bUpdate = false;
	m_State = STATE_UNINITIALIZED;
	m_EntityType = ENTITY_TYPE_UNDEFINED;
	m_ExhaustionLevel = 0;
	m_SuppressionLevel = 0;
	m_MoraleLevel = 0;
	m_Texture = nullptr;
	m_uiEntityID = 0;
	m_Velocity = glm::vec2(0);
	m_WayPointTolerance = 0;
	m_Width = 0;
	m_Height = 0;
	m_Position = glm::vec2(0);
	m_Accuracy = 0;
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

float CBaseEntity::GetAccuracy()
{
	return m_Accuracy;
}

float CBaseEntity::GetSuppressionLevel()
{
	return m_SuppressionLevel;
}

float CBaseEntity::GetExhaustionLevel()
{
	return m_ExhaustionLevel;
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

void CBaseEntity::AddAuxiliaryWeapon(CWeapon* a_weapon)
{
	m_AuxiliaryWeapons.push_back(a_weapon);
}

void CBaseEntity::RemoveAuxiliaryWeapon(int a_index)
{
	if (a_index < m_AuxiliaryWeapons.size() && a_index > 0)
	{
		delete m_AuxiliaryWeapons.at(a_index);
		m_AuxiliaryWeapons.erase(m_AuxiliaryWeapons.begin() + a_index);
	}
}

void CBaseEntity::RemoveAuxiliaryWeapon(CWeapon* a_weapon)
{
	for (int i = 0; i < m_AuxiliaryWeapons.size(); ++i)
	{
		if (m_AuxiliaryWeapons.at(i) == a_weapon)
		{
			RemoveAuxiliaryWeapon(i);
		}
	}
}

void CBaseEntity::GenerateRandomStats()
{
	std::cout << "TODO: Entity::GenerateRandomStats()" << std::endl;
}

aie::Texture* CBaseEntity::GetTexturePtr()
{
	return m_Texture;
}

CWeapon* CBaseEntity::GetMainWeapon()
{
	return m_MainWeapon;
}

std::vector<CWeapon*> CBaseEntity::GetAllWeapons()
{
	std::vector<CWeapon*> wepList;
	wepList.push_back(m_MainWeapon);
	for (int i = 0; i < m_AuxiliaryWeapons.size(); ++i)
	{
		wepList.push_back(m_AuxiliaryWeapons.at(i));
	}
	return wepList;
}

std::vector<CWeapon*> CBaseEntity::GetAuxillaryWeapons()
{
	return m_AuxiliaryWeapons;
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

eEntityType CBaseEntity::GetEntityType()
{
	return m_EntityType;
}

unsigned int CBaseEntity::GetEntityID()
{
	return m_uiEntityID;
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

void CBaseEntity::SetMainWeapon(CWeapon* a_weapon)
{
	m_MainWeapon = a_weapon;
}

void CBaseEntity::SetAuxiliaryWeaponList(std::vector<CWeapon*> a_weaponList)
{
	for (int i = 0; i < m_AuxiliaryWeapons.size(); ++i)
	{
		delete m_AuxiliaryWeapons.at(i);
	}
	m_AuxiliaryWeapons.clear();
	m_AuxiliaryWeapons = a_weaponList;
}

float CBaseEntity::DegToRad(float a_degrees)
{
	return (a_degrees + 90.0f) * 0.0174533;
}

float CBaseEntity::RadToDeg(float a_rad)
{
	return (a_rad * 57.2958) + 90.0f;
}

float CBaseEntity::VectorToAngle(glm::vec2 &a_vec)
{
	return atan2(a_vec.x, a_vec.y);
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

