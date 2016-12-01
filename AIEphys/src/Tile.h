#ifndef _TILE_H_
#define _TILE_H_

#include <glm\glm.hpp>

enum eTileType
{
	TILE_TYPE_UNDEFINED,
	TYLE_TYPE_GRASS,
	TILE_TYPE_ROAD,
	TILE_TYPE_DIRT,
	TILE_TYPE_WATER
};

namespace aie
{
	class Texture;
	class Renderer2D;
}

class CTile
{
public:
	CTile();
	~CTile();

	virtual void		Draw(aie::Renderer2D* a_renderer);

	glm::vec2			m_Position;
	glm::vec2			m_Dimensions;
private:
	aie::Texture*		m_Texture;
	eTileType			m_TileType;
};


#endif