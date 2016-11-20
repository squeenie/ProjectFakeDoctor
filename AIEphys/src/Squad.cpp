#include "Squad.h"
#include "EntityTypes.h"
#include "TestEntity.h"

CSquad::CSquad(unsigned int a_maxMembers, unsigned int a_squadID, glm::vec2 a_position)
{
	m_uiMaximumMembers = a_maxMembers;
	m_uiSquadID = a_squadID;
	m_Position = a_position;
}

CSquad::~CSquad()
{
	for (int i = 0; i < m_Members.size(); ++i)
	{
		delete m_Members.at(i);
	}
}

void CSquad::Update(float &a_delta)
{
	unsigned int livingMembers = 0;
	for (unsigned int i = 0; i < m_Members.size(); ++i)
	{
		m_Members.at(i)->Update(a_delta);
		if (m_Members.at(i)->IsAlive())
		{
			livingMembers++;
		}
	}
	m_uiLivingMembers = livingMembers;
}

void CSquad::Draw(aie::Renderer2D* a_renderer)
{
	for (unsigned int i = 0; i < m_Members.size(); ++i)
	{
		m_Members.at(i)->Draw(a_renderer);
	}
}

std::vector<CBaseEntity*> CSquad::GetSquad()
{
	return m_Members;
}

CBaseEntity* CSquad::GetLeader()
{
	return nullptr;
}

std::vector<glm::vec2> CSquad::GetWaypoints()
{
	return m_Waypoints;
}

unsigned int CSquad::GetNumberOfLivingMembers()
{
	return m_uiLivingMembers;
}

unsigned int CSquad::GetSquadID()
{
	return m_uiSquadID;
}

void CSquad::SetSquadWayPoint(glm::vec2 a_waypoint)
{
	if (m_Waypoints.size() > 0)
	{
		m_Waypoints.at(0) = a_waypoint;
	}
	else
	{
		m_Waypoints.push_back(a_waypoint);
		
	}
	for (int i = 0; i < m_Members.size(); ++i)
	{
		glm::vec2 tmp = glm::vec2(0, 1);
		int angle = rand() % 360;
		tmp.x = glm::cos((float)(angle * 0.0174533));
		tmp.y = glm::sin((float)(angle * 0.0174533));
		tmp = glm::normalize(tmp);
		m_Members.at(i)->SetCurrentWaypoint(a_waypoint + (tmp * 90.0f));
	}
}

void CSquad::SetSquadWayPointTolerance(float a_tol)
{
	for (int i = 0; i < m_Members.size(); ++i)
	{
		m_Members.at(i)->SetWayPointTolerance(a_tol);
	}
}

void CSquad::ResolveSquadOnSquadCollisions(float &a_delta)
{
	for (int i = 0; i < m_Members.size(); ++i)
	{
		for (int j = 0; j < m_Members.size(); ++j)
		{
			if (i == j)
			{
				continue;
			}
			else
			{

			}
		}
	}
}

bool CSquad::CreateMember(eEntityType a_type, glm::vec2 a_position, unsigned int a_ID)
{
	if (m_Members.size() < m_uiMaximumMembers)
	{
		if (a_type == ENTITY_TEST_RIFLEMAN)
		{
			TestEntity* newEntity = new TestEntity();
			newEntity->Init("./Images/Infantry/Stock_infantry.png", m_Position + a_position, glm::vec2(0), 0.0f, 30, 30, a_ID);
			float speed = 75.0f;
			newEntity->SetMaxSpeed(speed);
			m_Members.push_back(newEntity);
			return true;
		}
	}
	return false;
}
