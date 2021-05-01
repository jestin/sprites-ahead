#ifndef SA_DOCUMENT_H
#define SA_DOCUMENT_H

#include <wx/wx.h>
#include <wx/docview.h>

#include "SA_palette.h"

class SADocument : public wxDocument
{
	DECLARE_DYNAMIC_CLASS(SADocument)
	public:
		SADocument();
		~SADocument();

		wxOutputStream& SaveObject(wxOutputStream& stream);
		wxInputStream& LoadObject(wxInputStream& stream);

		// accessors
		inline wxList& GetPalettes() { return m_Palettes; };
		inline wxList& GetSprites() { return m_Sprites; };

	private:

		// objects managed by this document
		wxList m_Palettes;
		wxList m_Sprites;
};

#endif // SA_DOCUMENT_H
