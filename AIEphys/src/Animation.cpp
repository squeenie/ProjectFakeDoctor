#include "Animation.h"
#include "texture.h"
#include "Timer.h"
#include "Renderer2D.h"

CAnimation::CAnimation(const char * a_texture, unsigned int a_numFrames, unsigned int a_numFramesAcross, unsigned int a_numFramesDown, float a_frameRate, float a_width, float a_height)
{
	m_Texture = new aie::Texture(a_texture);
	m_TotalFrames = a_numFrames;
	m_FrameRate = a_frameRate;
	m_CurrentFrame = 0;
	m_bLoop = false;
	m_bPlaying = false;
	m_NumFramesAcross = a_numFramesAcross;
	m_NumFramesDown = a_numFramesDown;
	m_Timer = new CTimer();
	m_Width = a_width;
	m_Height = a_height;
	for (int y = 0; y < m_NumFramesDown; ++y)
	{
		unsigned int count = 0;
		for (int x = 0; x < m_NumFramesAcross; ++x)
		{
			AnimFrame frame;
			float texW = m_Texture->getWidth();
			float texH = m_Texture->getHeight();
			frame.w = (texW / m_NumFramesAcross) / texW;
			frame.h = (texH / m_NumFramesDown) / texH;
			frame.u = x * frame.w;
			frame.v = y * frame.h;
			m_FrameList.push_back(frame);
			++count;
			if (count >= m_TotalFrames)
			{
				break;
			}
		}
		if (count >= m_TotalFrames)
		{
			break;
		}
	}
}

CAnimation::~CAnimation()
{
	delete m_Timer;
	delete m_Texture;
}

void CAnimation::SetNumberOfFrames(unsigned int a_frameCount)
{
	//m_TotalFrames = a_frameCount;
	return;
}

unsigned int CAnimation::GetNumberOfFrames()
{
	return m_TotalFrames;
}

void CAnimation::SetTexture(const char *a_texture)
{
	std::cout << "[!] Warning! SetTexture is not advised. Be careful to maintain correct dimensions, frame count, etc" << std::endl;
	//TODO
}

const char* CAnimation::GetTextureFileName()
{
	return m_Texture->getFilename().c_str();
}

unsigned int CAnimation::GetCurrentFrame()
{
	return m_CurrentFrame;
}

aie::Texture* CAnimation::GetTexturePtr()
{
	return m_Texture;
}

std::vector<AnimFrame> CAnimation::GetFrameList()
{
	return m_FrameList;
}

void CAnimation::AddFrame(AnimFrame a_newFrame)
{
	m_FrameList.push_back(a_newFrame);
}

void CAnimation::SetFrameRate(float &a_fps)
{
	m_FrameRate = a_fps;
}

float CAnimation::GetFrameRate()
{
	return m_FrameRate;
}

void CAnimation::Play()
{
	if (!m_bPlaying)
	{
		m_Timer->Start(1.0 / m_FrameRate);
		m_bPlaying = true;
	}
	else
	{
		m_Timer->Update();
		if (m_Timer->m_bFinished)
		{
			m_Timer->Reset();
			m_Timer->Start(1.0 / m_FrameRate);
			m_CurrentFrame++;
			if (m_CurrentFrame >= m_TotalFrames)
			{
				if (m_bLoop)
				{
					m_CurrentFrame = 0;
				}
				else
				{
					m_CurrentFrame = m_TotalFrames - 1;
					m_bPlaying = false;
				}
			}
		}
	}
	
}

bool CAnimation::IsLooping()
{
	return m_bLoop;
}

void CAnimation::SetLoop(bool a_loop)
{
	m_bLoop = a_loop;
}

void CAnimation::Draw(aie::Renderer2D* a_renderer)
{
	a_renderer->setRenderColour(1, 1, 1, 1);
	a_renderer->setUVRect(GetFrameList().at(GetCurrentFrame()).u, GetFrameList().at(GetCurrentFrame()).v, GetFrameList().at(GetCurrentFrame()).w, GetFrameList().at(GetCurrentFrame()).h);
	a_renderer->drawSprite(GetTexturePtr(), m_Position.x, m_Position.y, m_Width, m_Height, m_Rotation);
}
