#ifndef _SQUAD_H_
#define _SQUAD_H_

#include <vector>

class CBaseEntity;



class CSquad
{
public:
	CSquad();
	~CSquad();

	std::vector<CBaseEntity*> GetSquad();
	CBaseEntity* GetLeader();
	unsigned int NumberOfLivingMembers();
private:
};


#endif