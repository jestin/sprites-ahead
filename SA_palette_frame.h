#ifndef SAPALETTEFRAME_H
#define SAPALETTEFRAME_H

#include <wx/wx.h>
#include "SA_palette_canvas.h"

class SAPaletteFrame : public wxMDIChildFrame
{
	public:
		SAPaletteFrame(wxMDIParentFrame *parent, wxString name);
		~SAPaletteFrame();

		// Accessors
		SAPaletteCanvas* GetCanvas() { return m_pCanvas; }


	private:
		void OnCloseWindow(wxCloseEvent &event);
		
		SAPaletteCanvas* m_pCanvas;

		DECLARE_EVENT_TABLE();
};

#endif // SAPALETTEFRAME_H

