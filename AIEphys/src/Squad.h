#ifndef _SQUAD_H
#define _SQUAD_H_

#include <vector>
#include <glm\glm.hpp>

class CBaseEntity;
enum eEntityType;

namespace aie
{
	class Renderer2D;
}

class CSquad
{
public:
	CSquad(unsigned int a_maxMembers, unsigned int a_squadID, glm::vec2 a_position);
	~CSquad();

	void						Update(float &a_delta);
	void						Draw(aie::Renderer2D* a_renderer);

	std::vector<CBaseEntity*>	GetSquad();
	CBaseEntity*				GetLeader();
	std::vector<glm::vec2>		GetWaypoints();
	unsigned int				GetNumberOfLivingMembers();
	unsigned int				GetSquadID();

	void						SetSquadWayPoint(glm::vec2 a_waypoint);
	void						SetSquadWayPointTolerance(float a_tol);
	void						ResolveSquadOnSquadCollisions(float &a_delta);
	void						SetSquadTarget(CBaseEntity* a_target);

	bool						CreateMember(eEntityType a_type, glm::vec2 a_position, unsigned int a_ID);
	
	glm::vec2					m_Position;
private:
	unsigned int				m_uiSquadID;
	unsigned int				m_uiLivingMembers;
	unsigned int				m_uiMaximumMembers;
	float						m_Morale;
	std::vector<glm::vec2>		m_Waypoints;
	std::vector<CBaseEntity*>	m_Members;
	
	float						m_Radius;
};


#endif