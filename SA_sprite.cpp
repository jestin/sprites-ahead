#include "SA_sprite.h"

SASprite::SASprite(wxSize& size)
{
	m_Size = size;
	m_aPixels = new int[size.x * size.y];
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

wxOutputStream& SASprite::SaveObject(wxOutputStream &stream)
{
	// TODO

	return stream;
}

wxInputStream& SASprite::LoadObject(wxInputStream &stream)
{
	// TODO

	return stream;
}
