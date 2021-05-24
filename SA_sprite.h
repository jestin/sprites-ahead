#pragma once

#include <wx/wx.h>

class SASprite : public wxObject
{
	public:
		SASprite();
		SASprite(SASprite& palette);
		~SASprite();

		void Draw(wxDC* dc);

		std::ostream& SaveObject(std::ostream& stream);
		std::istream& LoadObject(std::istream& stream);

		// accessors
		inline std::vector<int8_t> GetPixels() const { return m_vPixels; }
		inline wxSize& GetSize() { return m_Size; }

	private:
		wxSize m_Size;
		std::vector<int8_t> m_vPixels;
};
