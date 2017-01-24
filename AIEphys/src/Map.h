#ifndef _MAP_H_
#define _MAP_H_

class CBaseEntity;
class CTile;

namespace aie
{
	class Texture;
	class Renderer2D;
}

class CMap
{
public:
	CMap();
	~CMap();


private:
	aie::Texture*	m_BaseTexture;
	CTile*			m_Tiles;
};

#endif