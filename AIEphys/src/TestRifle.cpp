#include "TestRifle.h"
#include "Timer.h"
#include "Animation.h"


CTestRifle::CTestRifle()
{
	m_CurrentAmmoCount = 8;
	m_Condition = 1.0;
	m_CurrentSpread = 30.0f;
	m_MaxSpread = 200.0f;
	m_AnimMuzzle = new CAnimation("./Images/Effects/Muzzle_Stock.png", 3, 3, 1, 24.0f, 32, 32);
	m_AnimMuzzle->SetLoop(false);
	m_Parent = nullptr;
	m_Name = new char[strlen("Wep_Test_rifle")];
	strcpy(m_Name, "Wep_Test_rifle");
	
	m_CoolDownTimer = new CTimer();
	
}
CTestRifle::CTestRifle(const char* a_name)
{
	m_CurrentAmmoCount = 8;
	m_Condition = 1.0;
	m_CurrentSpread = 30.0f;
	m_MaxSpread = 200.0f;
	m_AnimMuzzle = new CAnimation("./Images/Effects/Muzzle_Stock.png", 3, 3, 1, 24.0f, 32, 32);
	m_AnimMuzzle->SetLoop(false);
	m_Parent = nullptr;
	m_CoolDownTimer = nullptr;
	m_Name = nullptr;
	if (a_name != nullptr)
	{
		m_Name = new char[strlen(a_name)];
		strcpy(m_Name, a_name);
	}
}

CTestRifle::~CTestRifle()
{

}

void CTestRifle::Fire(CBaseEntity* a_target)
{
	//Create projectile
	//Start case ejection
	//Update ammo count
	//Play sound
}

void CTestRifle::OnReload()
{

}

void CTestRifle::Update(float &a_delta)
{
	m_CoolDownTimer->Update();
	
}
