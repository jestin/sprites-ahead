#ifndef SA_PALETTE_H
#define SA_PALETTE_H

#include <wx/wx.h>

class SAPalette : public wxObject
{
	public:
		SAPalette();
		SAPalette(SAPalette& palette);
		~SAPalette();

		void Draw(wxDC* dc);

		wxOutputStream& SaveObject(wxOutputStream& stream);
		wxInputStream& LoadObject(wxInputStream& stream);

		// accessors
		inline wxList& GetColors() { return m_colors; }

	private:
		wxList m_colors;
};

#endif // SA_PALETTE_H
