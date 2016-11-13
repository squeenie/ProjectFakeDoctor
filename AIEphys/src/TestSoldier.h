#ifndef _TESTSOLDIER_H_
#define _TESTSOLDIER_H_
#include "BaseEntity.h"

class TestEntity : CBaseEntity public
{
public:
	TestEntity();
	~TestEntity();

	void		Update(float &a_delta);
	void		Draw(aie::Renderer2D* a_renderer, float &a_delta);
	void		Move(float &a_delta);


private:
	
}


#endif