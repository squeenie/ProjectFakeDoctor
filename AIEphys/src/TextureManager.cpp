#include "TextureManager.h"
#include "Texture.h"
#include "..\AIEphysApp.h"
#include <iostream>

extern AIEphysApp* app;

CTextureManager::CTextureManager(unsigned int a_maxNumTextures)
{
	m_TableMultiplier = 4;
	m_uiMaxNumberOfTextures = a_maxNumTextures;
	m_TextureTable = new aie::Texture*[m_uiMaxNumberOfTextures * m_TableMultiplier];
	for (int i = 0; i < m_uiMaxNumberOfTextures * m_TableMultiplier; ++i)
	{
		m_TextureTable[i] = nullptr;
	}
}

CTextureManager::~CTextureManager()
{

}

unsigned int CTextureManager::LoadTexture(const char* a_texture)
{
	unsigned int hash = app->HashString(a_texture);
	std::cout << "Attempting to load " << a_texture << std::endl;
	if (m_TextureTable[hash] != nullptr)
	{
		std::string tmp = m_TextureTable[hash]->getFilename();
		std::cout << "TextureTable index " << hash << " already loaded with " << tmp << std::endl;
	}
	else
	{
		m_TextureTable[hash] = new aie::Texture();
		m_TextureTable[hash]->load(a_texture);
	}
	return hash;
}

bool CTextureManager::IsTextureLoaded(const char* a_texture)
{
	unsigned int index = app->HashString(a_texture);

	std::cout << "IsTextureLoaded: " << a_texture << " with hashID " << index;

	if (m_TextureTable[index] != nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

aie::Texture* CTextureManager::GetTextureByID(unsigned int a_id)
{
	return m_TextureTable[a_id];
}

aie::Texture* CTextureManager::GetTextureByName(const char* a_textureName)
{
	return nullptr;
}

unsigned int CTextureManager::GetTextureIDFromFileName(const char* a_name)
{
	return 0;
}

unsigned int CTextureManager::GetMaxNumberOfTextures()
{
	return m_uiMaxNumberOfTextures;
}

unsigned int CTextureManager::GetTableSize()
{
	return m_uiMaxNumberOfTextures * m_TableMultiplier;
}

std::string CTextureManager::ExtractNameFromPath(const char* a_file)
{
	int length = strlen(a_file);
	for (int i = length - 1; i >= 0; --i)
	{
		//find slash, return new string from there
		if (a_file[i] == '/')
		{
			std::string ret = a_file + length + 1;
			return ret;
		}
	}
}
