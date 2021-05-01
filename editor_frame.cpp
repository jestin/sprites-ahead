#include "editor_frame.h"

#define ID_SLIDER 20001

	wxBEGIN_EVENT_TABLE(EditorFrame, wxMDIChildFrame)
	EVT_CLOSE(EditorFrame::OnCloseWindow)
	EVT_CANVAS_ZOOM_CHANGED(wxID_ANY, EditorFrame::OnZoomChanged)
wxEND_EVENT_TABLE()

EditorFrame::EditorFrame(wxMDIParentFrame *parent, wxString name)
	: wxMDIChildFrame(parent, wxID_ANY, name)
{
	m_Canvas = new Canvas(this);
	m_StatusBar = this->CreateStatusBar(2, wxSTB_DEFAULT_STYLE, wxID_ANY);
}

EditorFrame::~EditorFrame()
{
}

void EditorFrame::OnZoomChanged(wxCanvasEvent &event)
{
	std::cout << "zoom changed" << std::endl;
	m_StatusBar->SetStatusText(wxString("Zoom: ") << event.zoom, 1);
}

void EditorFrame::OnCloseWindow(wxCloseEvent &event)
{
}
