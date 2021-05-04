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
		inline int8_t GetNumColors() const { return m_nColors; }
		inline void SetNumColors(int8_t nColors) { m_nColors = nColors; }

		inline wxList& GetColors() { return m_colors; }

	private:
		int8_t m_nColors;
		wxList m_colors;
};

#endif // SA_PALETTE_H
