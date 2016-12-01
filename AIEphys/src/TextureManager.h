#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_

#include <vector>
#include <string.h>

namespace aie
{
	class Texture;
}

class CTextureManager
{
public:
	CTextureManager(unsigned int a_maxNumTextures);
	~CTextureManager();

	unsigned int		LoadTexture(const char* a_texture);
	bool				IsTextureLoaded(const char* a_texture);

	aie::Texture*		GetTextureByID(unsigned int a_id);
	aie::Texture*		GetTextureByName(const char* a_textureName);
	unsigned int		GetTextureIDFromFileName(const char* a_name);
	unsigned int		GetMaxNumberOfTextures();
	unsigned int		GetTableSize();

private:
	std::string			ExtractNameFromPath(const char* a_file);
	aie::Texture**		m_TextureTable;
	unsigned int		m_uiMaxNumberOfTextures;
	unsigned int		m_TableMultiplier;
};


#endif