#ifndef SA_PALETTE_H
#define SA_PALETTE_H

#include <wx/wx.h>

class SAPalette : public wxObject
{
	public:
		SAPalette(int colors);
		SAPalette(SAPalette& palette);
		~SAPalette();

		void Draw(wxDC* dc);

		wxOutputStream& SaveObject(wxOutputStream& stream);
		wxInputStream& LoadObject(wxInputStream& stream);

		// accessors
		inline int GetNumColors() { return m_nColors; }
		inline wxList& GetColors() { return m_colors; }

	private:
		int m_nColors;
		wxList m_colors;
};

#endif // SA_PALETTE_H
