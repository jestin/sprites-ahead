#ifndef SA_SPRITE_H
#define SA_SPRITE_H

#include <wx/wx.h>

class SASprite : public wxObject
{
	public:
		SASprite(wxSize& size);
		SASprite(SASprite& palette);
		~SASprite();

		void Draw(wxDC* dc);

		wxOutputStream& SaveObject(wxOutputStream& stream);
		wxInputStream& LoadObject(wxInputStream& stream);

		// accessors
		inline int* GetPixels() { return m_aPixels; }
		inline wxSize& GetSize() { return m_Size; }

	private:
		wxSize m_Size;
		int* m_aPixels;
};

#endif // SA_SPRITE_H
