#include "SA_palette.h"

SAPalette::SAPalette()
{
}

SAPalette::SAPalette(SAPalette& palette)
{
	m_nColors = palette.GetNumColors();

	// pre-allocate the memory to prevent copies during inserts
	m_vColors.reserve(m_nColors);

	std::copy(palette.GetColors().begin(),
			palette.GetColors().end(),
			std::back_inserter(m_vColors));
}

SAPalette::~SAPalette()
{
}

void SAPalette::SetNumColors(int8_t nColors)
{
	// fill undefined palette space with black
	for(int i = m_nColors; i < nColors; i++)
	{
		if(m_vColors.size() == i)
		{
			m_vColors.push_back(wxColor(0, 0, 0));
		}

		// existing values will remain so resize undos work
	}

	m_nColors = nColors;
}

std::ostream& SAPalette::SaveObject(std::ostream &stream)
{
	stream << m_nColors << '\n';

	for(int i = 0; i < m_nColors; i++)
	{
		wxColor color = m_vColors[i];
		stream << (wxInt32) color.Red() << '\n';
		stream << (wxInt32) color.Green() << '\n';
		stream << (wxInt32) color.Blue() << '\n';
	}

	return stream;
}

std::istream& SAPalette::LoadObject(std::istream &stream)
{
	stream >> m_nColors;

	for(int8_t i = 0; i < m_nColors; i++)
	{
		wxInt32 r, g, b;

		stream >> r;
		stream >> g;
		stream >> b;

		GetColors()[i] = wxColor(r, g, b);
	}

	return stream;
}
