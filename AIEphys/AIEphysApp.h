#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "src\PhysScene.h"
#include "glm\glm.hpp"
#include <string.h>

class CTextureManager;

class AIEphysApp : public aie::Application
{
public:

	AIEphysApp();
	virtual ~AIEphysApp();

	virtual bool		startup();
	virtual void		shutdown();
		
	virtual void		update(float deltaTime);
	virtual void		draw();

	glm::vec2			GetRandomDirection();
	float				VectorToAngle(glm::vec2 a_angle);
	float				DegToRad(float a_degrees);
	float				RadToDeg(float a_radians);
	unsigned int		HashString(std::string a_str);
	glm::vec2			m_MousePosition;

protected:
	CTextureManager*	m_TextureManager;
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_Font;
	PhysScene*			m_PhysScene;
	unsigned int		m_uiEntityCounter;
	unsigned int		testTextureID;
};