#pragma once

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

		inline std::vector<wxColor> GetColors() { return m_vColors; }

	private:
		int8_t m_nColors;
		std::vector<wxColor> m_vColors;
};
