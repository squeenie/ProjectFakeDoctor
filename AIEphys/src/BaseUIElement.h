#ifndef _BASEUIELEMENT_H_
#define _BASEUIELEMENT_H_

#include "glm\\glm.hpp"

namespace aie
{
	class Texture;
	class Renderer2D;
}

class CBaseUIElement
{
public:
	CBaseUIElement();
	~CBaseUIElement();

	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void OnClick() = 0;

	glm::vec2	m_Position;
	float		m_Width;
	float		m_Height;
private:
	aie::Texture*	m_Texture;
};



#endif