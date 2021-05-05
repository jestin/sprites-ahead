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
		void SetNumColors(int8_t nColors);

		inline wxColor* GetColors() { return m_aColors; }

	private:
		int8_t m_nColors;
		wxColor* m_aColors;
		int8_t m_nBufSize;
};

#endif // SA_PALETTE_H
