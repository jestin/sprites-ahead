#pragma once

#include <wx/wx.h>
#include "canvas.h"

class SASpriteFrame : public wxMDIChildFrame
{
	public:
		SASpriteFrame(wxMDIParentFrame *parent, wxString name);
		~SASpriteFrame();

		void OnZoomChange(int change);

	private:
		Canvas *m_Canvas = NULL;
		wxStatusBar *m_StatusBar = NULL;

		void OnZoomChanged(wxCanvasEvent &event);

		void OnCloseWindow(wxCloseEvent &event);

		void OnSelectColor(wxCommandEvent& event);

		DECLARE_EVENT_TABLE();
};
