#pragma once

#include <wx/wx.h>
#include "SA_palette_canvas.h"

class SAPaletteCanvas;

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
