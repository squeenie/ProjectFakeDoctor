#ifndef _EMITTER_H_
#define _EMITTER_H_

#include "glm\glm.hpp"
#include <vector>

class CParticle;

class CEmitter
{
public:
	CEmitter(glm::vec2 a_position);
	~CEmitter();

protected:
	unsigned int m_MaxParticles;
	unsigned int m_ParticleCount;
	CParticle* m_ParticleArray;
};


#endif