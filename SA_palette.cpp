#include "SA_palette.h"

SAPalette::SAPalette()
{
}

SAPalette::SAPalette(SAPalette& palette)
{
	m_nColors = palette.GetNumColors();
	
	m_aColors = (wxColor *) malloc(sizeof(wxColor) * m_nColors);

	for(int i = 0; i < m_nColors; i++)
	{
		wxColor color = palette.GetColors()[i];
		GetColors()[i] = wxColor(color);
	}
}

SAPalette::~SAPalette()
{
	free(m_aColors);
}

void SAPalette::SetNumColors(int8_t nColors)
{
	// resize the array if larger
	if(nColors > m_nColors)
	{
		wxColor* newArray = (wxColor *) malloc(sizeof(wxColor) * m_nColors);

		for(int i = 0; i < nColors; i++)
		{
			newArray[i] = (i < m_nColors) ? wxColor(m_aColors[i]) : wxColor();
		}

		free(m_aColors);
		m_aColors = newArray;
	}

	m_nColors = nColors;
}

std::ostream& SAPalette::SaveObject(std::ostream &stream)
{
	stream << m_nColors << '\n';

	for(int i = 0; i < m_nColors; i++)
	{
		wxColor color = m_aColors[i];
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
