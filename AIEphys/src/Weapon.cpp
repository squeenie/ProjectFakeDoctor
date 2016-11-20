#include "Weapon.h"
#include "Timer.h"

CWeapon::CWeapon()
{
	m_CurrentAmmoCount = 0;
	m_Condition = 0;
	m_CurrentSpread = 0.0f;
	m_MaxSpread = 0.0f;
	m_AnimMuzzle = nullptr;
	m_Parent = nullptr;
	m_CoolDownTimer = nullptr;
	m_Name = nullptr;
}

CWeapon::CWeapon(const char* a_name)
{

	m_CurrentAmmoCount = 0;
	m_Condition = 0;
	m_CurrentSpread = 0.0f;
	m_MaxSpread = 0.0f;
	m_AnimMuzzle = nullptr;
	m_Parent = nullptr;
	m_CoolDownTimer = nullptr;
	m_Name = nullptr;
	if (a_name != nullptr)
	{
		m_Name = new char[strlen(a_name)];
		strcpy(m_Name, a_name);
	}
}

CWeapon::~CWeapon()
{
	if (m_AnimMuzzle != nullptr)
	{
		delete m_AnimMuzzle;
	}
	if (m_CoolDownTimer != nullptr)
	{
		delete m_CoolDownTimer;
	}
	if (m_Name != nullptr)
	{
		delete[] m_Name;
	}

}

void CWeapon::SetParent(CBaseEntity* a_parent)
{
	m_Parent = a_parent;
}

void CWeapon::SetMaxSpread(float a_maxSpread)
{
	m_MaxSpread = a_maxSpread;
}

void CWeapon::SetCondition(float &a_condition)
{
	m_Condition = a_condition;
}

void CWeapon::SetFlashSize(float a_width, float a_height)
{
	m_FlashWidth = a_width;
	m_FlashHeight = a_height;
}

float CWeapon::GetMaxSpread()
{
	return m_MaxSpread;
}

float CWeapon::GetCurrentSpread()
{
	return m_CurrentSpread;
}

CBaseEntity* CWeapon::GetParent()
{
	return m_Parent;
}

unsigned int CWeapon::GetCurrentAmmoCount()
{
	return m_CurrentAmmoCount;
}

float CWeapon::GetCondition()
{
	return m_Condition;
}

CAnimation* CWeapon::GetMuzzleAnimation()
{
	return m_AnimMuzzle;
}

bool CWeapon::ReadyToFire()
{
	if (m_CoolDownTimer != nullptr)
	{
		if (m_CoolDownTimer->m_bFinished && m_CurrentAmmoCount > 0)
		{
			return true;
		}
	}
	return false;
}
