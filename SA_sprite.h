#ifndef SA_SPRITE_H
#define SA_SPRITE_H

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
		inline int* GetPixels() const { return m_aPixels; }
		inline wxSize& GetSize() { return m_Size; }

	private:
		wxSize m_Size;
		int* m_aPixels;
};

#endif // SA_SPRITE_H
