#include "AIEphysApp.h"
#include "Font.h"
#include "Input.h"
#include <iostream>

#include "src\PhysicsObject.h"
#include "src\Circle.h"
#include <random>
#include <time.h>
#include "src\Animation.h"
bool bForceApplied = false;
bool bSpawned = false;

Animation *ptrAnim;

AIEphysApp::AIEphysApp()
{

}

AIEphysApp::~AIEphysApp()
{

}

bool AIEphysApp::startup()
{
	srand(time(NULL));
	m_2dRenderer = new aie::Renderer2D();

	m_Font = new aie::Font("./font/consolas.ttf", 16);
	m_PhysScene = new PhysScene(-9.8, 1.0 / 60.0);

	ptrAnim = new Animation("./Images/Effects/explosion_stock.png", 16, 4, 4, 12.0f);
	ptrAnim->SetLoop(false);

	return true;
}

void AIEphysApp::shutdown()
{
	m_PhysScene->DeleteAllActors();
	delete m_Font;
	delete m_2dRenderer;
}

void AIEphysApp::update(float deltaTime)
{

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	if (input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		if (!bSpawned)
		{
			bSpawned = true;
			float massradius = 10;
			float mass2 = 10;
			PhysicsObject *testCircle = new CircleBody(glm::vec2(350, 300), glm::vec2(0), massradius, massradius, glm::vec4(1, 0, 0, 1));
			PhysicsObject *testCircle2 = new CircleBody(glm::vec2(420, 300), glm::vec2(0), mass2, massradius, glm::vec4(1, 0, 0, 1));
			m_PhysScene->AddActor(testCircle);
			m_PhysScene->AddActor(testCircle2);

			std::cout << "Created Circle" << std::endl;
		}
	}
	if (input->isKeyDown(aie::INPUT_KEY_DELETE))
	{
		m_PhysScene->DeleteAllActors();
	}
	if (input->isKeyDown(aie::INPUT_KEY_ENTER))
	{
		if (!bForceApplied)
		{
			bForceApplied = true;
			m_PhysScene->GetActors().at(0)->ApplyForce(glm::vec2(1.0, 0.0) * 30.0f);
			//m_PhysScene->GetActors().at(0)->ApplyForceToActor(m_PhysScene->GetActors().at(1), m_PhysScene->GetActors().at(0)->GetMomentum());
		}
	}
	ptrAnim->Play();
	m_PhysScene->Update(deltaTime);
	/*for (int i = 0; i < m_PhysScene->GetNumberOfActors(); ++i)
	{
		m_PhysScene->GetActors().at(i)->Update(deltaTime);
	}*/
}

void AIEphysApp::draw()
{

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	for (int i = 0; i < m_PhysScene->GetNumberOfActors(); ++i)
	{
		m_PhysScene->GetActors().at(i)->Draw(m_2dRenderer);
		//m_2dRenderer->drawLine(400, 300, m_PhysScene->GetActors().at(i)->GetPosition().x,
		//						m_PhysScene->GetActors().at(i)->GetPosition().y);
	}
	//draw collision points
	for (int i = 0; i < m_PhysScene->GetCollisionList().size(); ++i)
	{
		m_2dRenderer->drawBox(m_PhysScene->GetCollisionList().at(i).x, m_PhysScene->GetCollisionList().at(i).y, 1, 1, 0);
		m_2dRenderer->drawLine(m_PhysScene->GetCollisionList().at(i).x, m_PhysScene->GetCollisionList().at(i).y, 500, 500);
	}
	
	
	// output some text
	m_2dRenderer->drawText(m_Font, "Press ESC to quit", 0, 0);


	m_2dRenderer->setUVRect(ptrAnim->GetFrameList().at(ptrAnim->GetCurrentFrame()).u, ptrAnim->GetFrameList().at(ptrAnim->GetCurrentFrame()).v, ptrAnim->GetFrameList().at(ptrAnim->GetCurrentFrame()).w, ptrAnim->GetFrameList().at(ptrAnim->GetCurrentFrame()).h);
	/*m_2dRenderer->drawSprite(ptrAnim->GetTexturePtr(), 60, 30, ptrAnim->GetFrameList().at(ptrAnim->GetCurrentFrame()).w, ptrAnim->GetFrameList().at(ptrAnim->GetCurrentFrame()).h);*/
	//m_2dRenderer->setUVRect(0, 0, 0.5, 0.5);
	m_2dRenderer->drawSprite(ptrAnim->GetTexturePtr(), 200, 300, 128, 128);

	// done drawing sprites
	m_2dRenderer->end();
	//m_PhysScene->ClearCollisionList();
}

glm::vec2 AIEphysApp::GetRandomDirection()
{
	glm::vec2 tmp = glm::vec2(0, 1);
	int angle = rand() % 360;
	std::cout << "Random angle: " << angle << std::endl;
	tmp.x = glm::cos((float)(angle * 0.0174533));
	tmp.y = glm::sin((float)(angle * 0.0174533));

	return tmp;
}
