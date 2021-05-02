#include "SA_sprite.h"

SASprite::SASprite()
{
}

SASprite::SASprite(SASprite& sprite)
{
	m_Size = sprite.GetSize();
	m_aPixels = new int[m_Size.x * m_Size.y];

	for(int i = 0; i < m_Size.x * m_Size.y; i++)
	{
		m_aPixels[i] = sprite.GetPixels()[i];
	}
}

SASprite::~SASprite()
{
	delete[] m_aPixels;
}

std::ostream& SASprite::SaveObject(std::ostream& stream)
{
	// TODO

	return stream;
}

std::istream& SASprite::LoadObject(std::istream &stream)
{
	// TODO

	return stream;
}
