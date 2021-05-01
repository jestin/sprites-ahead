#include "SA_document.h"

IMPLEMENT_DYNAMIC_CLASS(SADocument, wxDocument)

SADocument::SADocument()
{
}

SADocument::~SADocument()
{
	WX_CLEAR_LIST(wxList, m_Palettes);
	WX_CLEAR_LIST(wxList, m_Sprites);
}

wxOutputStream& SADocument::SaveObject(wxOutputStream &stream)
{
	// TODO

	return stream;
}

wxInputStream& SADocument::LoadObject(wxInputStream &stream)
{
	// TODO

	return stream;
}
