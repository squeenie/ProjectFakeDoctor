#ifndef _ITEM_H_
#define _ITEM_H_

#include <glm\glm.hpp>

namespace aie
{
	class Texture;
	class Renderer2D;
}

class CItem
{
public:
	CItem(const char* a_textureFilename, glm::vec2 a_position);
	~CItem();

	virtual void	Activate() = 0;
	virtual void	Draw(aie::Renderer2D* a_renderer) = 0;
	virtual void	OnPickup() = 0;
	virtual void	OnDrop() = 0;

	aie::Texture*	GetTexturePtr();
	float			GetRotation();
	glm::vec2		GetDimensions();

	glm::vec2		m_Position;

protected:
	aie::Texture*	m_Texture;
	glm::vec2		m_Dimensions;
	float			m_Rotation;
};


#endif