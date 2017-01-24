#ifndef _BASEENTITY_H_
#define _BASEENTITY_H_

#include "glm\glm.hpp"
#include <vector>
#include "EntityTypes.h"

class CItem;
class CWeapon;
class CTimer;
enum eENTITY_STATE
{
	STATE_UNINITIALIZED,
	STATE_IDLE,
	STATE_WALK,
	STATE_DEAD,
	STATE_RUN,
	STATE_ATTACK,
	STATE_AIM,
	STATE_RELOAD
};



namespace aie
{
	class Texture;
	class Renderer2D;
}

class CBaseEntity
{
public:
	CBaseEntity();
	virtual ~CBaseEntity() = 0;

	virtual void				Update(float &a_delta) = 0;
	virtual void				Draw(aie::Renderer2D* a_renderer/*, float &a_delta*/) = 0;
	virtual void				Move(float &a_delta) = 0;
	virtual void				Attack(float &a_delta) = 0;
	virtual void				Spawn(glm::vec2 &a_spawnPoint) = 0;
	virtual void				Reload(float &a_delta) = 0;
	virtual void				Init(const char* a_texturePath, glm::vec2 a_position, glm::vec2 a_velocity, float a_rotation, float a_width, float a_height, unsigned int a_newID) = 0;
	virtual void				Seek(glm::vec2 &a_target, float &a_delta) = 0;
	virtual void				Flee(glm::vec2 &a_target, float &a_delta) = 0;
	virtual void				DrawHealth(aie::Renderer2D* a_renderer) = 0;


	float						GetHealth();
	float						GetMaxHealth();
	float						GetMaxSpeed();
	float						GetRotation();
	float						GetWidth();
	float						GetHeight();
	float						GetAccuracy();
	float						GetSuppressionLevel();
	float						GetExhaustionLevel();
	aie::Texture*				GetTexturePtr();
	CWeapon*					GetMainWeapon();
	std::vector<CWeapon*>		GetAllWeapons();
	std::vector<CWeapon*>		GetAuxillaryWeapons();
	glm::vec2					GetCurrectWaypoint();
	float						GetCurrentSpeed();
	float						GetWayPointTolerance();
	eEntityType					GetEntityType();
	unsigned int				GetEntityID();

	void						SetMaxSpeed(float &a_maxSpeed);
	void						SetHealth(float &a_health);
	void						SetMaxHealth(float &a_maxHealth);
	void						SetRotation(float &a_rotation);
	void						SetWidth(float a_width);
	void						SetHeight(float a_height);
	void						SetWayPointTolerance(float a_tolerance);
	void						SetCurrentSpeed(float a_speed);
	void						SetMainWeapon(CWeapon* a_weapon);
	void						SetAuxiliaryWeaponList(std::vector<CWeapon*> a_weaponList);
	void						SetCurentTarget(CBaseEntity* a_target);
	void						SetReloadTime(double a_time);

	bool						IsAlive();
	bool						ShouldUpdate();


	float						DegToRad(float a_degrees);
	float						RadToDeg(float a_rad);
	float						VectorToAngle(glm::vec2 &a_vec);

	void						AddForce(glm::vec2 &a_force);
	void						AddWayPoint(glm::vec2 a_waypoint);
	void						SetCurrentWaypoint(glm::vec2 a_waypoint);
	void						AddAuxiliaryWeapon(CWeapon* a_weapon);
	void						RemoveAuxiliaryWeapon(int a_index);
	void						RemoveAuxiliaryWeapon(CWeapon* a_weapon);
	void						GenerateRandomStats();

	glm::vec2					m_Position;
	glm::vec2					m_Velocity;
	glm::vec2					m_Forward;

protected:
	float						m_CurrentHP;
	float						m_MaxHP;
	float						m_CurrentSpeed;
	float						m_MaxSpeed;
	float						m_Rotation;
	float						m_Width;
	float						m_Height;
	float						m_WayPointTolerance;
	float						m_Accuracy;
	float						m_SuppressionLevel;
	float						m_ExhaustionLevel;
	float						m_MoraleLevel;
	double						m_SecondsToReload;
	bool						m_bUpdate;
	bool						m_bAlive;
	unsigned int				m_TextureID;
	aie::Texture*				m_Texture;
	std::vector<CItem*>			m_Inventory;
	std::vector<glm::vec2>		m_WayPoints;
	std::vector<CBaseEntity*>	m_Targets;
	eEntityType					m_EntityType;
	eENTITY_STATE				m_State;
	eENTITY_STATE				m_PreviousState;
	unsigned int				m_uiEntityID;
	CWeapon*					m_MainWeapon;
	std::vector<CWeapon*>		m_AuxiliaryWeapons;
	CTimer*						m_AimTimer;
	CTimer*						m_ReloadTimer;
};



#endif
