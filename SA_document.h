#pragma once

#include <wx/wx.h>
#include <wx/docview.h>

#include "SA_palette.h"
#include "SA_sprite.h"

class SADocument : public wxDocument
{
	DECLARE_DYNAMIC_CLASS(SADocument)
	public:
		SADocument();
		~SADocument();

		std::ostream& SaveObject(std::ostream& stream);
		std::istream& LoadObject(std::istream& stream);

		// accessors
		inline wxList& GetPalettes() { return m_Palettes; };
		inline wxList& GetSprites() { return m_Sprites; };

		inline int8_t GetActivePalette() { return m_nActivePalette; }
		inline void SetActivePalette(int8_t nActivePalette)
		{
			m_nActivePalette = nActivePalette;
		}

	private:

		// objects managed by this document
		wxList m_Palettes;
		wxList m_Sprites;
		int8_t m_nActivePalette;
};
