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
	stream << m_Size.GetWidth() << '\n' << m_Size.GetHeight() << '\n';

	for(int i = 0; i < m_Size.GetWidth() * m_Size.GetHeight(); i++) 
	{
		stream << m_aPixels[i] << '\n';
	}
	stream << '\n';

	return stream;
}

std::istream& SASprite::LoadObject(std::istream &stream)
{
	int w, h;

	stream >> w;
	stream >> h;

	m_Size = wxSize(w, h);

	for(int i = 0; i < w * h; i++)
	{
		stream >> m_aPixels[i];
	}

	return stream;
}
