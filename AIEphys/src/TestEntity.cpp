#include "TestEntity.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "Timer.h"
#include "Animation.h"
#include "TestRifle.h"

TestEntity::TestEntity()
{
	m_EntityType = ENTITY_TEST_RIFLEMAN;
	m_Texture = new aie::Texture("./Images/stock_infantry.png");
	m_CooldownTimer = new CTimer();
	m_DieAnim = nullptr;
	m_RunAnim = nullptr;
	m_IdleAnim = nullptr;
	m_WalkAnim = nullptr;
	m_CurrentAnimation = nullptr;
	m_State = STATE_UNINITIALIZED;
	m_PreviousState = STATE_UNINITIALIZED;
	m_MainWeapon = new CTestRifle();
	m_MainWeapon->SetParent(this);
	
}

TestEntity::~TestEntity()
{
	delete m_Texture;
}

void TestEntity::Update(float &a_delta)
{
	if (m_CurrentHP < 0)
	{
		m_bAlive = false;
		m_CurrentHP = 0;
	}

	if (m_bAlive) //TODO: Create proper logic (sense, think, act) not state machine
	{
		if (m_Targets.size() > 0)
		{
			m_State = STATE_ATTACK;
		}
		if (m_State == STATE_IDLE)
		{
			m_CurrentAnimation = m_IdleAnim;
			
		}
		else if (m_State == STATE_WALK)
		{
			m_CurrentAnimation = m_WalkAnim;
		}

		if (m_State == STATE_ATTACK)
		{
			if (m_Targets.at(0)->IsAlive())
			{
				Attack(a_delta);
			}
		}
		m_CurrentAnimation->Play();
	}
	Move(a_delta);
	if (m_Velocity != glm::vec2(0) && glm::length(m_Velocity) > 1.0)
	{
		float angle = RadToDeg(VectorToAngle(m_Velocity));
		float newAngle = DegToRad(270.0f - angle);
		SetRotation(newAngle);
	}
	m_PreviousState = m_State;
}

void TestEntity::Draw(aie::Renderer2D* a_renderer/*, float &a_delta*/)
{
	
	m_CurrentAnimation->m_Position = m_Position;
	m_CurrentAnimation->m_Rotation = m_Rotation;
	m_CurrentAnimation->Draw(a_renderer);
	if (m_State == STATE_AIM)
	{
		//draw aim progress bar or something
	}
	if (m_State == STATE_ATTACK)
	{
		DrawMuzzle(a_renderer);
	}

	DrawHealth(a_renderer);
}

void TestEntity::Move(float &a_delta)
{
	//check for waypoints
	if (m_bAlive == false)
	{
		return;
	}
	if (m_WayPoints.size() > 0)
	{
		/*
		TODO:
		1. push new waypoints to back of vector
		2. Follow waypoints in reverse order
		3. Pop back when target is reached
		*/
		
		//get direction and distance to waypoint
		glm::vec2 newForce = glm::vec2(0);
		glm::vec2 vecToWayPoint = m_WayPoints.at(0) - m_Position;
		float distanceToWayPoint = glm::length(vecToWayPoint);
		if (distanceToWayPoint > m_WayPointTolerance)
		{
			/*glm::vec2 dir = glm::normalize(vecToWayPoint);
			newForce = dir * (m_CurrentSpeed * a_delta);

			AddForce(newForce);*/
			m_State = STATE_WALK;
			m_CurrentSpeed += m_MaxSpeed * a_delta;

			if (m_CurrentSpeed > m_MaxSpeed)
			{
				m_CurrentSpeed = m_MaxSpeed;
			}
			Seek(m_WayPoints.at(0), a_delta);

		}
		else
		{
			m_State = STATE_IDLE;
			glm::vec2 friction = (-glm::normalize(m_Velocity) *  m_MaxSpeed) * a_delta;
			if (glm::length(m_Velocity) < 1.0)
			{
				m_Velocity = glm::vec2(0);
			}
			else
			{
				AddForce(friction);
			}
		}
	}
	if (glm::length(m_Velocity) > m_MaxSpeed)
	{
		m_Velocity = (glm::normalize(m_Velocity) * m_MaxSpeed);
	}
	
	m_Position += m_Velocity * a_delta;
}

void TestEntity::Attack(float &a_delta)
{
	m_MainWeapon->Fire(m_Targets.at(0));
}

void TestEntity::Spawn(glm::vec2 &a_spawnPoint)
{
	m_Position = a_spawnPoint;
}

void TestEntity::Init(const char* a_texturePath, glm::vec2 a_position, glm::vec2 a_velocity, float a_rotation, float a_width, float a_height, unsigned int a_newID)
{
	m_Position = a_position;
	m_Velocity = a_velocity;
	m_Rotation = a_rotation;
	m_Width = a_width;
	m_Height = a_height;
	m_Texture = new aie::Texture(a_texturePath);

	m_IdleAnim = new CAnimation("./Images/Infantry/stock_inf_idle.png", 31, 31, 1, 8, m_Width, m_Height);
	m_IdleAnim->SetLoop(true);
	m_WalkAnim = new CAnimation("./Images/Infantry/stock_inf_idle.png", 31, 31, 1, 16, m_Width, m_Height);
	m_WalkAnim->SetLoop(true);
	m_CurrentAnimation = m_IdleAnim;

	m_State = STATE_IDLE;
	m_PreviousState = STATE_IDLE;

	m_CurrentSpeed = 0.0f;
	m_MaxSpeed = 60.0f;
	m_MaxHP = 60.0f;
	m_CurrentHP = m_MaxHP;
	m_uiEntityID = a_newID;
	m_bAlive = true;
	m_bUpdate = true;

	float condition = 1.0;
	m_MainWeapon->SetCondition(condition);
	m_MainWeapon->SetFlashSize(48, 48);
}

void TestEntity::Seek(glm::vec2 &a_target, float &a_delta)
{
	glm::vec2 dir = glm::normalize(a_target - m_Position);
	AddForce(dir * (m_CurrentSpeed * a_delta));
}

void TestEntity::Flee(glm::vec2 &a_target, float &a_delta)
{
	glm::vec2 dir = glm::normalize(m_Position - a_target);
	AddForce(dir * (m_CurrentSpeed * a_delta));
}

void TestEntity::Reload(float &a_delta)
{
	m_State = STATE_RELOAD;
	m_ReloadTimer->Start(m_SecondsToReload);
}

void TestEntity::DrawHealth(aie::Renderer2D* a_renderer)
{
	glm::vec2 p = m_Position;
	p.x -= m_Width * 0.5;
	p.y -= m_Height * 0.5;
	float percentage = m_CurrentHP / m_MaxHP;
	if (percentage >= 0.7)
	{
		a_renderer->setRenderColour(0, 1, 0);
	}
	else if (percentage >= 0.4 && percentage < 0.7)
	{
		a_renderer->setRenderColour(1, 1, 0);
	}
	else if (percentage < 0.4)
	{
		a_renderer->setRenderColour(1, 0, 0);
	}
	else
	{
		a_renderer->setRenderColour(1, 1, 1);
	}
	a_renderer->drawLine(p.x, p.y, p.x + (m_Width * percentage), p.y, 2.0);
}

void TestEntity::DrawMuzzle(aie::Renderer2D* a_renderer)
{
	m_MainWeapon->GetMuzzleAnimation()->m_Position = m_Position + glm::vec2(0, 16);
	m_MainWeapon->GetMuzzleAnimation()->Draw(a_renderer);
}
