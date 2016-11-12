#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include <string>
#include <vector>

class CTimer;

namespace aie
{
	class Texture;
}

struct AnimFrame
{
	float u, v, w, h;
};

class Animation
{
public:
	Animation(const char *a_texture, unsigned int a_numFrames, unsigned int a_numFramesAcross, unsigned int a_numFramesDown, float a_frameRate);
	~Animation();

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
