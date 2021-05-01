#ifndef EDITOR_FRAME
#define EDITOR_FRAME

#include <wx/wx.h>
#include "canvas.h"

class EditorFrame : public wxMDIChildFrame
{
	public:
		EditorFrame(wxMDIParentFrame *parent, wxString name);
		~EditorFrame();

		void OnZoomChange(int change);

	private:
		Canvas *m_Canvas = NULL;
		wxStatusBar *m_StatusBar = NULL;

		void OnZoomChanged(wxCanvasEvent &event);

		void OnCloseWindow(wxCloseEvent &event);

		wxDECLARE_EVENT_TABLE();
};

#endif // EDITOR_FRAME
