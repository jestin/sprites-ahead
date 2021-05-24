#include "SA_sprite.h"

SASprite::SASprite()
{
}

SASprite::SASprite(SASprite& sprite)
{
	m_Size = sprite.GetSize();

	// pre-allocate the memory to prevent copies during inserts
	m_vPixels.reserve(m_Size.x * m_Size.y);

	std::copy(sprite.GetPixels().begin(),
			sprite.GetPixels().end(),
			std::back_inserter(m_vPixels));
}

SASprite::~SASprite()
{
}

std::ostream& SASprite::SaveObject(std::ostream& stream)
{
	stream << (wxInt32) m_Size.GetWidth() << '\n' << (wxInt32) m_Size.GetHeight() << '\n';

	for(int i = 0; i < m_Size.GetWidth() * m_Size.GetHeight(); i++) 
	{
		stream << m_vPixels[i] << '\n';
	}
	stream << '\n';

	return stream;
}

std::istream& SASprite::LoadObject(std::istream &stream)
{
	wxInt32 w, h;

	stream >> w;
	stream >> h;

	m_Size = wxSize(w, h);

	for(int i = 0; i < w * h; i++)
	{
		stream >> m_vPixels[i];
	}

	return stream;
}
