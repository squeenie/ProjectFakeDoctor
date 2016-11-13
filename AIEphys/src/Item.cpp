#include "Item.h"
#include "Texture.h"
CItem::CItem(const char* a_textureFilename, glm::vec2 a_position)
{
	m_Texture = new aie::Texture(a_textureFilename);
	m_Position = a_position;
}

CItem::~CItem()
{
	delete m_Texture;
}

aie::Texture* CItem::GetTexturePtr()
{
	return m_Texture;
}

float CItem::GetRotation()
{
	return m_Rotation;
}

glm::vec2 CItem::GetDimensions()
{
	return m_Dimensions;
}
