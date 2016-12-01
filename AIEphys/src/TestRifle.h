#ifndef _TESTRIFLE_H_
#define _TESTRIFLE_H_

#include "Weapon.h"


class CTestRifle : public CWeapon
{
public:
	CTestRifle();
	CTestRifle(const char* a_name);
	~CTestRifle();

	void Fire(CBaseEntity* a_target) override;
	void OnReload() override;
	void Update(float &a_delta) override;
	void EjectShell() override;
private:
};


#endif