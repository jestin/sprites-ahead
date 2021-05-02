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

		std::ostream& SaveObject(std::ostream& stream);
		std::istream& LoadObject(std::istream& stream);

		// accessors
		inline int GetNumColors() { return m_nColors; }
		inline wxList& GetColors() { return m_colors; }

	private:
		int m_nColors;
		wxList m_colors;
};

#endif // SA_PALETTE_H
