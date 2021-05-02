#include "SA_palette.h"

SAPalette::SAPalette(int colors)
{
	m_nColors = colors;
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

wxOutputStream& SAPalette::SaveObject(wxOutputStream &stream)
{
	// TODO

	return stream;
}

wxInputStream& SAPalette::LoadObject(wxInputStream &stream)
{
	// TODO

	return stream;
}
