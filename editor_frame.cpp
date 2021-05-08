#include "editor_frame.h"

BEGIN_EVENT_TABLE(EditorFrame, wxMDIChildFrame)
	EVT_CLOSE(EditorFrame::OnCloseWindow)
	EVT_CANVAS_ZOOM_CHANGED(wxID_ANY, EditorFrame::OnZoomChanged)
END_EVENT_TABLE()

EditorFrame::EditorFrame(wxMDIParentFrame *parent, wxString name)
	: wxMDIChildFrame(parent, wxID_ANY, name)
{
	m_Canvas = new Canvas(this);
	m_StatusBar = this->CreateStatusBar(2, wxSTB_DEFAULT_STYLE, wxID_ANY);

	// create palette
	wxToolBar *toolBar = CreateToolBar(wxTB_HORIZONTAL, wxID_ANY);
	wxColor palette[16];
	palette[0] =  wxColor(0, 0, 0);
	palette[1] =  wxColor(0, 0, 128);
	palette[2] =  wxColor(0, 128, 0);
	palette[3] =  wxColor(0, 128, 128);
	palette[4] =  wxColor(128, 0, 0);
	palette[5] =  wxColor(128, 0, 128);
	palette[6] =  wxColor(128, 128, 0);
	palette[7] =  wxColor(192, 192, 192);
	palette[8] =  wxColor(128, 128, 128);
	palette[9] =  wxColor(0, 0, 255);
	palette[10] =  wxColor(0, 255, 0);
	palette[11] =  wxColor(0, 255, 255);
	palette[12] =  wxColor(255, 0, 0);
	palette[13] =  wxColor(255, 0, 255);
	palette[14] =  wxColor(255, 255, 0);
	palette[15] =  wxColor(255, 255, 255);

	for(int i = 0; i < 16; i++)
	{
		wxButton *b = new wxButton(
				toolBar, 
				10100 + i, 
				"", 
				wxDefaultPosition, 
				wxSize(40,20), 
				0);
		b->SetBackgroundColour(palette[i]);
		b->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditorFrame::OnSelectColor), NULL);
		toolBar->AddControl(b);
	}

	wxButton *b = new wxButton(
			toolBar, 
			10100 + 16, 
			"ALPHA", 
			wxDefaultPosition, 
			wxSize(40,20), 
			0);
	b->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditorFrame::OnSelectColor), NULL);
	toolBar->AddControl(b);

	toolBar->Realize();
}

EditorFrame::~EditorFrame()
{
}

void EditorFrame::OnZoomChanged(wxCanvasEvent &event)
{
	m_StatusBar->SetStatusText(wxString("Zoom: ") << event.zoom, 1);
}

void EditorFrame::OnCloseWindow(wxCloseEvent &event)
{
}

void EditorFrame::OnSelectColor(wxCommandEvent &evvent)
{
}

