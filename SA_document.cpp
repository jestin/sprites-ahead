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

std::ostream& SADocument::SaveObject(std::ostream &stream)
{
	wxDocument::SaveObject(stream);

	// save palettes
	wxInt32 numPalettes = m_Palettes.GetCount();
	stream << numPalettes << '\n';

	wxList::compatibility_iterator node = m_Palettes.GetFirst();
	while(node)
	{
		SAPalette* palette = (SAPalette *) node->GetData();
		palette->SaveObject(stream);
	}

	// save sprites
	wxInt32 numSprites = m_Sprites.GetCount();
	stream << numSprites << '\n';

	node = m_Sprites.GetFirst();
	while(node)
	{
		SASprite* sprite = (SASprite *) node->GetData();
		sprite->SaveObject(stream);
	}

	return stream;
}

std::istream& SADocument::LoadObject(std::istream &stream)
{
	wxDocument::LoadObject(stream);

	// load palettes
	wxInt32 numPalettes = 0;
	stream >> numPalettes;

	for(int i = 0; i < numPalettes; i++)
	{
		SAPalette* palette = new SAPalette();
		palette->LoadObject(stream);
		m_Palettes.Append(palette);
	}

	// load sprites
	wxInt32 numSprites = 0;
	stream >> numSprites;

	for(int i = 0; i < numPalettes; i++)
	{
		SAPalette* sprite = new SAPalette();
		sprite->LoadObject(stream);
		m_Palettes.Append(sprite);
	}

	return stream;
}
