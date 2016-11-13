#ifndef _ITEM_H_
#define _ITEM_H_

#include <glm\glm.hpp>

namespace aie
{
	class Texture;
}

class CItem
{
public:
	CItem(const char* a_textureFilename, glm::vec2 a_position);
	~CItem();

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