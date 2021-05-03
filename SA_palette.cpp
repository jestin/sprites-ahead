#include "SA_palette.h"

SAPalette::SAPalette()
{
}

SAPalette::SAPalette(SAPalette& palette)
{
	wxList::compatibility_iterator node = palette.GetColors().GetFirst();

	m_nColors = palette.GetNumColors();

	while(node)
	{
		wxColor* color = (wxColor *) node->GetData();
		wxColor* newColor = new wxColor(*color);
		GetColors().Append(newColor);
	}
}

SAPalette::~SAPalette()
{
	WX_CLEAR_LIST(wxList, m_colors);
}

std::ostream& SAPalette::SaveObject(std::ostream &stream)
{
	stream << m_nColors << '\n';

	// assume that m_nColors is correct, otherwise there are bigger issues
	wxList::compatibility_iterator node = m_colors.GetFirst();

	while(node)
	{
		wxColor* color = (wxColor *) node->GetData();
		stream << color->Red() << '\n';
		stream << color->Green() << '\n';
		stream << color->Blue() << '\n';

		node = node->GetNext();
	}

	return stream;
}

std::istream& SAPalette::LoadObject(std::istream &stream)
{
	stream >> m_nColors;

	for(int i = 0; i < m_nColors; i++)
	{
		int r, g, b;

		stream >> r;
		stream >> g;
		stream >> b;

		m_colors.Append(new wxColor(r, g, b));
	}

	return stream;
}
