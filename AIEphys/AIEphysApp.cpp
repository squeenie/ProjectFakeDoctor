#include "AIEphysApp.h"
#include "Font.h"
#include "Input.h"
#include <iostream>

#include "src\PhysicsObject.h"
#include "src\Circle.h"
#include <random>
#include <time.h>
#include "src\Animation.h"
#include "src\TestEntity.h"
#include "gl_core_4_4.h"
#include <..\dependencies\glfw\include\GLFW\glfw3.h>
#include <string.h>
#include "src\Timer.h"
#include "src\Squad.h"
#include "src\TextureManager.h"
#include "Texture.h"

bool bForceApplied = false;
bool bSpawned = false;
bool bDoExplosion = false;

CAnimation *ptrAnim;
CSquad *testSquad;
glm::vec2 impact;
TestEntity *ptrEntity = nullptr;

CTimer BombTimer;

/*
TODO:

* Create BaseEntity class
* Create Sound Manager
* Finish Physics
* More

*/

AIEphysApp::AIEphysApp()
{

}

AIEphysApp::~AIEphysApp()
{

}

bool AIEphysApp::startup()
{

	BombTimer.Start(1.0);
	m_uiEntityCounter = 0;
	srand(time(NULL));
	m_2dRenderer = new aie::Renderer2D();

	m_Font = new aie::Font("./font/consolas.ttf", 16);
	m_PhysScene = new PhysScene(-9.8, 1.0 / 60.0);

	//aie::Texture *tt = new aie::Texture("./Images/Map/Terrain/stock_snowy_concrete_seamless.png");
	m_TextureManager = new CTextureManager(500);
	testTextureID = m_TextureManager->LoadTexture("./Images/Map/Terrain/stock_snowy_concrete_seamless.png");

	std::cout << "Creating Animation..." << std::endl;
	ptrAnim = new CAnimation("./Images/Effects/explosion_stock.png", 16, 4, 4, 12.0f, 128, 128);
	ptrAnim->m_Position = glm::vec2(300, 300);
	ptrAnim->m_Rotation = 0;
	ptrAnim->SetLoop(false);
	std::cout << "Done" << std::endl;

	std::cout << "Spawning TestEntity..." << std::endl;
	m_uiEntityCounter++;
	ptrEntity = new TestEntity();
	ptrEntity->Init("./Images/Infantry/Stock_infantry.png", glm::vec2(50, 50), glm::vec2(0), 0.0f, 60, 60, m_uiEntityCounter);
	float speed = 75.0f;
	ptrEntity->SetMaxSpeed(speed);
	std::cout << "Done" << std::endl;

	std::cout << "Creating Test Squad..." << std::endl;
	testSquad = new CSquad(6, 1, glm::vec2(300, 200));
	m_uiEntityCounter++;
	testSquad->CreateMember(ENTITY_TEST_RIFLEMAN, GetRandomDirection() * 50.0f, m_uiEntityCounter);
	m_uiEntityCounter++;
	testSquad->CreateMember(ENTITY_TEST_RIFLEMAN, GetRandomDirection() * 50.0f, m_uiEntityCounter);
	m_uiEntityCounter++;
	testSquad->CreateMember(ENTITY_TEST_RIFLEMAN, GetRandomDirection() * 50.0f, m_uiEntityCounter);
	m_uiEntityCounter++;
	testSquad->CreateMember(ENTITY_TEST_RIFLEMAN, GetRandomDirection() * 50.0f, m_uiEntityCounter);
	m_uiEntityCounter++;
	testSquad->CreateMember(ENTITY_TEST_RIFLEMAN, GetRandomDirection() * 50.0f, m_uiEntityCounter);

	std::cout << "Done" << std::endl;
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
	BombTimer.Update();
	aie::Input* input = aie::Input::getInstance();
	m_MousePosition = glm::vec2(input->getMouseX(), getWindowHeight() - input->getMouseY());

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	
	if (input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		//testSquad->SetSquadWayPointTolerance(100.0f);
		//testSquad->SetSquadWayPoint(m_MousePosition);
		testSquad->SetSquadTarget(ptrEntity);
	}
	if (input->isKeyDown(aie::INPUT_KEY_ENTER))
	{
		if (BombTimer.m_bFinished)
		{
			BombTimer.Restart();
			bDoExplosion = true;
			impact = glm::vec2(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
			float dist = (float)((rand() % 400) * 0.5);
			impact += GetRandomDirection() * dist;
		}
		else
		{
			bDoExplosion = false;
		}
	}
	
	ptrEntity->Update(deltaTime);
	ptrAnim->Play();
	m_PhysScene->Update(deltaTime);
	testSquad->Update(deltaTime);
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
	// output some text
	m_2dRenderer->drawText(m_Font, "Press ESC to quit", 0, 0);

	if (ptrEntity->m_Velocity != glm::vec2(0) && glm::length(ptrEntity->m_Velocity) > 1.0)
	{
		std::string text;
		text = "Rotation: ";
		float angle = RadToDeg(VectorToAngle(ptrEntity->m_Velocity));
		float newAngle = DegToRad(270.0f - angle);
		ptrEntity->SetRotation(newAngle);
		text += std::to_string(angle);
		m_2dRenderer->drawText(m_Font, text.c_str(), 0, 600);
	}
	
	m_2dRenderer->setUVRect(0, 0, 1, 1);
	m_2dRenderer->drawSprite(m_TextureManager->GetTextureByID(testTextureID), 600, 500, 64, 64);
	m_2dRenderer->drawSprite(m_TextureManager->GetTextureByID(testTextureID), 600, 564, 64, 64);

	ptrEntity->Draw(m_2dRenderer);
	if (ptrEntity->GetCurrectWaypoint() != glm::vec2(0))
	{
		m_2dRenderer->setRenderColour(1, 1, 1, 0.2f);
		m_2dRenderer->drawCircle(ptrEntity->GetCurrectWaypoint().x, ptrEntity->GetCurrectWaypoint().y, ptrEntity->GetWayPointTolerance());
	}

	if (bDoExplosion)
	{
		m_2dRenderer->setUVRect(ptrAnim->GetFrameList().at(ptrAnim->GetCurrentFrame()).u, ptrAnim->GetFrameList().at(ptrAnim->GetCurrentFrame()).v, ptrAnim->GetFrameList().at(ptrAnim->GetCurrentFrame()).w, ptrAnim->GetFrameList().at(ptrAnim->GetCurrentFrame()).h);
		m_2dRenderer->drawSprite(ptrAnim->GetTexturePtr(),impact.x, impact.y, 128, 128);
	}

	testSquad->Draw(m_2dRenderer);
	m_2dRenderer->setRenderColour(1, 1, 1, 0.1f);
	m_2dRenderer->drawCircle(ptrAnim->m_Position.x, ptrAnim->m_Position.y, 20);
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	ptrAnim->Draw(m_2dRenderer);
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

	return glm::normalize(tmp);
}

CTextureManager* AIEphysApp::GetTextureManager()
{
	return m_TextureManager;
}

float AIEphysApp::VectorToAngle(glm::vec2 a_angle)
{
	return atan2(a_angle.x, a_angle.y);
}

float AIEphysApp::DegToRad(float a_degrees)
{
	return (a_degrees + 90.0f) * 0.0174533;
}

float AIEphysApp::RadToDeg(float a_radians)
{
	return (a_radians * 57.2958) + 90.0f;
}

unsigned int AIEphysApp::HashString(std::string a_str)
{
	unsigned int hash = 0;
	for (int i = 0; i < a_str.size(); ++i)
	{
		int val = (int)a_str[i];
		hash = (hash * 256 + val) % m_TextureManager->GetTableSize();
	}
	return hash;
}
