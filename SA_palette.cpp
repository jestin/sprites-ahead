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
	// TODO

	return stream;
}

std::istream& SAPalette::LoadObject(std::istream &stream)
{
	// TODO

	return stream;
}
