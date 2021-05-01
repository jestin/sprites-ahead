#include "SA_palette.h"

SAPalette::SAPalette()
{
}

SAPalette::SAPalette(SAPalette& palette)
{
	wxList::compatibility_iterator node = palette.GetColors().GetFirst();

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
