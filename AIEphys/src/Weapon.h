#ifndef _WEAPON_H_
#define _WEAPON_H_

class CProjectile;
class CTimer;
class CBaseEntity;
class CAnimation;

namespace aie
{
	class Texture;
}

class CWeapon
{
public:
	CWeapon();
	CWeapon(const char* a_name);
	virtual ~CWeapon();

	virtual void	OnReload() = 0;
	virtual void	Fire(CBaseEntity* a_target) = 0;
	virtual void	Update(float &a_delta) = 0;

	void			SetParent(CBaseEntity* a_parent);
	void			SetMaxSpread(float a_maxSpread);
	void			SetCondition(float &a_condition);
	void			SetFlashSize(float a_width, float a_height);

	float			GetMaxSpread();
	float			GetCurrentSpread();
	CBaseEntity*	GetParent();
	unsigned int	GetCurrentAmmoCount();
	float			GetCondition();

	bool			ReadyToFire();
protected:
	bool			m_bIsFiring;
	unsigned int	m_CurrentAmmoCount;
	float			m_CurrentSpread;
	float			m_FlashWidth;
	float			m_FlashHeight;
	float			m_MaxSpread;
	float			m_Condition;
	float			m_BaseDamage;
	char*			m_Name;
	aie::Texture*	m_SpentShellTexture;
	CAnimation*		m_AnimMuzzle;
	CTimer*			m_CoolDownTimer;
	CBaseEntity*	m_Parent;
};


#endif