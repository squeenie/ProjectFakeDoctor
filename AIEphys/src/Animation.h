#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "glm\glm.hpp"
#include <string>
#include <vector>

class CTimer;

namespace aie
{
	class Texture;
	class Renderer2D;
}

struct AnimFrame
{
	float u, v, w, h;
};

class CAnimation
{
public:
	CAnimation(const char *a_texture, unsigned int a_numFrames, unsigned int a_numFramesAcross, unsigned int a_numFramesDown, float a_frameRate, float a_width, float a_height);
	~CAnimation();

	void					SetNumberOfFrames(unsigned int a_frameCount);
	unsigned int			GetNumberOfFrames();
	void					SetTexture(const char *a_texture);
	const char*				GetTextureFileName();
	unsigned int			GetCurrentFrame();
	aie::Texture*			GetTexturePtr();
	std::vector<AnimFrame>	GetFrameList();
	void					AddFrame(AnimFrame a_newFrame);
	void					SetFrameRate(float &a_fps);
	float					GetFrameRate();
	void					Play();
	bool					IsLooping();
	void					SetLoop(bool a_loop);
	void					Draw(aie::Renderer2D* a_renderer);
	glm::vec2				m_Position;
	float					m_Rotation;
	float					m_Width;
	float					m_Height;
private:
	bool					m_bPlaying;
	bool					m_bLoop;
	unsigned int			m_CurrentFrame;
	unsigned int			m_TotalFrames;
	unsigned int			m_NumFramesAcross;
	unsigned int			m_NumFramesDown;
	float					m_FrameRate;
	std::string				m_FileName;
	aie::Texture*			m_Texture;
	std::vector<AnimFrame>  m_FrameList;
	CTimer*					m_Timer;
};

#endif
