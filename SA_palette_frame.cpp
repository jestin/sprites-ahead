#include "SA_palette_frame.h"

BEGIN_EVENT_TABLE(SAPaletteFrame, wxMDIChildFrame)
	EVT_CLOSE(SAPaletteFrame::OnCloseWindow)
END_EVENT_TABLE()

SAPaletteFrame::SAPaletteFrame(wxMDIParentFrame *parent, wxString name)
	: wxMDIChildFrame(parent, wxID_ANY, name)
{
	m_pCanvas = new SAPaletteCanvas(this);
}

SAPaletteFrame::~SAPaletteFrame()
{
}

void SAPaletteFrame::OnCloseWindow(wxCloseEvent &event)
{
}
