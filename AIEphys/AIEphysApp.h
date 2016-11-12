#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "src\PhysScene.h"
#include "glm\glm.hpp"
class AIEphysApp : public aie::Application
{
public:

	AIEphysApp();
	virtual ~AIEphysApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	glm::vec2 GetRandomDirection();
protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_Font;
	PhysScene*			m_PhysScene;


};